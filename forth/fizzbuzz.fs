: fizzbuzz ( -- )
  101 1 do
    I 5 mod I 3 mod 2dup or
    0= if
      2drop ." fizzbuzz"
    else
      0= if
        drop ." fizz"
      else
        0= if
          ." buzz"
        else
          I .
        then
      then
    then
    cr
  loop ;