#include<bits/stdc++.h>
#define ll long long
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n;
int arr[1000001];
long long sum[1000001];
int l1,l2;

// put sol1 here
void sol(){
    int n, m; cin >> n >> m;
    vector<int> maxl(n + 2), minl(n + 2), maxr(n + 2), minr(n + 2);
    string s; cin >> s;

    maxl[n + 1] = minl[n + 1] = 0;
    maxl[0] = minl[0] = 0;
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == '+'){
            sum1++;
            sum2 = 0;
        }
        else{
            sum1 = 0;
            sum2--;
        }
        maxl[i] = max(maxl[i - 1] - 1, sum1);
        minl[i] = min(minl[i - 1] + 1, sum2);
    }
    maxr[n + 1] = minr[n + 1] = 0;
    maxr[0] = minr[0] = 0;
    sum1 = 0, sum2 = 0;
    for(int i = n; i > 0; i--){
        if(s[i - 1] == '+'){
            sum1++;
            sum2 = 0;
        }
        else{
            sum1 = 0;
            sum2--;
        }
        maxr[i] = max(maxr[i + 1] - 1, sum1);
        minr[i] = min(minr[i + 1] + 1, sum2);
    }

    while(m--){
        int l, r; cin >> l >> r;
        int best = max(maxr[r + 1] + maxl[l - 1], -(minr[r + 1] + minl[l - 1]));
        cout << best + 1 << endl;
    }
}

void sol1(){
    int n, m;
    cin >> n >> m;
    cout << m << n;
}

void sol2(){
    int n; cin >> n;
        int temp, prev = 0;
        long long total = 0;
        for(int i = 0; i < n; i++){
            cin >> temp;
            if(temp >= prev){
                prev = temp;
                continue;
            }
            else{
                int coeff = log2((prev - 1) / temp) + 1;
                total += coeff;
                prev = temp*pow(2, coeff);
            }
        }
        cout << total << endl;
}

/*
ProblemE.FibonacciWords
InputFileName: stdin
OutputFileName: stdout
TimeLimit: 1s
MemoryLimit: 256MB

The Fibonacci word sequence of bit strings is defined as:
F(n) =  /   0                   if n = 0
        \   1                   if n = 1
         \  F(n-1) + F(n-2)     if n >= 2

Here denotes concatenation of strings.The first few elements are:
n   F(n)
0   0
1   1
2   10
3   101
4   10110
5   10110101
6   1011010110110
7   101101011011010110101
8   1011010110110101101011011010110110
9   1011010110110101101011011010110110101101011011010110101

Given a bit pattern p and a number n,how often does p occur in F(n)?

Input
The first line of each test case contains the integern(0 <= n <= 100). The second line contains the bit
pattern p.The pattern p is nonempty and has a length of at most 100 000 characters.
Output
For each test case, display its case number followed by the number of occurrences of the bit pattern p in
F(n). Occurrences may overlap. The number of occurrences will be less than 2^63.

Example:
input:
6
10
output:
Case 1: 5
*/

/*
#include<bits/stdc++.h>


using namespace std;

int n;

*/

string pattern;
vector<long long> fibo(101, 0), overlap(101, 0);
vector<string> fw(101); // store fibonacci word

