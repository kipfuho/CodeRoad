// Nguyen Dinh Ut Biu 20215317
// Bai4.10: Seach engine

#include<iostream>
#include<math.h>
#include<sstream>
#include<vector>
#include<map>

using namespace std;

vector<map<string, int>> eachText; // number of times a string appear in each of the text
map<string, int> allText; // number of times a string appear in all text
map<string, double> notedIDF; // map to note the IDF of a string after calculate it
vector<int> maxf; // maxf[i] = maximum of eachText[i]
vector<int> res; // store result of each queries to print later
int n; // number of texts
int q; // number of queries

void prepare(){
	cin >> n;
	maxf.resize(n, 0);
	for(int i = 0; i < n; i++){
		string s; cin >> s;
		stringstream ss(s);
		map<string, int> tokens;
    	string token;
		while (std::getline(ss, token, ',')) {
        	tokens[token]++;
        	allText[token]++;
        	if(tokens[token] > maxf[i]) maxf[i] = tokens[token];
    	}
    	eachText.push_back(tokens);
	}
}

map<string, int> input(){
	string s; cin >> s;
	stringstream ss(s);
	map<string, int> tokens;
	string token;
	while (std::getline(ss, token, ',')) {
    	tokens[token]++;
	}
	return tokens;
}

// get TF of a string from index_th text
double TF(string t, int index){
	if (eachText[index][t] != 0){
		return 0.5 + 0.5*((double)eachText[index][t] / maxf[index]);
	}
	return 0;
}

// get IDF of a string
double IDF(string t){
	if(allText[t] != 0){
		int times = 0;
		for(int i = 0; i < n; i++){
			if(eachText[i][t] > 0) times++;
		}
		return log2((double)n/times);
	}
	return 0;
}

// get index of the Text with highest score
int getTextIndex(map<string, int> queryString){
	int index = 0;
	double currentScore = 0;
	for(int i = 0; i < n; i++){
		// calculate score of i_th text
		double score = 0;
		for(auto node:queryString){
			string t = node.first;
			int time = node.second;
			if(notedIDF[t] == 0){
				notedIDF[t] = IDF(t);
			}
			score += time*TF(t, i)*notedIDF[t];
		}
		// if this text score is greater, change index
		if(currentScore < score){
			index = i;
			currentScore = score;
		}
	}
	return index + 1;
}

int main(){
	prepare();
	cin >> q;
	while(q--){
		map<string, int> query = input();
		res.push_back(getTextIndex(query));
	}
	for(auto x:res) cout << x << " ";
}
