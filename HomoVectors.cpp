//============================================================================
// Name        : HomoVectors.cpp
// Author      : Swapniel
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <climits>
#include "Scheme.h"

#define Q 32768
#define W 29
#define P 256

int main()
{
	Matrix x1(5,1),x2(5,1);
	x1.random(P);
	x1.print();
	x2.random(P);
	x2.print();
	Scheme S1(5,20,P,Q,W),S2(5,20,P,Q,W);
	S1.printkeys();
	S2.printkeys();
	Matrix c1=S1.Encrypt(x1),c2=S2.Encrypt(x2);
	c1.print();
	c2.print();
	Matrix x1x2=x1+x2;
	x1x2.print();
	Matrix xform=getswitch(S1,S2);
	Matrix c12=transform(xform,c1,Q);
	S2.Decrypt(c12+c2).print();
	return 0;
}
