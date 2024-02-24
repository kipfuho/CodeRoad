// https://leetcode.com/problems/integer-break/

class Solution {
public:
    int integerBreak(int n) {
        long long arr[59];
        memset(arr, 0, sizeof(arr));
        long long best = 0;
        for(int i = 1; i <= n / 2 + 1; i++){
            int time = n / i;
            int offset = n % i;
            if(offset != 0){
                arr[i] = pow(i, time)*offset;
                if(time > 1){
                    long long temp = pow(i, time - 1)*(offset + i);
                    if(temp > arr[i]) arr[i] = temp;
                }
            }
            else if(time > 1) arr[i] = pow(i, time);
            if(arr[i] > best) best = arr[i];
        }
        return best;
    }
};