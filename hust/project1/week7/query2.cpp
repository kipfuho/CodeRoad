/*
Description
Data about sales in an e-commerce company (the e-commerce company has several shops) consists a sequence of lines, each line (represents an order) has the following information:
            <CustomerID> <ProductID> <Price> <ShopID> <TimePoint>
in which the customer <CustomerID> buys a product <ProductID> with price <Price> at the shop <ShopID> at the time-point <TimePoint>
<CustomerID>: string of length from 3 to 10
<ProductID>: string of length from 3 to 10
<Price>: a positive integer from 1 to 1000
<ShopID>: string of length from 3 to 10
<TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)


Perform a sequence of queries of following types:
?total_number_orders: return the total number of orders
?total_revenue: return the total revenue the e-commerce company gets
?revenue_of_shop <ShopID>: return the total revenue the shop <ShopID> gets 
?total_consume_of_customer_shop <CustomerID> <ShopID>: return the total revenue the shop <ShopID> sells products to customer <CustomerID> 
?total_revenue_in_period <from_time> <to_time>: return the total revenue the e-commerce gets of the period from <from_time> to <to_time> (inclusive)

Input
The input consists of two blocks of data:
The first block is the operational data, which is a sequence of lines (number of lines can be upto 100000), each line contains the information of a submission with above format 
The first block is terminated with a line containing the character #
The second block is the query block, which is a sequence of lines (number of lines can be upto 100000), each line is a query described above
The second block is terminated with a line containing the character #

Output
Write in each line, the result of the corresponding query 

Example
Input
C001 P001 10 SHOP001 10:30:10
C001 P002 30 SHOP001 12:30:10
C003 P001 40 SHOP002 10:15:20
C001 P001 80 SHOP002 08:40:10
C002 P001 130 SHOP001 10:30:10
C002 P001 160 SHOP003 11:30:20
#
?total_number_orders
?total_revenue
?revenue_of_shop SHOP001
?total_consume_of_customer_shop C001 SHOP001 
?total_revenue_in_period 10:00:00 18:40:45
#


Output 
6
450
170
40
370
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

int val_time[86401], prefixsum[86401];
map<pair<int, int>, int> mp;
map<int, int> mp2;

inline int get_shopid(string shop_string){
    int id = 0, len = shop_string.size();
    for(int i = len - 1; i >= 0; i--){
        if(shop_string[i] > '9' || shop_string[i] < '0') break;
        id = 10*id + (shop_string[i] - '0');
    }
    return id;
}

inline int get_consumerid(string consumer_string){
    int id = 0, len = consumer_string.size();
    for(int i = len - 1; i >= 0; i--){
        if(consumer_string[i] > '9' || consumer_string[i] < '0') break;
        id = 10*id + (consumer_string[i] - '0');
    }
    return id;
}

inline int get_time(string time_string){
    return (time_string[0] - '0')*36000 + (time_string[1] - '0')*3600 + (time_string[3] - '0')*600 + (time_string[4] - '0')*60 + (time_string[6] - '0')*10 + time_string[7] - '0';
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string op;
    int total_number_orders = 0, total_revenue = 0;
    while(cin >> op){
        if(op == "#") break;
        int cid = get_consumerid(op);
        cin >> op;
        int price;
        cin >> price;
        cin >> op;
        int sid = get_shopid(op);
        cin >> op;
        int time = get_time(op);

        total_number_orders++;
        total_revenue += price;
        val_time[time] += price;
        mp[{sid, cid}] += price;
        mp2[sid] += price;
    }
    prefixsum[0] = val_time[0];
    for(int i = 1; i <= 86400; i++){
        prefixsum[i] = prefixsum[i - 1] + val_time[i];
    }
    while(cin >> op){
        if(op == "#") break;
        if(op == "?total_number_orders"){
            cout << total_number_orders << endl;
        }
        else if(op == "?total_revenue"){
            cout << total_revenue << endl;
        }
        else if(op == "?revenue_of_shop"){
            cin >> op;
            int sid = get_shopid(op);
            cout << mp2[sid] << endl;
        }
        else if(op == "?total_consume_of_customer_shop"){
            cin >> op;
            int cid = get_consumerid(op);
            cin >> op;
            int sid = get_shopid(op);
            cout << mp[{sid, cid}] << endl;
        }
        else if(op == "?total_revenue_in_period"){
            cin >> op;
            int left = get_time(op);
            cin >> op;
            int right = get_time(op);
            cout << prefixsum[right] - ((left > 0) ? prefixsum[left - 1] : 0) << endl;
        }
        else continue;
    }
    return 0;
}
