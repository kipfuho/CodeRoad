// Nguyen Dinh Ut Biu 20215317
// Bai4.13: Dem xau con

#include<iostream>
#include<fstream>
#include<map>

using namespace std;

string filePath = "C:/Users/ctcak/Downloads/test13.txt";
string binaryString;
map<int, int> mp; // map store states appeared before and its times

// count valid substring
int numberOfSubsequencesStringWithEqual01(){
	int res = 0;
	int state = 0; // state is current number of bit 0 - number of bit 1
	mp[0] = 1; // begin value
	for(int i = 0; i < binaryString.size(); i++){
		if(binaryString[i] == '0') state++;
		else state--;
		
		// if state appear before, just add it to result and increase it
		// else we set it to 1
		if(mp[state]){
			res += mp[state];
			mp[state]++;
		}
		else{
			mp[state] = 1;
		}
	}
	return res;
}

int main(){
	// I use fstream to read input, cant paste all to cmd
	fstream file;
	file.open(filePath);
	file >> binaryString;
	cout << "Number of substring = " << numberOfSubsequencesStringWithEqual01();
	file.close();
}
