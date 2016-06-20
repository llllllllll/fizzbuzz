;; Joe Jevnik
;; 21.9.2013
;; A simple fizzbuzz in scheme
(import (srfi srfi-1))

(define (fizz-buzz n)
  (cond
   ((= 0 (remainder n 15)) 'FizzBuzz)
   ((= 0 (remainder n 3)) 'Fizz)
   ((= 0 (remainder n 5)) 'Buzz)
   (else n)))

(map
 (lambda (f)
   (format #t "~a\n" (fizz-buzz f)))
 (iota 100 1))
