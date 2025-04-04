/*
Let r be the remainder when (a−1)^n + (a+1)^n is divided by a^2.

For example, if a = 7 and n = 3, then r = 42: 63 + 83 = 728 ≡ 42 mod 49. And as n varies, so too will r, but for a = 7 it turns out that rmax = 42.

For 3 ≤ a ≤ 1000, find ∑rmax.

***Notes***
(a-1)^n + (a+1)^n
n=2
a^2-2a+1 + a^2+2a+1 == 2a^2+2
n=3
a^3-3a^2+3a-1 + a^3+3a^2+3a+1 == 2a^3+6a
n=4
a^4-4a^3+6a^2-4a+1 + a^4+4a^3+6a^2+4a+1 == 2a^4+12a^2+2
since we're modding by a^2, all of the terms >= a^2 don't matter
which means for even n : r = 2, for odd n : r = 2an which means
that we must find n s.t. 2an < a*a
*/

#include <stdio.h>

int main() {
	int result = 0;
  for ( int i = 3; i <= 1000; ++i ) {
  	int best = 0, mod = i*i, num = 2*i, n = num;
  	for ( int j = 1; j < n; j += 2 ) {
  		int f = num % mod;
  		if ( f > best ) best = f;
  		num += n;
  	}
  	result += best;
  }
  printf("Result: %d\n", result);
  return 0;
}