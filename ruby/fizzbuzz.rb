(1..100).each {|i| (y=(i%3==0));(x=(i%5==0));if (y && x) then puts "FizzBuzz" elsif y then puts "Fizz" elsif x then puts "Buzz" else puts i end}

