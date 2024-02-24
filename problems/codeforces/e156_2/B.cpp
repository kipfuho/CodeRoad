//

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        double px, py, ax, ay, bx, by;
        cin >> px >> py >> ax >> ay >> bx >> by;
        double d1 = sqrt(px*px + py*py), 
            d2 = min(sqrt(ax*ax + ay*ay), sqrt(bx*bx + by*by)),
            d3 = min(sqrt((ax-px)*(ax-px) + (ay-py)*(ay-py)), sqrt((bx-px)*(bx-px) + (by-py)*(by-py)));
        
    }
}