//============================================================================
// Name        : HomoVectors.cpp
// Author      : Swapniel
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include "Scheme.h"
#include "params.h"

void encdec()
{
	Scheme S(M,N,P,Q,W);
	S.printkeys();
	Matrix x(M,1);
//	x.random(P);
	x.set(0,0,1);
	printf("Plain text:\n");
	x.print();
	Matrix c=S.Encrypt(x);
	printf("Cipher text:\n");
	c.print();
	Matrix x1=S.Decrypt(c);
	x1.print();
	if(x==x1)
		printf("equal.\n");
	else
		printf("not equal!\n");
}

void countadditions()
{
	Matrix Acc(M,1), CAcc(N,1), x(M,1), c, DCAcc;
	Scheme S(M,N,P,Q,W);
//	S.printkeys();

	bool correct=true;
	long long int count = 1;

	while(correct)
	{
		x.random(P);
//		x.set(2,0,255);
//		printf("Plain text %d:\n",count);
//		x.print();
		c=S.Encrypt(x);
//		printf("Cipher text %d:\n",count);
//		c.print();
//		Acc+=x;
//		Acc=Acc;
		Acc=(Acc+x)%P;
		CAcc=(CAcc+c)%Q;
//		if(count%50000==0)
//			CAcc=S.Recrypt(CAcc);
		DCAcc=S.Decrypt(CAcc);
//		printf("Original sum %d:\n",count);
//		Acc.print();
//		printf("Sum from cipher %d:\n",count);
//		DCAcc.print();
		if(!(correct = (Acc==DCAcc)))
			printf("\nSum is not equal %lld:\n",count);
//		else
//			printf("Sum is equal %lld:\n",count);
		count++;
	}
}

int addition()
{
	Matrix x1(M,1),x2(M,1);
	x1.random(P);
	printf("Plain text 1:\n");
	x1.print();
	x2.random(P);
	printf("Plain text 2:\n");
	x2.print();
	Scheme S1(M,N,P,Q,W);
	S1.printkeys();
	Scheme S2(M,N,P,Q,W);
	S2.printkeys();
	Matrix c1=S1.Encrypt(x1),c2=S2.Encrypt(x2);
	printf("Cipher text 1:\n");
	c1.print();
	printf("Cipher text 2:\n");
	c2.print();
	Matrix x1x2=(x1+x2)%P;
	Matrix c12=transform(c1,S1,S2);
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

int main()
{
	encdec();
	return 0;
}
