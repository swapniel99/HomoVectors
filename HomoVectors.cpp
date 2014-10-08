//============================================================================
// Name        : HomoVectors.cpp
// Author      : Swapniel
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include "Scheme.h"

int main()
{
	Scheme e(4,32,7);
	Matrix S(2,2);
	S.input();
	e.setkey(S);
	Matrix c(2,1);
	c.input();
	Matrix x=e.Decrypt(c);
	x.print();
	return 0;
}
