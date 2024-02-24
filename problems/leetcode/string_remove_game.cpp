// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0;
        int c1 = 0, c2 = 0;
        for(auto& x:colors){
            if(x == 'A'){
                c1++;
                if(c2 > 2) bob += c2 - 2;
                c2 = 0;
            }
            else if(x == 'B'){
                c2++;
                if(c1 > 2) alice += c1 - 2;
                c1 = 0;
            }
        }
        if(c1 > 2) alice += c1 - 2;
        if(c2 > 2) bob += c2 - 2;
        if(alice > bob){
            return true;
        }
        else{
            return false;
        }
    }
};