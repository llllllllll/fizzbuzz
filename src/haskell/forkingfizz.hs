-- Joe Jevnik
-- 21.9.2013
-- Experiment with threading to do checks.
-- Poor performance unfortunatly.

import Control.Monad (mapM_)
import Control.Concurrent (runInBoundThread)

main :: IO ()
main = mapM_ (runInBoundThread . fizz_buzz) [1..100]
  where
      fizz_buzz :: Int -> IO ()
      fizz_buzz n
          | n `rem` 15 == 0 = putStrLn "fizzbuzz"
          | n `rem` 3 == 0 =  putStrLn "fizz"
          | n `rem` 5 == 0 =  putStrLn "buzz"
          | otherwise =       putStrLn $ show n
                         
