func maximumDifference(nums []int) int {
	mi := 1 << 30
	ans := -1
	for _, x := range nums {
		if mi < x {
			ans = max(ans, x-mi)
		} else {
			mi = x
		}
	}
	return ans
}