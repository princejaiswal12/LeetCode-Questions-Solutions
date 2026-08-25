class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%k==0) s.insert(nums[i]/k);
        }
        for(int i=1;i<INT_MAX;i++){
            if(s.find(i)==s.end()) return i*k;
        }
        return 0;
    }
};