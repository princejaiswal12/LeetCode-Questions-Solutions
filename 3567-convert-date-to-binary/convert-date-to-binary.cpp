class Solution {
public:
    string toBinary(int n) {
        string res;
        
        while (n > 0) {
            res += char('0' + (n % 2));
            n /= 2;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }

    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        return toBinary(year) + "-" + 
               toBinary(month) + "-" + 
               toBinary(day);
    }
};