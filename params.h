/*
 * params.h
 *
 *  Created on: 15-Oct-2014
 *      Author: swapniel
 */

#ifndef PARAMS_H_
#define PARAMS_H_

#include <climits>

//#define M 10
//#define N 14
//#define Q 46340
//#define W 128
//#define P 256

#define M 10
#define N 14
#define Q INT_MAX
#define W 7759
#define P 257

//#define M 10
//#define N 14
//#define Q 2049
//#define W 64
//#define P 32

#ifndef Q
#define Q INT_MAX // = 2^31 - 1 = 2147483647
#endif

#endif /* PARAMS_H_ */
