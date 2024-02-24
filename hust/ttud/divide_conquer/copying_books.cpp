/* https://codeforces.com/group/Ir5CI6f3FD/contest/273369/problem/D
D. 04. BOOKS1
time limit per test 1 second
memory limit per test 256 megabytes
input standard input
output standard output
Before the invention of book-printing, it was very hard to make a copy of a book. All the contents 
had to be re-written by hand by so called scribers. The scriber had been given a book and after several 
months he finished its copy. One of the most famous scribers lived in the 15th century and his name was 
Xaverius Endricus Remius Ontius Xendrianus (Xerox). Anyway, the work was very annoying and boring. And 
the only way to speed it up was to hire more scribers.

Once upon a time, there was a theater ensemble that wanted to play famous Antique Tragedies. The scripts 
of these plays were divided into many books and actors needed more copies of them, of course. So they hired 
many scribers to make copies of these books. Imagine you have m books (numbered 1,2,…,m) that may have 
different number of pages (p1,p2,…,pm) and you want to make one copy of each of them. Your task is to 
divide these books among k scribes, k≤m. Each book can be assigned to a single scriber only, and every 
scriber must get a continuous sequence of books. That means, there exists an increasing succession of 
numbers 0=b0<b1<b2,…<bk−1≤bk=m such that i-th scriber gets a sequence of books with numbers between bi−1+1 and bi. 
The time needed to make a copy of all the books is determined by the scriber who was assigned the most work. 
Therefore, our goal is to minimize the maximum number of pages assigned to a single scriber. Your task is to 
find the optimal assignment.

Input
The input consists of N cases (equal to about 200). The first line of the input contains only 
positive integer N. Then follow the cases. Each case consists of exactly two lines. At the first line, there are 
two integers m and k, 1≤k≤m≤500. At the second line, there are integers p1,p2,…,pm separated by spaces. All 
these values are positive and less than 10000000.

Output
For each case, print exactly one line. The line must contain the input succession p1,p2,…,pm divided into exactly 
k parts such that the maximum sum of a single part should be as small as possible. Use the slash character ('/') to 
separate the parts. There must be exactly one space character between any two successive numbers and between the number and the slash.

If there is more than one solution, print the one that minimizes the work assigned to the first scriber, then to the second 
scriber etc. But each scriber must be assigned at least one book.

Example
input
2
9 3
100 200 300 400 500 600 700 800 900
5 4
100 100 100 100 100
output
100 200 300 400 500 / 600 700 / 800 900 
100 / 100 / 100 / 100 100 
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int t; cin >> t;
    int n, k, valid, curr_scriber, last;
    long long left, mid, right, best;
    vector<long long> arr(501), prefix_sum(501), save_point(501);
    prefix_sum[0] = 0;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        }
        left = prefix_sum[n] - prefix_sum[n - 1];
        right = prefix_sum[n];
        best = left;
        while(left <= right){
            mid = (left + right) / 2;
            last = n;
            valid = 1;
            curr_scriber = k - 1;
            //cout << endl << mid << endl;
            for(int i = n; i > 0; i--){
                if(prefix_sum[last] - prefix_sum[i - 1] > mid){
                    if(i == last){
                        valid = 0;
                        break;
                    }
                    last = i++;
                    curr_scriber--;
                    if(curr_scriber < 0) break;
                }
                else if(i - 1 == curr_scriber){
                    for(int j = i; j > 0; j--){
                        if(prefix_sum[j] - prefix_sum[j - 1] > mid){
                            valid = 0;
                            break;
                        }
                    }
                    curr_scriber = 0;
                    break;
                }
            }
            if(curr_scriber < 0){
                valid = 0;
                //cout << "less";
            }
            if(valid){
                if(curr_scriber == 0){
                    best = mid;
                }
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        //cout << best << endl;
        last = n;
        k--;
        valid = 1;
        for(int i = n; i > 1; i--){
            if(prefix_sum[last] - prefix_sum[i - 1] > best){
                last = i++;
                save_point[valid++] = i;
                k--;
            }
            else if(i - 1 == k){
                save_point[valid++] = i;
                last = i - 1;
                k--;
            }
        }
        k = 1;
        for(last = valid - 1; last > 0; last--){
            for(; k < save_point[last]; k++) cout << arr[k] << " ";
            cout << "/ ";
        }
        for(; k <= n; k++) cout << arr[k] << " ";
        cout << endl;
    }
    return 0;
}