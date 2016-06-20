-- Joe Jevnik
-- Compile time FizzBuzz
-- 2014.3.16

import Control.Monad  (void)
import System.Process (system)

-- | A FizzBuzz Type.
type FizzBuzz a = Either String a

-- | The pair of 'String's to be used.
cStrings :: (String,String)
cStrings = ( "int main(void){puts(\""
           , "\");return 0;}"
           )

main :: IO ()
main = appendFile "test.c" (fst cStrings)
       >> evalFizzBuzz "test.c" [1..100]
       >> appendFile "test.c" (snd cStrings)
       >> void (system "gcc test.c -o fizzbuzz")

-- | Shows a 'FizzBuzz' value.
showFizzBuzz :: (Show a) => FizzBuzz a -> String
showFizzBuzz (Left s)  = s
showFizzBuzz (Right n) = show n

-- | Converts an 'Integral' type to a 'FizzBuzz' type.
fizzBuzz :: (Integral a) => a -> FizzBuzz a
fizzBuzz n = case (n `rem` 3,n `rem` 5) of
                 (0,0) -> Left "FizzBuzz"
                 (0,_) -> Left "Fizz"
                 (_,0) -> Left "Buzz"
                 _     -> Right n

-- | Evaluates 'FizzBuzz' on the list.
evalFizzBuzz :: (Integral a,Show a) => FilePath -> [a] -> IO ()
evalFizzBuzz f = mapM_ (appendFile f . (++) "\\n" . showFizzBuzz . fizzBuzz)
