class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx = max(mx,nums[i]);
        }
        int move = 0;
        for(int i=0;i<nums.size();i++){
            move += (mx-nums[i]);
        }
        return move;
    }
};