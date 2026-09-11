class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;

        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 8; c += 2) {

                    vector<int> need = {a, b, c};
                    vector<int> freq(10, 0);

                    for (int x : digits)
                        freq[x]++;

                    bool possible = true;

                    for (int x : need) {
                        if (freq[x] == 0) {
                            possible = false;
                            break;
                        }
                        freq[x]--;
                    }

                    if (possible) {
                        int num = a * 100 + b * 10 + c;
                        st.insert(num);
                    }
                }
            }
        }

        return st.size();
    }
};