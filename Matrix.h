/*
 * Matrix.h
 *
 *  Created on: 02-Aug-2014
 *      Author: swapniel
 */

#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix
{
private:
	int n,m;
	int size;//
	int *p;
public:
	Matrix();
	Matrix(int n,int m);
	Matrix(const Matrix &m1);
	~Matrix();
	inline int& operator ()(int i,int j) const;
	void input();
	void set(int i, int j, int val);
	void print() const;
	const Matrix identity();
	const Matrix random(int max,int min=0);
	const Matrix vappend(const Matrix &m1) const;	//vertical append
	const Matrix happend(const Matrix &m1) const;	//horizontal append
	const Matrix getT() const;
	const Matrix expand(int l) const;
	const Matrix binexpand(int l) const;
	const Matrix operator |(const Matrix &m1) const;	//horizontal append
	const Matrix operator +(const Matrix &m1) const;
	const Matrix operator +=(const Matrix &m1) const;
	const Matrix operator -(const Matrix &m1) const;
	const Matrix operator -=(const Matrix &m1) const;
	const Matrix operator *(const Matrix &m1) const;
	const Matrix operator *(int a) const;
	const Matrix operator *=(int a) const;
	const Matrix operator =(const Matrix &mat);
	bool operator ==(const Matrix &mat) const;
	const Matrix operator ~() const;
	const Matrix operator %(const int q) const;
	const Matrix operator /(const int w) const; //Rounding division to closest number
};

#endif /* MATRIX_H_ */
