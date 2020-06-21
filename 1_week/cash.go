package main

import "fmt"

func main(){
  var money float32
  var cents int
  var coins uint

  for(money <=0){
    fmt.Print("Enter an amount: ")
    fmt.Scan(&money)
  }

  cents = int(money*100);
  fmt.Printf("$%.2f is %d cents.\n", money, cents)
 
  for cents > 0 {
    if cents - 25 >= 0 {
      cents = cents - 25
      coins +=  1
      fmt.Printf("Quarter added. %d cents left.\n", cents)
    } else if cents - 10 >=0 {
      cents -= 10
      coins += 1
      fmt.Printf("Dime added. %d cents left.\n", cents)

    } else if cents -5 >= 0{
      cents -= 5
      coins += 1
      fmt.Printf("Nickel added. %d cents left. \n", cents)
    } else if cents -1 >=0 {
      cents -= 1
      coins += 1
      fmt.Printf("Penny added. %d cents left. \n", cents)
    }
  }

  fmt.Printf("Total coins: %d\n", coins)
}
