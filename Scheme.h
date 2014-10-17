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
	int m,n;
	big p,q,w;

	Matrix S,M;	//The pvt key, public key
public:
	Scheme() {p=m=q=n=w=0;}
	Scheme(int m, int n, big p, big q, big w);
	void setkey(const Matrix &S);
	void printkeys() const;
	const Matrix Encrypt(const Matrix &x) const;
	const Matrix Decrypt(const Matrix &c) const;
	const Matrix Recrypt(const Matrix &c) const;
	friend const Matrix getswitch(const Scheme &S1,const Scheme &S2);
	friend const Matrix transform(const Matrix &c, const Scheme &S1, const Scheme &S2);
};

const Matrix transform(const Matrix &M, const Matrix &c, big q);

#endif /* SCHEME_H_ */
