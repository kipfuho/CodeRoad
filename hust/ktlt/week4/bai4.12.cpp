// Nguyen Dinh Ut Biu 20215317
// Bai4.12: Luoc do

#include<iostream>
#include<vector>
#include<stack>
#include<fstream>

using namespace std; 

int n;
vector<long long> heights;
string filePath = "C:/Users/ctcak/Downloads/test12.txt";

// Use fstream to get input, i can't paste all input into cmd? dont know why
void input(){
	fstream file;
	file.open(filePath);
	file >> n;
	for(int i = 0; i < n; i++){
		long long h; file >> h;
		heights.push_back(h);
	}
	file.close();
}

long long findMaxArea() {
    stack<int> s; // use stack to solve 
    long long maxArea = 0;
    int i = 0;
    
    while(i < n){
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i);
            i++;
        }
		else{
            int topIndex = s.top();
            s.pop();
            long long area = heights[topIndex] * (s.empty() ? i : (i - s.top() - 1));
            maxArea = max(maxArea, area);
        }
    }

    while(!s.empty()){
        int topIndex = s.top();
        s.pop();
        long long area = heights[topIndex] * (s.empty() ? i : (i - s.top() - 1));
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
	input();
    cout << "Max area = " << findMaxArea() << endl;
    
}
