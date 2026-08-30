class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int mn = INT_MAX;
        int mni = -1;
        int mxi = -1;
        for(int i=0;i<n;i++){
            if(mx<nums[i]){
                mx = max(mx,nums[i]);
                mxi = i;
            }
            if(mn>nums[i]){
                mn = min(mn,nums[i]);
                mni = i;
            }
        }
        return min({max(mxi,mni)+1,max(n-mxi,n-mni),(mxi+1)+(n-mni),(mni+1)+(n-mxi)});
    }
};