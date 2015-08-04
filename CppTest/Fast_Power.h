//
//  Fast_Power.h
//  CppTest
//
//  Created by meng zhang on 28/03/2015.
//  Copyright (c) 2015 meng zhang. All rights reserved.
//
/*
 Calculate the an % b where a, b and n are all 32bit integers.
 
 Example
 For 231 % 3 = 2
 
 For 1001000 % 1000 = 0
 
 Challenge
 O(logn)
 
 */

#ifndef CppTest_Fast_Power_h
#define CppTest_Fast_Power_h

#include "global.h"

class Fast_Power
{
public:
	/*
	 * @param a, b, n: 32bit integers
	 * @return: An integer
	 */
	int fastPower(int a, int b, int n) {
		// write your code here
		if (a == 0 && n == 0)	// undefined
			return -1;
		if (b == 0)		// undefined
			return -1;
		
		if (a == 0)
			return 0;
		if (n == 0 || a == 1)
			return b == 1 ? 0 : 1;
		if (n == 1)
			return a % b;
		
		if (a > b)
			return fastPower(a % b, b, n);
		else if (a == b)
			return 0;
		else {
			unsigned int fac = 1;
			unsigned int new_a = 1;
			unsigned int k = 1;
			for (; k <= n; k ++) {
				new_a *= a;
				if (new_a >= b)
					break;
			}
			if (k > n)
				return new_a % b;
			unsigned int r = n % k;
			for (unsigned int i = 0; i < r; i ++)
				fac *= a;
			return (fac * fastPower(new_a % b, b, n / k)) % b;
		}
	}
};

void test_fastPower()
{
	Fast_Power f;
	int a = 109, b = 10000007, n = 1000001;
	printf("a:%d, n:%d, b:%d, remainder:%d\n",
		   a, n, b, f.fastPower(a, b, n));
}
#endif
