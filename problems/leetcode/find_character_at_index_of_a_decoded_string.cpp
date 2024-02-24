// https://leetcode.com/problems/decoded-string-at-index/description/?envType=daily-question&envId=2023-09-27

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<tuple<string, long long, long long>> token;
        token.push({"", 0, 0});
        string temp = "";
        for(auto& c:s){
            if(c > '0' && c <= '9'){
                tuple<string, long long, long long> top = token.top();
                token.push({temp, c - '0', get<1>(top)*get<2>(top) + temp.size()});
                temp = "";
            }
            else temp += c;
        }
        k--;
        tuple<string, long long, long long> top = token.top();
        token.pop();

        if(token.empty()){
            string retr(1, s[k]);
            return retr;
        }
        k%=get<2>(top);
        while(1){
            tuple<string, long long, long long> curTop = token.top();
            
            if(get<1>(curTop)*get<2>(curTop) <= k){
                break;
            }
            else if(k > get<2>(curTop) && get<2>(curTop) != 0) k%= get<2>(curTop);
            else{
                top = curTop;
                token.pop();
            }
        }
        tuple<string, long long, long long> curTop = token.top();
        k-=(get<1>(curTop)*get<2>(curTop));
        if(get<2>(top)!=0)k%=get<2>(top);
        string node = get<0>(top);
        string retr(1, node[k]);
        return retr;
    }
};