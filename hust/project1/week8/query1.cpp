/*
Description
Data about submission of a programming contest consists a sequence of lines, each line has the following information:
        <UserID> <ProblemID> <TimePoint> <Status> <Point>
in which the user <UserID> submits his/her code to solve the problem <ProblemID> at time-point <TimePoint>, and gets status <Status> and point <Point>
<UserID>: string of length from 3 to 10
<ProblemID>: string under the format Pxy where x, y are digits 0,1,...,9 (for example P03, P10)
<TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)
<Status>: string with two cases (ERR, OK)
<Point>: integer from {0, 1, 2, ..., 10}

A user can submit the code for solving each problem several time. The point that the user gets for a problem is the maximal point among the submissions for that problem.

Perform a sequence of queries of following types:
?total_number_submissions: return the number of submissions of the contest
?number_error_submision: return the number of submissions having status ERR 
?number_error_submision_of_user <UserID>: return the number of submission having status ERR of user <UserID> 
?total_point_of_user <UserID>: return the total point of user <UserID> 
?number_submission_period <from_time_point> <to_time_point>: return the number of submissions in the period from <from_time_point> to <to_time_point> (inclusive)

Input
The input consists of two blocks of data:
The first block is the operational data, which is a sequence of lines (number of lines can be up to 100000), each line contains the information of a submission with above format .The first block is terminated with a line containing the character #
The second block is the query block, which is a sequence of lines (number of lines can be up to 100000), each line is a query described above. The second block is terminated with a line containing the character #

Output
Write in each line, the result of the corresponding query 

Example
Input
U001 P01 10:30:20 ERR 0
U001 P01 10:35:20 OK 10
U001 P02 10:40:20 ERR 0
U001 P02 10:55:20 OK 7
U002 P01 10:40:20 ERR 0
U001 P01 11:35:20 OK 8
U002 P02 10:40:20 OK 10
#
?total_number_submissions
?number_error_submision
?number_error_submision_of_user U002 
?total_point_of_user U001 
?number_submission_period 10:00:00 11:30:45
#


Output 
7
3
1
17
6
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FOD(i, r, l) for(int i = r; i >= l; i--)
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define bit(x) (x & (-x))

using namespace std;

struct user{
    int id;
    int prob[100];
    int total_point;
    int total_err_submit;
    user(int _id, int _pn, int _pp, int _error){
        FOR(i, 0, 99) prob[i] = 0;
        id = _id;
        prob[_pn] = _pp;
        total_point = _pp;
        total_err_submit = _error;
    }
};

string token1, token2, token3, token4;
int total_error_submit, total_submit, user_id, prob_id, time1, time2, token5;
bool found;
int temp_arr[86401], prefixsum[86401];
vector<vector<user>> data_user(1000000, vector<user>());

inline int get_number(string s){
    int number = 0, len = s.size();
    FOR(i, 0, len - 1){
        if(s[i] > '9' || s[i] < '0') continue;
        number = 10*number + (s[i] - '0');
    }
    return number%1000000;
}

inline int get_time(string time_string){
    return (time_string[0] - '0')*36000 + (time_string[1] - '0')*3600 + (time_string[3] - '0')*600 + (time_string[4] - '0')*60 + (time_string[6] - '0')*10 + time_string[7] - '0';
}

int main(){_
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    time_t start = clock();
    total_error_submit = 0, total_submit = 0;
    while(cin >> token1){
        if(token1 == "#") break;
        cin >> token2 >> token3 >> token4 >> token5;
        user_id = get_number(token1);
        prob_id = get_number(token2);
        time1 = get_time(token3);

        found = false;
        for(auto& x:data_user[user_id]){
            if(x.id == user_id){
                if(token4 == "ERR"){
                    x.total_err_submit++;
                    total_error_submit++;
                }
                if(x.prob[prob_id] < token5){
                    x.total_point += (token5 - x.prob[prob_id]);
                    x.prob[prob_id] = token5;
                }

                found = true;
                break;
            }
        }

        if(!found){
            if(token4 == "ERR"){
                user temp_user = user(user_id, prob_id, 0, 1);
                data_user[user_id].push_back(temp_user);
                total_error_submit++;
            }
            else{
                user temp_user = user(user_id, prob_id, token5, 0);
                data_user[user_id].push_back(temp_user);
            }
        }

        temp_arr[time1]++;
        total_submit++;
    }

    prefixsum[0] = temp_arr[0];
    FOR(i, 1, 86400) prefixsum[i] = prefixsum[i - 1] + temp_arr[i];

    while(cin >> token1){
        if(token1 == "#") break;
        if(token1 == "?total_number_submissions"){
            cout << total_submit << endl;
        }
        else if(token1 == "?number_error_submision"){
            cout << total_error_submit << endl;
        }
        else if(token1 == "?number_error_submision_of_user"){
            cin >> token2;
            user_id = get_number(token2);

            found = false;
            for(auto& x:data_user[user_id]){
                if(x.id == user_id){
                    cout << x.total_err_submit << endl;
                    found = true;
                    break;
                }
            }
            if(!found) cout << "0\n";
        }
        else if(token1 == "?total_point_of_user"){
            cin >> token2;
            user_id = get_number(token2);

            found = false;
            for(auto& x:data_user[user_id]){
                if(x.id == user_id){
                    cout << x.total_point << endl;
                    found = true;
                    break;
                }
            }
            if(!found) cout << "0\n";
        }
        else if(token1 == "?number_submission_period"){
            cin >> token2 >> token3;
            time1 = get_time(token2), time2 = get_time(token3);
            cout << prefixsum[time2] - (time1 > 0 ? prefixsum[time1 - 1] : 0) << endl;
        }
    }
    time_t end = clock();
    cout << "Time: " << (double) (end - start) / CLOCKS_PER_SEC << " s";
    return 0;
}