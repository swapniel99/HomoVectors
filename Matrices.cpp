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
	p = new int*[n];
	for(int i=0;i<n;i++)
	{
		p[i]=new int[m];
		for(int j=0;j<m;j++)
			p[i][j]=0;
	}
}

Matrix::~Matrix()
{
	for(int i=0;i<n;i++)
	{
		delete [] p[i];
	}
	delete [] p;
	printf("Destructor called.\n");
}

Matrix::Matrix(const Matrix &m1)
{
	n=m1.n;
	m=m1.m;
	p = new int*[n];
	for(int i=0;i<n;i++)
	{
		p[i]=new int[m];
		for(int j=0;j<m;j++)
			p[i][j]=m1.p[i][j];
	}
	printf("Copy Constructor called.\n");
}

void Matrix::input()
{
	printf("Provide %d x %d matrix:\n",n,m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&p[i][j]);
}

void Matrix::print()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%d\t",p[i][j]);
		printf("\n");
	}
}

const Matrix Matrix::operator +(const Matrix &mat) const
{
	Matrix res(n,m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			res.p[i][j] = this->p[i][j]+mat.p[i][j];
	return res;
}

const Matrix Matrix::operator *(const Matrix &mat) const
{
	Matrix res(n,mat.m);
	int sum;
	for(int j=0;j<n;j++)
		for(int k=0;k<mat.m;k++)
		{
			sum=0;
			for(int i=0;i<m;i++)
				sum+=p[j][i]*mat.p[i][k];
			res.p[j][k]=sum;
		}
	return res;
}

const Matrix Matrix::operator =(const Matrix &mat)
{	
	printf("Assignment called.\n");
	for(int i=0;i<n;i++)
		delete [] p[i];
	delete [] p;
	
	n=mat.n;
	m=mat.m;
	p = new int*[n];
	for(int i=0;i<n;i++)
	{
		p[i]=new int[m];
		for(int j=0;j<m;j++)
			p[i][j]=mat.p[i][j];
	}
	return *this;
}

const Matrix Matrix::operator ~() const
{
	Matrix res(m,n);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			res.p[j][i]=p[i][j];
	return res;
}

