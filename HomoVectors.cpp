//============================================================================
// Name        : HomoVectors.cpp
// Author      : Swapniel
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Matrix.h"

int main()
{
	Matrix m(2,2);
	printf("a\n");
	m.input();
	printf("a\n");
	Matrix q;
	printf("a\n");
	q=m;
	printf("a\n");
	Matrix r=(q*m);
	printf("a\n");
	r.print();
	printf("%d\n",r(1,1));
	return 0;
}
