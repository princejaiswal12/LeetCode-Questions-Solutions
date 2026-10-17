
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int x : nums) {
            arr.push_back({x, digitSum(x)});
        }

        sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        });

        vector<int> target(n);

        unordered_map<int, int> originalIndex;

        for (int i = 0; i < n; i++) {
            originalIndex[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            target[i] = originalIndex[arr[i].first];
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || target[i] == i)
                continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = target[j];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
