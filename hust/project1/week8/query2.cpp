/*
Description
CITIZEN
Given a DataBase about citizen, perform queries over this DataBase.
Input
The input consists of two blocks: the first block is the DataBase and the second block is the list of queries. Two blocks are separated by a line containing a character *.
1. The first block (DataBase about citizen) consists of lines (number of lines can be upto 100000), each line is the information about a person and is under the format:
        <code>  <dat_of_birth>  <fathher_code>   <mother_code>  <is_alive>  <region_code>
in which:
 <code>: the code of the person which is a string of length 7
 <date_of_birth>: the date of birth of the person and has the format YYYY-MM-DD (for example 1980-02-23), <date_of_birth> is before 3000-12-31
 <fathher_code> and <mother_code> is the code of father and mother: they are also strings of length 7. If the code is 0000000, then the current person does not has information about his father or mother
 <is_alive>: a character with two values: ‘Y’ means that the person is still alive, and ‘N’ means tat the current person is died.
 <region_code>: the code of the region where the person lives

2. The second block is the list of queries (number of queries can be upto 100000) over the DataBase which consists of following commands:
 NUMBER_PEOPLE: return the number of people (number of lines of the DataBase)
 NUMBER_PEOPLE_BORN_AT <date>: return the number of people having date-of-birth is equal to <date>
 MOST_ALIVE_ANCESTOR <code>: find the most ancestor (farthest in term of generation distance) of the given person <code>. Return the generation distance between the ancestor found and the given person
 NUMBER_PEOPLE_BORN_BETWEEN <from_date> <to_date>: compute the number of people having date-of-birth between <from_date> and <to_date> (<from_date> and <to_date> are under the form YYYY-MM-DD, <to_date> is before 3000-12-31)
 MAX_UNRELATED_PEOPLE: find a subset of people in which two any people of the subset do not have father/mother-children and the size of the subset is maximal. Return the size of the subset found.
The second block is terminated by a line containing ***.
Output
 Each line presents the result of the corresponding query (described above).
Example
Input
0000001 1920-08-10 0000000 0000000 Y 00002
0000002 1920-11-03 0000000 0000000 Y 00003
0000003 1948-02-13 0000001 0000002 Y 00005
0000004 1946-01-16 0000001 0000002 Y 00005
0000005 1920-11-27 0000000 0000000 Y 00005
0000006 1920-02-29 0000000 0000000 Y 00004
0000007 1948-07-18 0000005 0000006 Y 00005
0000008 1948-07-18 0000005 0000006 Y 00002
0000009 1920-03-09 0000000 0000000 Y 00005
0000010 1920-10-16 0000000 0000000 Y 00005
*
NUMBER_PEOPLE
NUMBER_PEOPLE_BORN_AT 1919-12-10
NUMBER_PEOPLE_BORN_AT 1948-07-18
MAX_UNRELATED_PEOPLE
MOST_ALIVE_ANCESTOR 0000008
MOST_ALIVE_ANCESTOR 0000001
NUMBER_PEOPLE_BORN_BETWEEN 1900-12-19 1928-11-16
NUMBER_PEOPLE_BORN_BETWEEN 1944-08-13 1977-12-15
NUMBER_PEOPLE_BORN_BETWEEN 1987-01-24 1988-06-03
***
Output
10
0
2
6
1
0
6
4
0
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

string token1, token2, token3, token4, token5, token6;
int ppl_number = 0, not_parent_child, code, day_num1, day_num2, fcode, mcode;
int birthday[1100000], birthday_prefix[1100000], greatest_alive_ancestor[100001], generation[100001], ppl_number_of_generation[100001];
bool still_alive[100001];

inline int get_number(string s){
    int number = 0, len = s.size();
    FOR(i, 0, len - 1){
        if(s[i] > '9' || s[i] < '0') continue;
        number = 10*number + (s[i] - '0');
    }
    return number%100001;
}

// 372 days per year???? perfecto test case!
inline int get_time(string time_string){
    int year = (time_string[0] - '0')*1000 + (time_string[1] - '0')*100 + (time_string[2] - '0')*10 + time_string[3] - '0';
    int month = (time_string[5] - '0')*10 + time_string[6] - '0';
    int day = (time_string[8] - '0')*10 + time_string[9] - '0';
    return (year*372 + (month - 1)*31 + day)%1100000;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> token1){
        if(token1 == "*") break;
        cin >> token2 >> token3 >> token4 >> token5 >> token6;
        code = get_number(token1);
        day_num1 = get_time(token2);
        fcode = get_number(token3);
        mcode = get_number(token4);

        if(token5 == "Y") still_alive[code] = true;
        else still_alive[code] = false;
        if(still_alive[fcode]) greatest_alive_ancestor[code] = greatest_alive_ancestor[fcode] + 1;
        if(still_alive[mcode]) greatest_alive_ancestor[code] = max(greatest_alive_ancestor[code], greatest_alive_ancestor[mcode] + 1);
        generation[code] = max(generation[fcode], generation[mcode]) + 1;
        ppl_number_of_generation[generation[code]]++;
        birthday[day_num1]++;
        ppl_number++;
    }

    birthday_prefix[0] = birthday[0];
    FOR(i, 1, 1100000) birthday_prefix[i] = birthday_prefix[i - 1] + birthday[i];
    not_parent_child = max(ppl_number_of_generation[1], ppl_number_of_generation[2]);
    FOR(i, 3, 100000){
        ppl_number_of_generation[i] = max(ppl_number_of_generation[i - 2], ppl_number_of_generation[i - 3]) + ppl_number_of_generation[i];
        not_parent_child = max(not_parent_child, ppl_number_of_generation[i]);
    }
    
    while(cin >> token1){
        if(token1 == "*") break;
        if(token1 == "NUMBER_PEOPLE"){
            cout << ppl_number << endl;
        }
        else if(token1 == "NUMBER_PEOPLE_BORN_AT"){
            cin >> token2;
            day_num1 = get_time(token2);
            cout << birthday[day_num1] << endl;
        }
        else if(token1 == "MOST_ALIVE_ANCESTOR"){
            cin >> token2;
            code = get_number(token2);
            cout << greatest_alive_ancestor[code] << endl;
        }
        else if(token1 == "NUMBER_PEOPLE_BORN_BETWEEN"){
            cin >> token2 >> token3;
            day_num1 = get_time(token2), day_num2 = get_time(token3);
            cout << birthday_prefix[day_num2] - birthday_prefix[day_num1 - 1] << endl;
        }
        else if(token1 == "MAX_UNRELATED_PEOPLE"){
            cout << not_parent_child << endl;
        }
    }
    return 0;
}