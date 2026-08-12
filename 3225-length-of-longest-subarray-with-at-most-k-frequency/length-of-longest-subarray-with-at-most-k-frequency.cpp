class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        int maxl = 0;
        for (int j = 0; j < n; j++) {
            m[nums[j]]++;
            if (m[nums[j]] > k) {
                while (m[nums[j]] > k) {
                    m[nums[i]]--;
                    i++;
                }
            }
            maxl = max(maxl, j - i + 1);
        }
        return maxl;
    }
};