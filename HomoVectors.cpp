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

//int main()
//{
//	Scheme S(M,N,P,Q,W);
//	S.printkeys();
//	Matrix x(M,1);
//	x.random(P);
//	x.set(0,0,0);
////	x.set(1,0,241);
//	printf("Plain text:\n");
//	x.print();
//	Matrix c=S.Encrypt(x);
//	printf("Cipher text:\n");
//	c.print();
//	Matrix x1=S.Decrypt(c);
//	x1.print();
//	if(x==x1)
//		printf("equal.\n");
//	else
//		printf("not equal!\n");
//	return 0;
//}

int main()
{
	Matrix Acc(M,1), CAcc(N,1), x(M,1), c, DCAcc;
	Scheme S(M,N,P,Q,W);
	S.printkeys();

	bool correct=true;
	int count = 1;

	while(correct)
	{
		x.random(P);
//		printf("Plain text %d:\n",count);
//		x.print();
		c=S.Encrypt(x);
//		printf("Cipher text %d:\n",count);
//		c.print();
		Acc=(Acc+x)%P;
		CAcc=(CAcc+c)%Q;
//		if(count%50==0)
//			CAcc=S.Recrypt(CAcc);
		printf("Original sum %d:\n",count);
		Acc.print();
		printf("Sum from cipher %d:\n",count);
		DCAcc=S.Decrypt(CAcc);
		DCAcc.print();
		if(correct = (Acc==DCAcc))
			printf("Sum is equal %d:\n",count);
		else
			printf("Sum is not equal %d:\n",count);
		count++;
	}
	return 0;
}

//int main()
//{
//	Matrix x1(M,1),x2(M,1);
//	x1.random(P);
//	printf("Plain text 1:\n");
//	x1.print();
//	x2.random(P);
//	printf("Plain text 2:\n");
//	x2.print();
//	Scheme S1(M,N,P,Q,W);
//	S1.printkeys();
//	Scheme S2(M,N,P,Q,W);
//	S2.printkeys();
//	Matrix c1=S1.Encrypt(x1),c2=S2.Encrypt(x2);
//	printf("Cipher text 1:\n");
//	c1.print();
//	printf("Cipher text 2:\n");
//	c2.print();
//	Matrix x1x2=(x1+x2)%P;
//	Matrix c12=transform(c1,S1,S2);
//	Matrix nx1x2=S2.Decrypt(c12+c2);
//	printf("Original sum\n");
//	x1x2.print();
//	printf("Decrypted sum\n");
//	nx1x2.print();
//	if(nx1x2==x1x2)
//		printf("Sum is equal.\n");
//	else
//		printf("Sum is not equal!\n");
//	return 0;
//}
