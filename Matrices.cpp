//============================================================================
// Name        : Matrices.cpp
// Author      : Swapniel
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <gmp.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "Matrix.h"

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
	p=new big[size]();
//	printf("arg constructor called.");
}

Matrix::Matrix(const Matrix &m1)
{
	n=m1.n;
	m=m1.m;
	size=m1.size;//
	p = new big[size];
	
	for(int i=0;i<size;i++)
		p[i]=m1.p[i];
	
//	printf("Copy Constructor called.\n");
}

Matrix::~Matrix()
{
	delete [] p;
//	printf("Destructor called.\n");
}

inline big& Matrix::operator ()(int i,int j) const
{
	return p[i*m+j];
}
//This can be used anywhere, where element is accessed using coordinates. 
//See a few functions below

void Matrix::input()
{
	printf("Provide a %d x %d matrix:\n",n,m);
	for(int i=0;i<size;i++)
		cin>>p[i];
}

void Matrix::set(int i, int j, const big &val)
{
	(*this)(i,j)=val;
}

void Matrix::print() const
{
	printf("%d x %d\n[\n",n,m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<"\t"<<(*this)(i,j);
//			printf("\t%lld",(*this)(i,j));
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
					(*this)(i,j)=1;
//					p[i*m+j]=1;
				else
					(*this)(i,j)=0;
//					p[i*m+j]=0;
			}
	
	return *this;
}

const Matrix Matrix::random(const big &max,const big &min)
{
	static bool seed=true;
	if(seed)
	{
		srand(time(NULL));
		seed=false;
	}
	for(int i=0;i<size;i++)
		p[i]=(rand()%max)+min;
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
				res(i,j)=(*this)(i,j);
//				res.p[i*res.m+j]=p[i*m+j];
			for(int j=0;j<m1.m;j++)
				res(i,j+m)=m1(i,j);
//				res.p[i*res.m+m+j]=m1.p[i*m1.m+j];
		}
		return res;
	}
}

const Matrix Matrix::getT() const
{
	Matrix T(n,m-n);
	for(int i=0;i<n;i++)
		for(int j=n;j<m;j++)
			T(i,j-n)=(*this)(i,j);
//			T.p[i*T.m+j-n]=p[i*m+j];
	return T;
}

const Matrix Matrix::expand(int l) const
{
	Matrix res(n,m*l);
//	static big pow2[] = {1, 2, 4, 8, 16, 32,
//			64, 128, 256, 512, 1024, 2048, 4096,
//			8192, 16384, 32768, 65536, 131072,
//			262144, 524288, 1048576, 2097152,
//			4194304, 8388608, 16777216, 33554432,
//			67108864, 134217728, 268435456,
//			536870912, 1073741824, 2147483648,
//			4294967296};
//	pow2[0]=1;
//	for(int i=1;i<l;i++)
//		pow2[i]=pow2[i-1]<<1;
	big pow2;
	for(int i=0;i<size;i++)
	{	
		pow2=1;
		for(int j=0;j<l;j++)
		{
			res.p[l*i+j]=p[i]*pow2;
			pow2<<=1;
		}
	}
	
//	res.print();
	return res;
}

const Matrix Matrix::binexpand(int l) const
{
	Matrix res(n*l,m);
	big temp;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
//			temp=p[i*m+j];
			temp=(*this)(i,j);
			for(int k=0;k<l;k++)
			{
//				res.p[(i*l+k)*res.m+j]=temp%2;
				res(i*l+k,j)=temp%2;
				temp/=2;
			}
		}
//	res.print();
	return res;
}

const Matrix Matrix::operator |(const Matrix &m1) const
{
//	return ((*this).happend(m1));
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
//				res.p[i*res.m+j]=p[i*m+j];
				res(i,j)=(*this)(i,j);
			for(int j=0;j<m1.m;j++)
//				res.p[i*res.m+m+j]=m1.p[i*m1.m+j];
				res(i,m+j)=m1(i,j);
		}
		return res;
	}
}

const Matrix Matrix::operator +(const Matrix &mat) const
{
	Matrix res(n,m);
	for(int i=0;i<size;i++)
		res.p[i] = p[i]+mat.p[i];
	return res;
}

const Matrix Matrix::operator +=(const Matrix &mat)
{
	for(int i=0;i<size;i++)
		p[i] += mat.p[i];
	return (*this);
}

const Matrix Matrix::operator -(const Matrix &m1) const
{
	Matrix res(n,m);
	for(int i=0;i<size;i++)
		res.p[i] = p[i]-m1.p[i];
	return res;
}

const Matrix Matrix::operator -=(const Matrix &m1)
{
	for(int i=0;i<size;i++)
		p[i] -= m1.p[i];
	return (*this);
}

const Matrix Matrix::operator *(const Matrix &mat) const
{
	Matrix res(n,mat.m);
	big sum;
	for(int j=0;j<n;j++)
		for(int k=0;k<mat.m;k++)
		{
			sum=0;
			for(int i=0;i<m;i++)
//				sum+=p[j*m+i] * mat.p[i*mat.m+k];
				sum+=(*this)(j,i)*mat(i,k);
//			res.p[j*res.m+k]=sum;
			res(j,k)=sum;
		}
	return res;
}

const Matrix Matrix::operator *(const big &a) const
{
	Matrix res(n,m);
	for(int i=0;i<size;i++)
		res.p[i]=a*p[i];
	return res;
}

const Matrix Matrix::operator *=(const big &a)
{
	for(int i=0;i<size;i++)
		p[i]*=a;
	return (*this);
}

const Matrix Matrix::operator =(const Matrix &mat)
{	
//	printf("Assignment called.\n");
	delete [] p;
	
	n=mat.n;
	m=mat.m;
	size=mat.size;//
	p = new big[size];
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
//			res.p[j*n+i]=p[i*m+j];
			res(j,i)=(*this)(i,j);
	
	return res;
}

const Matrix Matrix::operator %(const big &q) const
{
	Matrix res(n,m);
	for(int i=0;i<size;i++)
	{
		if(p[i]<0)
			res.p[i]=q-((-p[i])%q);
		else
			res.p[i]=p[i]%q;
	}
	return res;
}

const Matrix Matrix::operator %=(const big &q)
{
	for(int i=0;i<size;i++)
	{
		if(p[i]<0)
			p[i]=q-((-p[i])%q);
		else
			p[i]=p[i]%q;
	}
	return (*this);
}

const Matrix Matrix::operator /(const big &w) const	//Flooring division to closest integer
{
	Matrix res(n,m);
	mpf_class temp;
	for(int i=0;i<size;i++)
	{
		temp=p[i];
		temp/=w;
//		res.p[i]=(big)round(temp);
		res.p[i]=(big)floor(temp);
		if(temp-res.p[i]>0.5)
			res.p[i]+=1;
//		else if(temp-res.p[i]==0.5)
//			printf("Divide by w gave x.5\n");
	}
	return res;
}

bool Matrix::operator ==(const Matrix &mat) const
{
	for(int i=0;i<size;i++)
		if(p[i]!=mat.p[i])
			return false;
	return true;
}
