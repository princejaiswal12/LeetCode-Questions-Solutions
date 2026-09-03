class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> even,odd;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even.push_back(nums[i]);
            }
        }
        if(even.size()==n) return true;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                odd.push_back(nums[i]);
            }else{
                for(int j=0;j<i;j++){
                    if(j==i) continue;
                    if((nums[i]-nums[j])%2!=0 && (nums[i]-nums[j])>=1){
                        odd.push_back(nums[i]-nums[j]);
                        break;
                    }
                }
            }
        }
        if(odd.size()==n) return true;
        return false;
    }
};