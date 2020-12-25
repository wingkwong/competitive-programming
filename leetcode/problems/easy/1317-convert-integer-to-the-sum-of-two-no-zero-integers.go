func getNoZeroIntegers(n int) []int {
    A, B := 1, n - 1
    for {
        if check(A) && check(B) { return []int{ A, B } }
        A++
        B--
    }
    return nil
}

func check(n int) bool {
    for n > 10 {
        if n % 10 == 0 {
            return false
        }
        n /= 10
    }
    return n != 10
}