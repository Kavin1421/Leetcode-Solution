func maxWidthOfVerticalArea(points [][]int) (ans int) {
	sort.Slice(points, func(i, j int) bool { return points[i][0] < points[j][0] })
	for i, p := range points[1:] {
		ans = max(ans, p[0]-points[i][0])
	}
	return
}