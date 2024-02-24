/*
Description
Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>

Note that: the total number of people in the family is less than or equal to 10
4
Input
Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
Output
Each line is the result of a corresponding query.
Example
Input
Peter Newman
Michael Thomas
John David
Paul Mark
Stephan Mark
Pierre Thomas
Mark Newman
Bill David
David Newman
Thomas Mark
***
descendants Newman
descendants Mark
descendants David
generation Mark
***
Output
10
5
2
2
*/

#include<bits/stdc++.h>
#define FOR(i, l, r) for(int i = l; i <= r; i++)

using namespace std;

int const nmax=10e4+1;
vector<int> g[nmax];
string str[nmax];
string Order[nmax];

int num[nmax], child[nmax], gen[nmax];
int timeDFS;

void split_string(string s){
    char *p = new char [s.size() + 1];
    strcpy(p, s.c_str());
    char *pch = strtok(p, " ");
    int i = 0;
    while(pch != 0){
        str[i++] = pch;
        pch = strtok(NULL, " ");
    }
}

int indexing(string s){
    FOR(i, 1, nmax - 1){
        if(Order[i].size() == 0){
            Order[i] = s;
            return i;
        }
        if(Order[i] == s) return i;
    }
    return -1;
}

void dfs(int u, int pre){
    num[u] = ++timeDFS;
    for(auto x : g[u]){
        if(num[x] == 0){
            child[u] ++;
            dfs(x, u);
            child[u] += child[x];
            gen[u] = max(gen[u], gen[x] + 1);
        }
    }
}

void sol(){
    timeDFS = 0;
    FOR(i, 1, nmax - 1){
        num[i] = child[i] = gen[i] = 0;
    }
    while(true){
        string s;
        getline(cin, s);
        if(s == "***") break;
        split_string(s);
        g[indexing(str[1])].push_back(indexing(str[0]));
    }
    FOR(i, 1, nmax - 1){
        if(num[i] == 0) dfs(i, 0);
    }
    while(true){
        string s;
        getline(cin, s);
        if(s == "***") break;
        split_string(s);
        if(str[0] == "descendants"){
            cout << child[indexing(str[1])] << endl;
        }
        if(str[0] == "generation"){
            cout << gen[indexing(str[1])] << endl;
        }
    }
}

int main(){
    sol();
}