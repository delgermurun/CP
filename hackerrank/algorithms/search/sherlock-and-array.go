package main

import "fmt"

func main() {
  var f bool
  var t, n int
  var s int
  var a [100000] int

  fmt.Scanf("%d", &t)

  for i := 0; i < t; i++ {
    fmt.Scanf("%d", &n)

    s = 0
    for j := 0; j < n; j++ {
      fmt.Scanf("%d", &a[j])
      s += a[j]
    }

    f = false
    cur := 0
    for j := 0; j < n; j++ {
      if j > 0 {
        cur += a[j-1]
      }
      if cur * 2 == s-a[j] {
        f = true
        break
      }
    }

    if f {
      fmt.Println("YES")
    } else {
      fmt.Println("NO")
    }
  }
}
