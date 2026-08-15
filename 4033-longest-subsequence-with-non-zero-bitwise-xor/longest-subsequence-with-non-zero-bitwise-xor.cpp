class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            xr ^= x;
            if (x != 0)
                hasNonZero = true;
        }

        // Entire array has non-zero XOR
        if (xr != 0)
            return nums.size();

        // XOR of entire array is zero
        // If there is a non-zero element, remove it
        if (hasNonZero)
            return nums.size() - 1;

        // All elements are zero
        return 0;
    }
};