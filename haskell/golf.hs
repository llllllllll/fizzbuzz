main=mapM_ putStrLn [max(show x)(concat[n|(f,n)<-[(3,"Fizz"),(5,"Buzz")],rem x f==0])|x<-[1..100]]
