-- Joe Jevnik
-- 21.9.2013
-- Simple fizzbuzz.
-- Currently winning.

main :: IO ()
main = putStr $ concatMap fizz_buzz [1..100]


fizz_buzz :: Int -> String
fizz_buzz n
    | n `rem` 15 == 0 = "fizzbuzz\n"
    | n `rem` 3 == 0  = "fizz\n"
    | n `rem` 5 == 0  = "buzz\n"
    | otherwise       = show n ++ "\n"
