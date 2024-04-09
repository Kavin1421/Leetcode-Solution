func distributeCookies(cookies []int, k int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(cookies)))
	cnt := make([]int, k)
	ans := 1 << 30
	var dfs func(int)
	dfs = func(i int) {
		if i >= len(cookies) {
			ans = slices.Max(cnt)
			return
		}
		for j := 0; j < k; j++ {
			if cnt[j]+cookies[i] >= ans || (j > 0 && cnt[j] == cnt[j-1]) {
				continue
			}
			cnt[j] += cookies[i]
			dfs(i + 1)
			cnt[j] -= cookies[i]
		}
	}
	dfs(0)
	return ans
}