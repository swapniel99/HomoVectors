/*
 * params.h
 *
 *  Created on: 15-Oct-2014
 *      Author: swapniel
 */

#ifndef PARAMS_H_
#define PARAMS_H_

#include <climits>

// Below parameters allow roughly 0.7 million additions in 4 mins.
#define M 8
#define N 10
//#define Q 2147483648
#define W 8388608    //4194304
#define P 256


#ifndef Q
#define Q INT_MAX // = 2^31 - 1 = 2147483647
#endif

#endif /* PARAMS_H_ */
