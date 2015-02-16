/*
 * Matrix.h
 *
 *  Created on: 02-Aug-2014
 *      Author: swapniel
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <cstdio>
#include <gmpxx.h>

using namespace std;

typedef mpz_class big;

// Assumption: Size of the matrices are well into int. And values have int number of bits.

class Matrix
{
private:
	int n,m;
	int size;//
	big *p;
public:
	Matrix();
	Matrix(int n,int m);
	Matrix(const Matrix &m1);
	~Matrix();
	inline big& operator ()(int i,int j) const;
	void input();
	void set(int i, int j,const big &val);
	void print() const;
	const Matrix identity();
	const Matrix random(const big &max,const big &min=0);
	const Matrix vappend(const Matrix &m1) const;	//vertical append
	const Matrix happend(const Matrix &m1) const;	//horizontal append
	const Matrix getT() const;
	const Matrix expand(int l) const;
	const Matrix binexpand(int l) const;
	const Matrix operator |(const Matrix &m1) const;	//horizontal append
	const Matrix operator +(const Matrix &m1) const;
	const Matrix operator +=(const Matrix &m1);
	const Matrix operator -(const Matrix &m1) const;
	const Matrix operator -=(const Matrix &m1);
	const Matrix operator *(const Matrix &m1) const;
	const Matrix operator *(const big &a) const;
	const Matrix operator *=(const big &a);
	const Matrix operator =(const Matrix &mat);
	const Matrix operator ~() const;			//Transpose
	const Matrix operator %(const big &q) const;	//Modulo
	const Matrix operator %=(const big &q);
	const Matrix operator /(const big &w) const; //Flooring division
	bool operator ==(const Matrix &mat) const;
};

#endif /* MATRIX_H_ */
