class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int a:nums){
            sum += a;
        }
        int tar = sum - x;
        if(tar<0) return -1;
        if(tar==0) return n;
        int i = 0;
        int t = 0;
        int lon = -1;
        for(int j=0;j<n;j++){
            t += nums[j];
            while(t>tar){
                t -= nums[i];
                i++;
            }
            if(t==tar){
                lon = max(lon,j-i+1);
            }
        }
        return lon == -1 ? -1 : n - lon;
    }
};