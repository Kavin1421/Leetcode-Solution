func tilingRectangle(n int, m int) int {
	ans := n * m
	filled := make([]int, n)
	var dfs func(i, j, t int)
	dfs = func(i, j, t int) {
		if j == m {
			i++
			j = 0
		}
		if i == n {
			ans = t
			return
		}
		if filled[i]>>j&1 == 1 {
			dfs(i, j+1, t)
		} else if t+1 < ans {
			var r, c int
			for k := i; k < n; k++ {
				if filled[k]>>j&1 == 1 {
					break
				}
				r++
			}
			for k := j; k < m; k++ {
				if filled[i]>>k&1 == 1 {
					break
				}
				c++
			}
			mx := min(r, c)
			for x := i; x < i+mx; x++ {
				for y := j; y < j+mx; y++ {
					filled[x] |= 1 << y
				}
			}
			for w := mx; w > 0; w-- {
				dfs(i, j+w, t+1)
				for k := 0; k < w; k++ {
					filled[i+w-1] ^= 1 << (j + k)
					if k < w-1 {
						filled[i+k] ^= 1 << (j + w - 1)
					}
				}
			}
		}
	}
	dfs(0, 0, 0)
	return ans
}