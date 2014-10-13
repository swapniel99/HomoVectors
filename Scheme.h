/*
 * Scheme.h
 *
 *  Created on: 08-Oct-2014
 *      Author: swapniel
 */

#ifndef SCHEME_H_
#define SCHEME_H_

#include "Matrix.h"

class Scheme
{
private:
	int p,m,q,n,w;
	Matrix S,M;	//The pvt key, public key
public:
	Scheme() {p=m=q=n=w=0;}
	Scheme(int m, int n, int p, int q, int w);
	void setkey(const Matrix &S);
	void printkeys() const;
	const Matrix Encrypt(const Matrix &x);
	const Matrix Decrypt(const Matrix &c);
	friend const Matrix getswitch(const Scheme &S1,const Scheme &S2);
};

const Matrix transform(const Matrix &M, const Matrix &c, int q);

#endif /* SCHEME_H_ */
