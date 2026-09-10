class Solution {
public:
    vector<string> v;
    void f(int n,string s){
        if(s.size()>=n){
            v.push_back(s);
            return;
        }
        if(!s.size()){
            f(n,s+'a');
            f(n,s+'b');
            f(n,s+'c');
        }else if(s.back()=='a'){
            f(n,s+'b');
            f(n,s+'c');
        }else if(s.back()=='b'){
            f(n,s+'a');
            f(n,s+'c');
        }else{
            f(n,s+'a');
            f(n,s+'b');
        }
    }
    string getHappyString(int n, int k) {
        f(n,"");
        sort(v.begin(),v.end());
        if(v.size()<k) return "";
        return v[k-1];
    }
};