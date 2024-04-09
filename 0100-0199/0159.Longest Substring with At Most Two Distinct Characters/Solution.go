func lengthOfLongestSubstringTwoDistinct(s string) (ans int) {
	cnt := map[byte]int{}
	j := 0
	for i := range s {
		cnt[s[i]]++
		for len(cnt) > 2 {
			cnt[s[j]]--
			if cnt[s[j]] == 0 {
				delete(cnt, s[j])
			}
			j++
		}
		ans = max(ans, i-j+1)
	}
	return
}