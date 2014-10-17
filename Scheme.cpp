/*
 * Scheme.cpp
 *
 *  Created on: 08-Oct-2014
 *      Author: swapniel
 */

#include "Scheme.h"
#include <cstdio>
#include <cmath>

Scheme::Scheme() {p=q=w=m=n=0;}

Scheme::Scheme(int m, int n, big p, big q, big w)// : S(m,n)
{
	this->p=p;
	this->m=m;
	this->q=q;
	this->n=n;
	this->w=w;
	
	Matrix I(m,m);
	I.identity();
	Matrix T(m,n-m);
	T.random(q);
	S=I|T;
	M=makeswitch(I,S,m,m,n,q);
}

void Scheme::setkey(const Matrix &S)
{
	this->S=S;
	
	Matrix I(m,m);
	I.identity();
	M=makeswitch(I,S,m,m,n,q);
}

void Scheme::printkeys() const
{
	printf("Private key S:\n");
	S.print();
	printf("Public key M:\n");
	M.print();
}

const Matrix Scheme::Encrypt(const Matrix &x) const {return transform(M,x*w,q);}

const Matrix Scheme::Decrypt(const Matrix &c) const //{return (((S*c)%q)/w);}
{return ((((S*c)%q)/w)%p);}
//Why there is no need of %p ?

const Matrix Scheme::Recrypt(const Matrix &c) const {return Encrypt(Decrypt(c));}

const Matrix getswitch(const Scheme &S1, const Scheme &S2)
{
	 if(S1.p==S2.p && S1.m==S2.m && S1.q==S2.q && S1.w==S2.w)
		 return makeswitch(S1.S,S2.S,S1.m,S1.n,S2.n,S1.q);
	 else
	 {
		 printf("Cannot switch key as parameters don't match.\n");
		 Matrix null;
		 return null;
	 }
}

const Matrix transform(const Matrix &c, const Scheme &S1, const Scheme &S2) {return transform(getswitch(S1,S2),c,S1.q);}
//Parameters have to be same

const Matrix transform(const Matrix &M, const Matrix &c, big q) {return ((M*(c.binexpand((int)ceil(log2(q)))))%q);}

const Matrix makeswitch(const Matrix &S1,const Matrix &S2,int m, int n1, int n2, big q)
{
	 int l=(int)ceil(log2(q));
	 int n1l=n1*l;
	 Matrix A(n2-m,n1l);
	 A.random(q);		// Why modular product didn't work?
	 Matrix E(m,n1l);
	 E.random(5);
//	 printf("Error added:\n");
//	 E.print();
	 return (((E+S1.expand(l)-(S2.getT()*A)).vappend(A))%q);
}		/*	   E+	 S*				-TA							*/


