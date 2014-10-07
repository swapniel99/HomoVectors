//============================================================================
// Name        : Matrices.cpp
// Author      : Swapniel
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Matrix.h"
using namespace std;

Matrix::Matrix(int n,int m)
{
	this->n=n;
	this->m=m;
	size=n*m;//
//	p = new int*[n];
	p = new int[size]();
	
//	for(int i=0;i<n;i++)
//	{
//		p[i]=new int[m];
//		for(int j=0;j<m;j++)
//			p[i][j]=0;
//	}
}

Matrix::~Matrix()
{
//	for(int i=0;i<n;i++)
//	{
//		delete [] p[i];
//	}
	delete [] p;
	printf("Destructor called.\n");
}

Matrix::Matrix(const Matrix &m1)
{
	n=m1.n;
	m=m1.m;
	size=m1.size;//
//	p = new int*[n];
	p = new int[size];
	
//	for(int i=0;i<n;i++)
//	{
//		p[i]=new int[m];
//		for(int j=0;j<m;j++)
//			p[i][j]=m1.p[i][j];
//	}
	for(int i=0;i<size;i++)
		p[i]=m1.p[i];
	
	printf("Copy Constructor called.\n");
}

void Matrix::input()
{
	printf("Provide a %d x %d matrix:\n",n,m);
//	for(int i=0;i<n;i++)
//		for(int j=0;j<m;j++)
//			scanf("%d",&p[i][j]);
	for(int i=0;i<size;i++)
		scanf("%d",p+i);
}

void Matrix::print()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
//			printf("%d\t",p[i][j]);
			printf("%d\t",p[i*m+j]);
		printf("\n");
	}
}

const Matrix Matrix::operator +(const Matrix &mat) const
{
	Matrix res(n,m);
//	for(int i=0;i<n;i++)
//		for(int j=0;j<m;j++)
//			res.p[i][j] = this->p[i][j]+mat.p[i][j];
	for(int i=0;i<size;i++)
		res.p[i] = this->p[i]+mat.p[i];
	return res;
}

const Matrix Matrix::operator *(const Matrix &mat) const
{
	Matrix res(n,mat.m);
	int sum;
//	for(int j=0;j<n;j++)
//		for(int k=0;k<mat.m;k++)
//		{
//			sum=0;
//			for(int i=0;i<m;i++)
//				sum+=p[j][i]*mat.p[i][k];
//			res.p[j][k]=sum;
//		}
	for(int j=0;j<n;j++)
		for(int k=0;k<mat.m;k++)
		{
			sum=0;
			for(int i=0;i<m;i++)
				sum+=p[j*m+i]*mat.p[i*mat.m+k];
			res.p[j*mat.m+k]=sum;
		}
	return res;
}

const Matrix Matrix::operator =(const Matrix &mat)
{	
	printf("Assignment called.\n");
//	for(int i=0;i<n;i++)
//		delete [] p[i];
	delete [] p;
	
	n=mat.n;
	m=mat.m;
	size=mat.size;//
//	p = new int*[n];
//	for(int i=0;i<n;i++)
//	{
//		p[i]=new int[m];
//		for(int j=0;j<m;j++)
//			p[i][j]=mat.p[i][j];
//	}
	p = new int[size];
	for(int i=0;i<size;i++)
		p[i]=mat.p[i];

	return *this;
}

const Matrix Matrix::operator ~() const
{
	Matrix res(m,n);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
//			res.p[j][i]=p[i][j];
			res.p[j*n+i]=p[i*m+j];
	
	return res;
}

