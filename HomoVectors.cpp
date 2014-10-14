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

#define Q 2147483647
#define W 7777
#define P 256

int main()
{
	Matrix x1(10,1),x2(10,1);
	x1.random(P);
	printf("Plain text 1:\n");
	x1.print();
	x2.random(P);
	printf("Plain text 2:\n");
	x2.print();
	Scheme S1(10,14,P,Q,W);
	S1.printkeys();
	Scheme S2(10,14,P,Q,W);
	S2.printkeys();
	Matrix c1=S1.Encrypt(x1),c2=S2.Encrypt(x2);
	printf("Cipher text 1:\n");
	c1.print();
	printf("Cipher text 2:\n");
	c2.print();
	Matrix x1x2=(x1+x2)%P;
	Matrix xform=getswitch(S1,S2);
	Matrix c12=transform(xform,c1,Q);
	Matrix nx1x2=S2.Decrypt(c12+c2);
	printf("Original sum\n");
	x1x2.print();
	printf("Decrypted sum\n");
	nx1x2.print();
	if(nx1x2==x1x2)
		printf("Sum is equal.\n");
	else
		printf("Sum is not equal!\n");
	return 0;
}
