object FizzBuzz {
  def main(args: Array[String]) = {
    (1 to 100) map {
      n => (n % 3, n % 5) match {
        case (0, 0) => "FizzBuzz"
        case (0, _) => "Fizz"
        case (_, 0) => "Buzz"
        case (_, _) => n.toString
      }
    } foreach { println(_) }
  }
}
