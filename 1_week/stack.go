package main

import "fmt"

func main(){
  var num int

  fmt.Print("Enter a number: ")
  fmt.Scan(&num)

  for num < 0{
    fmt.Print("Enter a number: ")
    fmt.Scan(&num)
  }

  for x := 0; x < num ; x++{
    for y := 0; y < num; y++{
      fmt.Print("# ")
    }
    fmt.Print("\n")
  }
}
