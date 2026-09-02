class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<int> st(jewels.begin(),jewels.end());
        int n = stones.size();
        int c = 0;
        for(int i=0;i<n;i++){
            if(st.count(stones[i])) c++;
        }
        return c;
    }
};