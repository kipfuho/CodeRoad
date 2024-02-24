/* https://codeforces.com/group/Ir5CI6f3FD/contest/281925/problem/F
F. 02. POSTMAN
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Chuyển phát hàng là một công việc quan trọng trong thương mại điện tử là lĩnh vực phát triển bùng nổ trong thời gian hiện nay. Ta xét công việc của một nhân viên giao hàng của Công ty XYZ chuyên bán hàng trên mạng. Nhân viên giao hàng cần phát các kiện hàng (được đóng gói trong các hộp cùng kích thước) đến các khách hàng có địa chỉ trên một đại lộ có dạng một đường thẳng.

Nhân viên giao hàng sẽ nhận các kiện hàng tại trụ sở công ty ở vị trí x=0
, và cần chuyển phát hàng đến n
 khách hàng, được đánh số từ 1
 đến n
. Biết xi
 và mi
 là vị trí của khách hàng i
 và số lượng kiện hàng cần chuyển cho khách hàng này. Do các kiện hàng là khá cồng kềnh nên mỗi lần đi chuyển phát nhân viên giao hàng chỉ có thể mang theo không quá k
 kiện hàng.

Nhân viên giao hàng xuất phát từ trụ sở, nhận một số (không quá k
) kiện hàng và di chuyển theo đại lộ để chuyển phát cho một số khách hàng. Khi giao hết các kiện hàng mang theo, nhân viên giao hàng lại quay trở về trụ sở và lặp lại công việc nói trên cho đến khi chuyển phát được tất cả các kiện hàng cho khách hàng. Sau khi kết thúc công việc chuyển phát, nhân viên phải quay trở lại trụ sở công ty để nộp cho phòng kế toán tất cả các hóa đơn giao nhận có ký nhận của khách hàng. Giả thiết là: tốc độ di chuyển của nhân viên là 1 đơn vị khoảng cách trên một đơn vị thời gian. Thời gian nhận hàng ở trụ sở công ty và thời gian bàn giao hàng cho khách hàng được coi là bằng 0.

Yêu cầu: Giả sử thời điểm mà nhân viên giao hàng bắt đầu công việc là 0. Hãy giúp nhân viên giao hàng tìm cách hoàn thành công việc đã mô tả ở trên tại thời điểm sớm nhất.

Input
Dòng đầu tiên chứa hai số nguyên dương được ghi cách nhau bởi dấu cách n
 và k
 (n≤1000;k≤107)
.

Dòng thứ i
 trong số n
 dòng tiếp theo chứa hai số nguyên được ghi cách nhau bởi dấu cách xi
 (|xi|≤107)
 và mi(1≤mi≤107)
Output
Ghi ra một số nguyên là thời điểm sớm nhất mà người giao hàng có thể hoàn thành nhiệm vụ của mình.

Examples
inputCopy
7 1
9400000 10000000
9500000 10000000
9600000 10000000
9700000 10000000
9800000 10000000
9900000 10000000
10000000 10000000
outputCopy
1358000000000000
inputCopy
4 10
-7 5
-2 3
5 7
9 5
outputCopy
42
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

ll n, k, mincost = 0, temp1, temp2, plen = 0, nlen = 0;
pll positive[1000], negative[1000];

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> k;
    FOR(i, 1, n){
        cin >> temp1 >> temp2;
        if(temp1 < 0) negative[nlen++] = {temp1, temp2};
        else positive[plen++] = {temp1, temp2};
    }
    sort(positive, positive + plen);
    sort(negative, negative + nlen);

    FOD(i, plen - 1, 0){
        temp1 = positive[i].second/k;
        mincost += 2*temp1*positive[i].first;
        positive[i].second -= temp1*k;
        if(positive[i].second > 0){
            mincost += 2*positive[i].first;
            temp2 = k - positive[i].second;
            while(temp2 > 0 && i >= 0){
                positive[--i].second -= temp2;
                if(positive[i].second < 0) temp2 = -positive[i].second;
                else temp2 = 0;
            }
            i++;
        }
    }
    FOR(i, 0, nlen - 1){
        temp1 = negative[i].second/k;
        mincost -= 2*temp1*negative[i].first;
        negative[i].second -= temp1*k;
        if(negative[i].second > 0){
            mincost -= 2*negative[i].first;
            temp2 = k - negative[i].second;
            while(temp2 > 0 && i < nlen){
                negative[++i].second -= temp2;
                if(negative[i].second < 0) temp2 = -negative[i].second;
                else temp2 = 0;
            }
            i--;
        }
    }
    cout << mincost;
    return 0;
}