func numberOfArrays(differences []int, lower int, upper int) int {
	num, mi, mx := 0, 0, 0
	for _, d := range differences {
		num += d
		mi = min(mi, num)
		mx = max(mx, num)
	}
	return max(0, upper-lower-(mx-mi)+1)
}