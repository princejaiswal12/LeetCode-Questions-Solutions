class Solution {
public:
    string interpret(string command) {
        string s = "";
        if(command[0]!='(') s += command[0];
        int n = command.size();
        for(int i=1;i<n;i++){
            if(command[i]==')'&& command[i-1]=='(') s += 'o';
            else if(command[i]==')' || command[i]=='(') continue;
            else s += command[i];
        }
        return s;
    }
};