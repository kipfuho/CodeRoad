/*
// Problem: minimum of columns we need to delete so the expression is true

Long là một cậu bé 6 tuổi và cậu ấy đang học phép cộng theo cách cộng cột có nhiều chữ số. Anh ấy thường
thực hiện phép cộng hai số nguyên như sau:
  321
+ 456
  777
Đôi khi, Long thực hiện phép cộng không chính xác và bây giờ là lúc bạn phải giúp anh ấy trước khi anh ấy
nộp bài tập về nhà cho giáo viên của mình. Vì Long đã viết phần bổ sung vào vở của mình, bạn
chỉ có thể xóa một số cột trong phần bổ sung của mình để làm cho nó chính xác. Ví dụ, trong phần bổ sung sau,
bạn có thể có được một phép bổ sung chính xác bằng cách xóa cột đầu tiên và cột thứ tư.
  71212     122
+ 12348 → + 238
  93650     360
Nhiệm vụ của bạn là tìm ra mức tối thiểu để biểu thức đúng

input:
3 số lần lượt theo biểu thức
output:
số cột tối thiểu cần xoá để biểu thức đúng

example:
input:
71212
12348
93650
output:
2
*/

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int const nmax=10e6+1;
string a,b,c;

int r[nmax];
int res[nmax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fill_n(r,nmax,0);
	fill_n(res,nmax,0);
	cin>>a; // so 1		EX:		211
	cin>>b; // so 2		   	   + 12
	cin>>c; // ket qua			123	-> result = 1
	int n=max(max(a.size(),b.size()),c.size());
	int n1=a.size(),n2=b.size(),n3=c.size();
	FOR(i,0,n-n1-1) a="0"+a;
	FOR(i,0,n-n2-1) b="0"+b;
	FOR(i,0,n-n3-1) c="0"+c;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	reverse(c.begin(),c.end());
	FOR(i,0,n-1){
		int temp=a[i]+b[i]-2*'0';
        FOR(j,0,i-1){
            if((temp%10+r[j])%10==c[i]-'0'){
                if(res[j]+1>res[i]){
                    res[i]=res[j]+1;
                    r[i]=(temp>=10 || (temp%10+r[j])>=10);	
                }
            }
        }
        if(res[i]==0){
            if(temp%10==c[i]-'0'){
				res[i]=1;
                r[i]=(temp>=10);
            }
        }
    }
	int res_max=0;
	FOR(i,0,n-1){
		if(r[i]==0){
			res_max=max(res_max,res[i]);
		}
	}
	cout<<n-res[n-1];
}