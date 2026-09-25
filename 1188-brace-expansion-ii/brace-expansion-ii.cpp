class Solution {
public:
    string s;
    int i = 0;

    set<string> parse() {
        set<string> result;

        if (s[i] == '{') {
            i++; // skip {

            set<string> current = parse();

            result.insert(current.begin(), current.end());

            while (s[i] == ',') {
                i++; // skip ,

                set<string> next = parse();

                result.insert(next.begin(), next.end());
            }

            i++; // skip }
        } 
        else {
            string word;

            while (i < s.size() && isalpha(s[i])) {
                word += s[i++];
            }

            result.insert(word);
        }

        // Handle concatenation
        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> next = parse();
            set<string> temp;

            for (string a : result) {
                for (string b : next) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parse();

        return vector<string>(ans.begin(), ans.end());
    }
};