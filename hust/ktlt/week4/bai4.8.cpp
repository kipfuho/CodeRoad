// Nguyen Dinh Ut Biu 20215317
// Bài 4.8. Viet các hàm thuc hien các phép giao
// và hop cua hai tap hop mo duoc bieu dien bang map.

#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> c;
    // use 2 iterators to search through the map
    // if the first field of 2 elements is different we can just add to map c and advance our iterator
    // if the first field is equal, we add the element with higher second field 
    auto it1 = a.begin();
    auto it2 = b.begin();
    while(it1 != a.end() && it2 != b.end()){
        if(it1->first > it2->first){
            c.insert({it2->first, it2->second});
            it2++;
        }
        else if(it1->first < it2->first){
            c.insert({it1->first, it1->second});
            it1++;
        }
        else{
            if(it1->second > it2->second){
                c.insert({it1->first, it1->second});
                it1++;
                it2++;
            }
            else{
                c.insert({it2->first, it2->second});
                it1++;
                it2++;
            }
        }
    }
    // add remaining elements
    while(it1 != a.end()){
        c.insert({it1->first, it1->second});
        it1++;
    }
    while(it2 != b.end()){
        c.insert({it2->first, it2->second});
        it2++;
    }
    return c;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> c;
    // use 2 iterators to search through the map
    // if the first field of 2 elements is different we can just advance our iterator
    // if the first field is equal, we add the element with lower second field 
    auto it1 = a.begin();
    auto it2 = b.begin();
    while(it1 != a.end() && it2 != b.end()){
        if(it1->first > it2->first){
            it2++;
        }
        else if(it1->first < it2->first){
            it1++;
        }
        else{
            if(it1->second < it2->second){
                c.insert({it1->first, it1->second});
                it1++;
                it2++;
            }
            else{
                c.insert({it2->first, it2->second});
                it1++;
                it2++;
            }
        }
    }
    return c;
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
