class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        for (int i = 0, n = word.size(); i < n; ++i) {
            char c = word[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ans += (i + 1LL) * (n - i);
            }
        }
        return ans;
    }
};