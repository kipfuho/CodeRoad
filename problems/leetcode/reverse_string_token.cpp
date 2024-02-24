// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    
    string reverseWords(string s) {
        stringstream ss(s);
        string token = "", ret = "";
        ss >> ret;
        reverse(ret.begin(), ret.end());
        while(!ss.eof()){
            ss >> token;
            reverse(token.begin(), token.end());
            ret.push_back(' ');
            ret += token;
        }
        return ret;
    }
};

auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();