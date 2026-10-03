class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> m;

        for(int x : nums) {
            m[x]++;
        }

        vector<int> ans;

        while(!m.empty()) {
            vector<int> remove;

            for(auto [a, b] : m) {
                ans.push_back(a);

                if(b == 1)
                    remove.push_back(a);
                else
                    m[a]--;
            }

            for(int x : remove) {
                m.erase(x);
            }
        }

        return ans;
    }
};