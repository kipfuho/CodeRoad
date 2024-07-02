class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> num3(num1.size() + num2.size(), 0);

        int idx = 0, len2 = num2.size();
        for(auto x:num1){
            int i = 0;
            for(auto y:num2){
                num3[idx + i] += (x -'0')*(y -'0');
                i++;
            }
            idx++;
        }

        for(int i = 0; i < num3.size() - 1; i++){
            num3[i + 1] += num3[i]/10;
            num3[i] %= 10;
        }

        string res;
        if(num3[num3.size() - 1] != 0){
            res.push_back('0' + num3[num3.size() - 1]);
        }
        for(int i = num3.size() - 2; i >= 0; i--){
            res.push_back('0' + num3[i]);
        }
        
        return res;
    }
};