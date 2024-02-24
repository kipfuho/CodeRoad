// Nguyen Dinh Ut Biu
// Bài 4.7. Viet các hàm thuc hien các phép giao và hop cua 
// hai tap hop duoc bieu dien bang set

#include <iostream>
#include <set>

using namespace std;

template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
	// set set c = set a, then insert each 
	// element from set b to set c
    set<T> c = a;
    for(auto& x:b) c.insert(x);
    return c;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> c;
    // find each of element of set b in set a
    // if it present in set a, we add it to set c
    for(auto& x:b){
        if(a.find(x) != a.end()){
            c.insert(x);
        }
    }
    return c;
}

template<class T>
void print_set(const std::set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);
 
    std::cout << "Union: "; print_set(c);
    std::cout << "Intersection: "; print_set(d);

    return 0;
}
