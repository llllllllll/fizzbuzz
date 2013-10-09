// Joe Jevnik
// 21.9.2013
// Basic fizzbuzz in c.

#include <stdio.h>

inline void fizz_buzz(int n){
    if (!(n % 15)){
	printf("fizzbuzz\n");
	return;
    } else if (!(n % 3)){
	printf("fizz\n");
	return;
    } else if (!(n % 5)){
	printf("buzz\n");
	return;
    } else {
	printf("%i\n",n);
    }
}

int main(){
    int n;
    for (n = 0;n <= 100;fizz_buzz(n++));
}
