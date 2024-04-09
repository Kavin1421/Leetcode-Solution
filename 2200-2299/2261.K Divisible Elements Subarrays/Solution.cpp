class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> s;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            string t;
            for (int j = i; j < n; ++j) {
                if (nums[j] % p == 0 && ++cnt > k) {
                    break;
                }
                t += to_string(nums[j]) + ",";
                s.insert(t);
            }
        }
        return s.size();
    }
};