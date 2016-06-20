// Joe Jevnik
// 21.9.2013
// Basic fizzbuzz in c.

#include <stdio.h>

int main(){
    int n;
    for (n = 0;n <= 100;((!(n % 15)) ?
			 puts("fizzbuzz") : (!(n % 3)) ?
			 puts("fizz") : (!(n % 5)) ?
			 puts("buzz") : printf("%i\n",n)), n++);
}
