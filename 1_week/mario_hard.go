package main

import "fmt"

func main() {
  var num int
  fmt.Print("Enter a number: ")
  fmt.Scan(&num)
  for num<=0{
    fmt.Print("Invalid number: ")
    fmt.Scan(&num)
  }

  build_pyramid(num);
}

func build_pyramid(num int){
  for i := 0; i <num; i++ {
    for j := 0; j < num; j++ {
      build_left(num, i, j);
    }

    build_space();

    for j := 0; j < num; j++{
      build_right(i, j);
    }
    fmt.Printf("\n");
  }
}


func build_left(num, i, j int){
  if j < num-i-1{
    fmt.Printf(" ");
  }else {
    fmt.Printf("#");
  }
}

func build_right(i, j int){
  if(j < i+1){
    fmt.Printf("#");
  }else {
    fmt.Printf(" ");
  }
}

func build_space(){
  fmt.Printf("  ");
}

