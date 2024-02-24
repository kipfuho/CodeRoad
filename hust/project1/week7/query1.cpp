/*
Description
The data about bank transactions consists of a sequence of transactions: the information of each transaction has the following format:
                                                                    <from_account>   <to_account>   <money>   <time_point>   <atm>
In which:
•	<from_account>: the account from which money is transferred (which is a string of length from 6 to 20 )
•	<to_account>: the account which receives money in the transaction (which is a string of length from 6 to 20)
•	<money>: amount of money transferred in the transaction (which is an integer from 1 to 10000)
•	<time_point>: the time point at which the transaction is performed, it is a string under the format HH:MM:SS  (hour: minute: second)
•	<atm>: the code of the ATM where the transaction is taken (a string of length from 3 to 10)
Example: T00112233445 T001234002 2000 08:36:25 BIDV (at the ATM BIDV, account T00112233445 transfers 2000$ to account T001234002 at time point 08:36:25 (08 hour, 36 minutes, 25 seconds) 
A transaction cycle of length k starting from account a1 is defined to be a sequence of distinct account a1, a2, …, ak  in which there are transactions from account a1 to a2, from a2 to a3, …, from ak to a1.
Write a program that process the following queries: 
?number_transactions: compute the total number of transactions of the data
?total_money_transaction: compute the total amount of money of transactions  
?list_sorted_accounts: compute the sequence of bank accounts (including sending and receiving accounts) appearing in the transaction (sorted in an increasing (alphabetical) order)  
?total_money_transaction_from <account>: compute the total amount of money transferred from the account <account>  
?inspect_cycle <account> k : return 1 if there is a transaction cycle of length k, starting from <account>, and return 0, otherwise
Input (stdin)
The input consists of 2 blocks of information: the data block and the query block
•	The data block consists of lines:
o	Each line contains the information about a transaction described above
o	The data is terminated by a line containing #
•	The query block consists of lines:
o	Each line is a query described above
o	The query block is terminated by a line containing #

Output (stdout)
•	Print to stdout (in each line) the result of each query described above

Example
Input
T000010010 T000010020 1000 10:20:30 ATM1
T000010010 T000010030 2000 10:02:30 ATM2
T000010010 T000010040 1500 09:23:30 ATM1
T000010020 T000010030 3000 08:20:31 ATM1
T000010030 T000010010 4000 12:40:00 ATM2
T000010040 T000010010 2000 10:30:00 ATM1
T000010020 T000010040 3000 08:20:31 ATM1
T000010040 T000010030 2000 11:30:00 ATM1
T000010040 T000010030 1000 18:30:00 ATM1
#
?number_transactions
?total_money_transaction
?list_sorted_accounts
?total_money_transaction_from T000010010
?inspect_cycle T000010010 3
#
Output
9
19500
T000010010 T000010020 T000010030 T000010040
4500
1
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
#define NMAX 100001

using namespace std;

string token1, token2, token4, token5;
int total_trans = 0, total_money_trans = 0, token3, temp;
map<int, int> mp;
set<string> account;
vector<vector<int>> g(NMAX, vector<int>()); // for dfs
vector<bool> visited(NMAX, false);

inline int get_number(string s){
    int number = 0;
    char op;
    sscanf(s.c_str(), "%c%d", &op, &number); // extract number
    return number%NMAX;
}

bool dfs(int cur, int target, int k){
    if(k == 0) return false;
    bool valid = false;
    for(auto& x:g[cur]){
        if(k == 1 && x == target) return true;
        if(visited[x]) continue;
        visited[x] = true;
        valid = dfs(x, target, k - 1);
        visited[x] = false;
        if(valid) break;
    }
    return valid;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(cin >> token1){
        if(token1 == "#") break;
        cin >> token2 >> token3 >> token4 >> token5;

        account.insert(token1), account.insert(token2);
        g[get_number(token1)].push_back(get_number(token2));
        mp[get_number(token1)] += token3;
        total_trans++, total_money_trans += token3;
    }
    while(cin >> token1){
        if(token1 == "#") break;
        if(token1 == "?number_transactions"){
            cout << total_trans << endl;
        }
        else if(token1 == "?total_money_transaction"){
            cout << total_money_trans << endl;
        }
        else if(token1 == "?list_sorted_accounts"){
            for(auto& x : account) cout << x << " ";
            cout << endl;
        }
        else if(token1 == "?total_money_transaction_from"){
            cin >> token2;
            cout << mp[get_number(token2)] << endl;
        }
        else if(token1 == "?inspect_cycle"){
            cin >> token2 >> token3;
            temp = get_number(token2);
            visited[temp] = true;
            cout << dfs(temp, temp, token3) << endl;
            visited[temp] = false;
        }
        else continue;
    }
    return 0;
}