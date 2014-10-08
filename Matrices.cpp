//============================================================================
// Name        : Matrices.cpp
// Author      : Swapniel
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "Matrix.h"
//using namespace std;

Matrix::Matrix()
{
//	printf("def constructor called.");
	n=m=size=0;
	p=NULL;
}

Matrix::Matrix(int n,int m)
{
	this->n=n;
	this->m=m;
	size=n*m;//
//	p=new int*[n];
	p=new int[size]();
//	printf("arg constructor called.");
//	for(int i=0;i<n;i++)
//	{
//		p[i]=new int[m];
//		for(int j=0;j<m;j++)
//			p[i][j]=0;
//	}
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
	
//	printf("Copy Constructor called.\n");
}

Matrix::~Matrix()
{
//	for(int i=0;i<n;i++)
//	{
//		delete [] p[i];
//	}
	delete [] p;
//	printf("Destructor called.\n");
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

void Matrix::print() const
{
	printf("[\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
//			printf("%d\t",p[i][j]);
			printf("\t%d",p[i*m+j]);
		printf("\n");
	}
	printf("]\n");
}

const Matrix Matrix::identity()
{
	if(m!=n)
		printf("Can't create identity matrix of %d x %d\n",n,m);
	else
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(i==j)
					p[i*m+j]=1;
				else
					p[i*m+j]=0;
			}
	
	return *this;
}

const Matrix Matrix::random(int q)
{
	srand(time(NULL));
	for(int i=0;i<size;i++)
		p[i]=rand()%q;
	return *this;
}

const Matrix Matrix::vappend(const Matrix &m1) const
{
	if(m!=m1.m)
	{
		printf("Cant append vertically as no. of columns %d and %d don't match\n",m,m1.m);
		return *this;
	}
	else
	{
		Matrix res(n+m1.n,m);
		for(int i=0;i<size;i++)
			res.p[i]=p[i];
		for(int i=0;i<m1.size;i++)
			res.p[i+size]=m1.p[i];
		return res;
	}
}

const Matrix Matrix::happend(const Matrix &m1) const
{
	if(n!=m1.n)
	{
		printf("Cant append horizontally as no. of rows %d and %d don't match\n",n,m1.n);
		return *this;
	}
	else
	{
		Matrix res(n,m+m1.m);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				res.p[i*res.m+j]=p[i*m+j];
			for(int j=0;j<m1.m;j++)
				res.p[i*res.m+m+j]=m1.p[i*m1.m+j];
		}
		return res;
	}
}

const Matrix Matrix::operator |(const Matrix &m1) const
{
	return ((*this).happend(m1));
}

const Matrix Matrix::operator +(const Matrix &mat) const
{
	Matrix res(n,m);
//	for(int i=0;i<n;i++)
//		for(int j=0;j<m;j++)
//			res.p[i][j] = this->p[i][j]+mat.p[i][j];
	for(int i=0;i<size;i++)
		res.p[i] = p[i]+mat.p[i];
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
//	printf("Assignment called.\n");
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

const Matrix Matrix::operator %(const int q) const
{
	Matrix res(n,m);
	for(int i=0;i<size;i++)
		res.p[i]=p[i]%q;
	return res;
}

const Matrix Matrix::operator /(const int w) const	//Rounding division to closest integer
{
	Matrix res(n,m);
	double temp;
	for(int i=0;i<size;i++)
	{
		temp=p[i];
		temp/=w;
		res.p[i]=(int)round(temp);
	}
	return res;
}

const int Matrix::operator ()(int i,int j) const {return p[i*m+j];}
