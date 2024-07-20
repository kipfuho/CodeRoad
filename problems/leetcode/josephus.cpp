#include<bits/stdc++.h>

using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int res = 0, reserve = 0;
    while(numBottles + reserve >= numExchange) {
        res += numBottles;
        numBottles += reserve;
        reserve = numBottles % numExchange;
        numBottles /= numExchange;
    }
    return res + numBottles;
}

int main() {
    cout << numWaterBottles(9, 3);
    return 0;
}