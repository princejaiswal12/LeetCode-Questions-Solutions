class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> pos(26);

        // Store position of each character in s
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'] = i;
        }

        int ans = 0;

        // Compare positions with t
        for (int i = 0; i < t.size(); i++) {
            ans += abs(pos[t[i] - 'a'] - i);
        }

        return ans;
    }
};