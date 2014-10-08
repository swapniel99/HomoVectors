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
	int p,q,w;
	Matrix S;
public:
	Scheme() {p=q=w=0;}
	Scheme(int p,int q,int w);
	void setkey(Matrix S) {this->S=S;}
	const Matrix Decrypt(const Matrix &c);
};

#endif /* SCHEME_H_ */