long long count_appear_kmp(string text, string pattern){
    int text_size = text.size(), pattern_size = pattern.size();
    // calculate lps - longest prefix suffix
    int lps[pattern_size], i = 1, j = 0;
    lps[0] = 0;
    while(i < pattern_size){
        if(pattern[i] == pattern[j]) lps[i++] = ++j;
        else{
            if(j != 0) j = lps[j - 1];
            else lps[i++] = 0;
        }
    }
    // for(i = 0; i < m; i++) cout << lps[i] << " ";

    // count time pattern appear in text
    long long count = 0;
    i = 0; j = 0;
    while((text_size - i) >= (pattern_size - j)){
        if(pattern[j] == text[i]){
            j++;
            i++;
            if (j == pattern_size){
                count++;
                j = lps[j - 1];
            }
        }
        else{
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return count;
}

int create_fw(string pattern){
    int p_size = pattern.size();
    // cout << p_size << endl;
    // trivial case for small p :D
    if(p_size == 1){
        overlap[0] = 0;
        overlap[1] = 0;
        if(pattern == "1") fibo[1] = 1;
        else fibo[0] = 1;
        return 2;
    }
    if(p_size == 2){
        overlap[0] = 0;
        overlap[1] = count_appear_kmp("11", pattern);
        overlap[2] = count_appear_kmp("01", pattern);
        overlap[3] = overlap[1];
        fibo[2] = count_appear_kmp("10", pattern);
        fibo[3] = count_appear_kmp("101", pattern);
        return 4;
    }
    // common case 
    // find first fw that is equal or bigger than pattern / 2
    fibo[0] = 1; fibo[1] = 1;
    fw[0] = "0"; fw[1] = "1";
    int i;
    for(i = 2; i <= n; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fw[i] = fw[i - 1] + fw[i - 2];
        if(2*fibo[i] >= p_size) break;
    }
    // this mean pattern is bigger than n_th fibo word
    if(i >= n){
        fibo[n] = 0;
        return n+1;
    }
    
    // create 2 more fw fw(i + 1) and fw(i + 2), from fw(i + 3) it has the same pattern to count toward result
    fw[i + 1] = fw[i] + fw[i - 1];
    fibo[i + 1] = fibo[i] + fibo[i - 1];
    if(fibo[i + 1] <= p_size){
        fw[i + 2] = fw[i + 1] + fw[i];
        fw[i + 3] = fw[i + 2] + fw[i + 1];
        fibo[i + 1] = count_appear_kmp(fw[i + 1], pattern);
        fibo[i + 2] = count_appear_kmp(fw[i + 2], pattern);
        fibo[i + 3] = count_appear_kmp(fw[i + 3], pattern);
        overlap[i] = count_appear_kmp(fw[i] + fw[i], pattern);
        overlap[i + 1] = count_appear_kmp(fw[i + 1] + fw[i + 1], pattern) - 2*fibo[i + 1];
        if(overlap[i] != 0) overlap[i + 2] = overlap[i];
        else overlap[i + 2] = count_appear_kmp(fw[i + 2] + fw[i + 2], pattern) - 2*fibo[i + 2];
        if(overlap[i + 1] != 0) overlap[i + 3] = overlap[i + 1];
        else overlap[i + 3] = count_appear_kmp(fw[i + 3] + fw[i + 3], pattern) - 2*fibo[i + 3];
        return i + 4;
    }
    else{
        fw[i + 2] = fw[i + 1] + fw[i];
        fibo[i + 1] = count_appear_kmp(fw[i + 1], pattern);
        fibo[i + 2] = count_appear_kmp(fw[i + 2], pattern);
        overlap[i] = count_appear_kmp(fw[i] + fw[i], pattern);
        overlap[i + 1] = count_appear_kmp(fw[i + 1] + fw[i + 1], pattern) - 2*fibo[i + 1];
        if(overlap[i] != 0) overlap[i + 2] = overlap[i];
        else overlap[i + 2] = count_appear_kmp(fw[i + 2] + fw[i + 2], pattern) - 2*fibo[i + 2];
        return i + 3;
    }
    
    return 0;
}

long long calculate_total_occurences(int start, int p_size){
    // trivial case p = "0" or p = "1"
    if(p_size == 1){
        fibo[start] = fibo[start - 1] + fibo[start - 2];
        start++;
    }
    for(int i = start; i <= n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2] + overlap[i-3];
        overlap[i] = overlap[i-2];
    }
    return fibo[n];
}

bool check_size(int p_size){
    if(p_size == 1 && n >= 1) return true;
    int a1 = 1, a2 = 1, a3;
    for(int i = 2; i <= n; i++){
        a3 = a1 + a2;
        if(a3 > p_size) return true;
        swap(a1, a2);
        swap(a2, a3);
    }
    return false;
}

int sol3(){
    cin >> n >> pattern;
    if(check_size(pattern.size())){
        int start = create_fw(pattern);
        cout << "Case 1: " << calculate_total_occurences(start, pattern.size()) << endl;
    }
    else{
        cout << "Case 1: 0";
    }
    
    //for(int i = 0; i <= n; i++) cout << fibo[i] << " ";
    //cout << endl;
    //for(int i = 0; i <= n; i++) cout << overlap[i] << " ";
    return 0;
}

bool cmp(pair<pair<int, int>, double> p2, pair<pair<int, int>, double> p1){
    if(p2.second > p1.second) return true;
    else return false;
}

int sol4(){_
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        vector<pair<pair<int, long long>, double>> arr;
        vector<long long> value(n+1);
        long long temp;
        for(int i = 1; i <= n; i++){
            cin >> temp;
            double score = temp / i*c;
            arr.push_back({{i, temp}, score});
            value[i] = temp;
        }
        
        //cout << "still fine\n";
        sort(arr.begin(), arr.end(), cmp);
        pair<pair<int, long long>, double> start_node = arr[0];
        long long sum = start_node.first.second;
        bool valid = true;
        vector<int> visited(n + 1, 0);
        visited[start_node.first.first] = 1;
        
        //cout << start_node.second << endl;
        if(start_node.second < 1){
            pair<pair<int, long long>, double> second_node = arr[1];
            if(sum + second_node.first.second < start_node.first.first*second_node.first.first*c) valid = false;
            else{
                sum += second_node.first.second;
                visited[second_node.first.first] = 1;
            }
        }

        /*
        int start_node_floor_score = n;
        if(start_node_floor_score > floor(start_node.second)) start_node_floor_score = floor(start_node.second);
        for(int i = 1; i <= start_node_floor_score; i++){
            if(i == start_node.first.first) continue;
            sum += value[i];
            visited[i] = 1;
        }
        */

        for(int i = 0; i < n; i++){
            pair<pair<int, long long>, double> cur_node = arr[i];
            if(visited[cur_node.first.first]) continue;
            if(sum + cur_node.first.second >= cur_node.first.first*c){
                sum += cur_node.first.second;
            }
            else{
                valid = false;
                break;
            }
        }
        
        if(valid) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}



int sol5(){_
     cin>>n>>l1>>l2; 
     for (int i=1; i<=n;i++){
        cin>>arr[i];
     }
     for (int i=1; i<= l1; i++){
        sum[i]= arr[i];
     }
     long long Result =0;
     deque<int> de;
    // de.push_back(0);
     for (int i = l1+1; i <= n; i ++){
         while (!de.empty() && i- de.front() > l2){
            de.pop_front();
         }
         while(!de.empty()  && sum[i-l1] > sum[de.back()]){             
            de.pop_back();
         }
         de.push_back(i-l1);
         sum[i]= sum[de.front()] + arr[i];

     }
     for (int  i =n-l1; i<=n ;i++){
         Result = max(Result,sum[i]);     
      }
    cout<<Result;
    return 0;
}

int main(int argc, char** argv) {
    freopen("input.inp", "r", stdin);
    freopen("sol1.out", "w", stdout);
    sol5();
}