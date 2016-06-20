#include <stdio.h>
int main(void){
    int n,f,b;
    for (n = 0;n <= 100;f = !(n % 3),b = !(n % 5),(f && b) ? puts("FizzBuzz"): (f) ? puts("Fizz"): (b) ? puts("Buzz"): printf("%d\n",n),++n);
    return 0;
}
