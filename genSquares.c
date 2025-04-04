#include <stdio.h>

int print_uint128(__uint128_t n) {
  if (n == 0)  return printf("0\n");

  char str[40] = {0}; 
  char *s = str + sizeof(str) - 1;
  while ( n ) {
    *--s = "0123456789"[n % 10];
    n /= 10;                     
  }
  return printf("%s, ", s);
}

int main() {
	int index = 0;
	__uint128_t i; 
	printf("static int squares[] = { ");
	for ( i = 1; i*i < 1000000000000; ++i ) {
		print_uint128( i*i );
	}
	printf("};\n");
	print_uint128( i );
}