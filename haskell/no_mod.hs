-- Joe Jevnik
-- 21.9.2013
-- An implementation that avoids calling `rem` or `mod`

main :: IO ()
main = putStrLn $ concatMap fizz_buzz (take 100 $ zip [1..] fizz_ls)

fizz_buzz :: (Integral a, Show a) => (a,String) -> String
fizz_buzz (n,f)
    | null f    = '\n':show n
    | otherwise = '\n':f

fizz_ls = zipWith (++) (cycle ["","","fizz"]) (cycle ["","","","","buzz"])
