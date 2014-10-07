/*
 * Matrix.h
 *
 *  Created on: 02-Aug-2014
 *      Author: swapniel
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <cstdio>

class Matrix
{
private:
	int n,m,size;
//	int **p;
	int *p;
public:
	Matrix() {n=m=size=0; p=NULL;}
	Matrix(int n,int m);
	Matrix(const Matrix &m1);
	~Matrix();
	void input();
	void print();
	const Matrix operator +(const Matrix &m1) const;
	const Matrix operator *(const Matrix &m1) const;
	const Matrix operator =(const Matrix &mat);
	const Matrix operator ~() const;
//	const int operator ()(int i,int j) const {return p[i][j];}
	const int operator ()(int i,int j) const {return p[i*m+j];}
};

#endif /* MATRIX_H_ */
