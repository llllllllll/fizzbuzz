puts (1..100).map{|i|y,x=i%3==0,i%5==0;y&&x ? 'FizzBuzz' : y ? 'Fizz' : x ? 'Buzz' : i}
