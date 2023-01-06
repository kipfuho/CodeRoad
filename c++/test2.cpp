#include<iostream>
#include<string>
using namespace std;
class Time {
    private:
    int hour;
    int minute;
    int second;
    public:
    Time(int a,int b,int c){
        this->hour=a;
        this->minute=b;
        this->second=c;
    }
    void setTime(int a,int b,int c){
        this->hour=a;
        this->minute=b;
        this->second=c;
    }
    void setHour(int a){
        this->hour=a;
    }
    void setMinute(int b){
        this->minute=b;
    }
    void setSecond(int c){
        this->second=c;
    }
    int getHour(){
        return hour;
    }
    int getMinute(){
        return minute;
    }
    int getSecond(){
        return second;
    }
    void nextSecond(){
        if(second==59){
            if(minute==59){
                if(hour==23){
                    second=0;
                    minute=0;
                    hour=0;
                }
                else{
                    second=0;
                    minute=0;
                    hour++;
                }
            }
            else{
                second=0;
                minute++;
            }
        }
        else{
            second++;
        }
    }
    void previousSecond(){
        if(second==0){
            if(minute==0){
                if(hour==0){
                    second=59;
                    minute=59;
                    hour=23;
                }
                else{
                    second=59;
                    minute=59;
                    hour--;
                }
            }
            else{
                second=59;
                minute--;
            }
        }
        else{
            second--;
        }
    }
    void display(){
        string hour=to_string(this->hour);
        string minute=to_string(this->minute);
        string second=to_string(this->second);
        if(hour.length()==1){
            hour="0"+hour;
        }
        if(minute.length()==1){
            minute="0"+minute;
        }
        if(second.length()==1){
            second="0"+second;
        }
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
};
