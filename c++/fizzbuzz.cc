#include<iostream>

int main(){
    int n;
    for (n = 0;n <= 100;((!(n % 15)) ?
			 std::cout << "fizzbuzz\n" : (!(n % 3)) ?
			 std::cout << "fizz\n" : (!(n % 5)) ?
			 std::cout << "buzz\n" : std::cout << n << '\n'), n++);
}
