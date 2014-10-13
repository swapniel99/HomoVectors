/*
 * Scheme.cpp
 *
 *  Created on: 08-Oct-2014
 *      Author: swapniel
 */

#include "Scheme.h"
#include <cstdio>
#include <cmath>

const Matrix makeswitch(const Matrix &S1,const Matrix &S2,int m, int n1, int n2, int q)
{
	 int l=(int)ceil(log2(q));
	 int nl=n1*l;
	 Matrix A(n2-m,nl);
	 A.random(q);
	 Matrix T = S2.getT();
	 Matrix Sxp = S1.expand(l);
	 Matrix E(m,nl);
	 E.random(3,-1);	//Some limit yet to be defined
	 return (((E+Sxp-(T*A)).vappend(A))%q);
}

Scheme::Scheme(int m, int n, int p, int q, int w)// : S(m,n)
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
	printf("S:\n");
	S.print();
	printf("M:\n");
	M.print();
}

const Matrix transform(const Matrix &M, const Matrix &c, int q)
{
	return ((M*(c.binexpand((int)ceil(log2(q)))))%q);
}

const Matrix Scheme::Encrypt(const Matrix &x) {return ((M*((x*w).binexpand((int)ceil(log2(q)))))%q);}

const Matrix Scheme::Decrypt(const Matrix &c) {return (((S*c)%q)/w);}

const Matrix getswitch(const Scheme &S1,const Scheme &S2)
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
