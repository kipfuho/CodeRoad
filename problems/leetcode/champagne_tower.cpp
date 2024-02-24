// https://leetcode.com/problems/champagne-tower/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double wine[query_row + 2][query_row + 2];
        memset(wine, 0, sizeof(wine));
        wine[0][0] = poured;
        
        for(int i = 0; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                if(wine[i][j] <= 1) continue;
                double spare = wine[i][j] - 1;
                wine[i+1][j] += spare / 2.0;
                wine[i+1][j+1] += spare / 2.0;
            }
        }

        return (wine[query_row][query_glass] > 1) ? 1.0 : wine[query_row][query_glass];
    }
};