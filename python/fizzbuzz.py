#!/usr/bin/env python3


def fizzbuzz():
    lookup = {
        (True, True): lambda _: 'FizzBuzz',
        (True, False): lambda _: 'Fizz',
        (False, True): lambda _: 'Buzz',
        (False, False): lambda n: str(n)
    }
    return (lookup[(not n % 3, not n % 5)](n) for n in range(1, 101))


if __name__ == '__main__':
    for f in fizzbuzz():
        print(f)
