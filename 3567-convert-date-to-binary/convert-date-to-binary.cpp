class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        string y = bitset<32>(year).to_string();
        string m = bitset<32>(month).to_string();
        string d = bitset<32>(day).to_string();

        y.erase(0, y.find_first_not_of('0'));
        m.erase(0, m.find_first_not_of('0'));
        d.erase(0, d.find_first_not_of('0'));

        return y + "-" + m + "-" + d;
    }
};