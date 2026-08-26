class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;

        // Store positions of all '1's
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }

        // Not enough 1s
        if (ones.size() < k) {
            return "";
        }

        string ans = "";

        // Consider every k consecutive 1s
        for (int i = 0; i + k - 1 < ones.size(); i++) {
            int left = ones[i];
            int right = ones[i + k - 1];

            string curr = s.substr(left, right - left + 1);

            // Choose shortest, then lexicographically smallest
            if (ans.empty() ||
                curr.size() < ans.size() ||
                (curr.size() == ans.size() && curr < ans)) {
                ans = curr;
            }
        }

        return ans;
    }
};