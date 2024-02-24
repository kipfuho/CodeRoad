/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <random>

using namespace std;

int main()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,100);
    
    int roll5 = 0, rateup = 0, pity = 0, offrate = 0, currRoll; 
    for(int i = 1; i <= 10000000; i++){
        currRoll = dist6(rng);
        if(currRoll > 98){
            roll5++;
            pity = 0;
            if(currRoll == 100 || offrate == 2){
                rateup++;
                offrate = 0;
            }
            else offrate++;
        }
        else{
            pity++;
            if(pity == 50){
                roll5++;
                pity = 0;
                if(currRoll > 50 || offrate == 2){
                    rateup++;
                    offrate = 0;
                }
                else offrate++;
            }
        }
    }
    
    cout << roll5 << " " << rateup;

    return 0;
}
