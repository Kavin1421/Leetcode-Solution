func minOperations(s string) int {
	cnt := 0
	for i, c := range s {
		if c != []rune("01")[i&1] {
			cnt++
		}
	}
	return min(cnt, len(s)-cnt)
}