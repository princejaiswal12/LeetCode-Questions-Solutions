class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store {value, original_index}
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        // Sort by value
        sort(a.begin(), a.end());

        vector<vector<int>> groups;
        vector<int> groupId(n);

        // Create connected components
        int group = 0;
        groups.push_back({});

        groups[0].push_back(a[0].first);
        groupId[a[0].second] = 0;

        for (int i = 1; i < n; i++) {
            // If consecutive sorted values differ by > limit,
            // they cannot belong to the same component.
            if (a[i].first - a[i - 1].first > limit) {
                group++;
                groups.push_back({});
            }

            groups[group].push_back(a[i].first);
            groupId[a[i].second] = group;
        }

        // Pointer to smallest unused value in each group
        vector<int> ptr(groups.size(), 0);

        vector<int> ans(n);

        // Process original indices from left to right
        for (int i = 0; i < n; i++) {
            int g = groupId[i];

            ans[i] = groups[g][ptr[g]];
            ptr[g]++;
        }

        return ans;
    }
};