class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int cnt = 0, ans = 0;
        for (int v : nums) {
            if (v == 1) {
                ++cnt;
            } else {
                ans = Math.max(ans, cnt);
                cnt = 0;
            }
        }
        return Math.max(cnt, ans);
    }
}