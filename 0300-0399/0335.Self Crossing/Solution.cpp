class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        vector<int> d = distance;
        for (int i = 3; i < d.size(); ++i) {
            if (d[i] >= d[i - 2] && d[i - 1] <= d[i - 3]) return true;
            if (i >= 4 && d[i - 1] == d[i - 3] && d[i] + d[i - 4] >= d[i - 2]) return true;
            if (i >= 5 && d[i - 2] >= d[i - 4] && d[i - 1] <= d[i - 3] && d[i] >= d[i - 2] - d[i - 4] && d[i - 1] + d[i - 5] >= d[i - 3]) return true;
        }
        return false;
    }
};