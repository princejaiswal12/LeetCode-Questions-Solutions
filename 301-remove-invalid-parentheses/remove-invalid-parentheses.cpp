class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int idx, int leftCount, int rightCount,
             int leftRem, int rightRem, string &cur) {

        if (idx == s.size()) {
            if (leftRem == 0 && rightRem == 0 && leftCount == rightCount) {
                ans.insert(cur);
            }
            return;
        }

        char ch = s[idx];

        // Remove current character
        if (ch == '(' && leftRem > 0) {
            dfs(s, idx + 1, leftCount, rightCount,
                leftRem - 1, rightRem, cur);
        }

        if (ch == ')' && rightRem > 0) {
            dfs(s, idx + 1, leftCount, rightCount,
                leftRem, rightRem - 1, cur);
        }

        // Keep current character
        cur.push_back(ch);

        if (ch != '(' && ch != ')') {
            dfs(s, idx + 1, leftCount, rightCount,
                leftRem, rightRem, cur);
        }
        else if (ch == '(') {
            dfs(s, idx + 1, leftCount + 1, rightCount,
                leftRem, rightRem, cur);
        }
        else {
            if (leftCount > rightCount) {
                dfs(s, idx + 1, leftCount, rightCount + 1,
                    leftRem, rightRem, cur);
            }
        }

        cur.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0;
        int rightRem = 0;

        // Find minimum removals required
        for (char ch : s) {
            if (ch == '(') {
                leftRem++;
            }
            else if (ch == ')') {
                if (leftRem > 0) {
                    leftRem--;
                }
                else {
                    rightRem++;
                }
            }
        }

        string cur;

        dfs(s, 0, 0, 0, leftRem, rightRem, cur);

        return vector<string>(ans.begin(), ans.end());
    }
};