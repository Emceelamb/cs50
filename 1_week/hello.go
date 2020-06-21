package main
import (
  "bufio"
  "os"
  "fmt"
)

func main(){
  scanner := bufio.NewScanner(os.Stdin);

  fmt.Println("Whats your name?")

  scanner.Scan();
  name := scanner.Text();

  fmt.Printf("Hello %s.\n", name)
}
