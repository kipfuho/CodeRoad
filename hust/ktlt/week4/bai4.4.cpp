// Nguyen Dinh Ut Biu 20215317
// Bài 4.4. Cho hai std::vector, hãy xóa het các phan tu chan, sap xep 
// giam dan các so trong ca 2 vector và tron lai thành mot vector cung 
// duoc sap xep giam dan.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
	// use iterator to scan and delete even numbers
    for(vector<int>::const_iterator it = a.begin(); it < a.end();){
        if((*it) % 2 == 0) a.erase(it);
        else ++it;
    }
}

void sort_decrease(vector<int> &a) {
    auto comp = [&](int x, int y){
        if(x > y) return true;
        return false;
    };
    sort(a.begin(), a.end(), comp);
}

// merge 2 vector using iterator
vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> temp;
    vector<int>::const_iterator it1 = a.begin();
    vector<int>::const_iterator it2 = b.begin();
    // compare value of 2 numbers and put it into new vector
    while(it1 < a.end() && it2 < b.end()){
        if((*it1) > (*it2)){
            temp.push_back(*it1);
            ++it1;
        }
        else{
            temp.push_back(*it2);
            ++it2;
        }
    }
    // add remaining numbers from the vectors
    for(;it1 < a.end(); it1++){
        temp.push_back(*it1);
    }
    for(;it2 < b.end(); it2++){
        temp.push_back(*it2);
    }
    return temp;
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
