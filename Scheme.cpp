/*
 * Scheme.cpp
 *
 *  Created on: 08-Oct-2014
 *      Author: swapniel
 */

#include "Scheme.h"

Scheme::Scheme(int p, int q, int w)
{
	this->p=p;
	this->q=q;
	this->w=w;
}

const Matrix Scheme::Decrypt(const Matrix &c)
{
//	Matrix Sc=S*c;
////	Sc.print();
//	Sc=(Sc%q)/w;
//	return Sc;
	return (((S*c)%q)/w);
}
