#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;

// trim from start (in place)
inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

class Node {
    public:
    string tagName;
    map<string, string> attrs;
    vector<Node*> childs;
    
    Node(string tag) {
      tagName = tag;
    }
    
    Node(string name, vector<pair<string, string>> attr) {
        tagName = name;
        for(auto x : attr) attrs[x.first] = x.second;
    }
    
    void addChild(Node* child) {
        childs.push_back(child);
    }
};

Node* createNode(string s) {
    //if(s[0] != '<') return nullptr;
    //if(s[1] == '/') return nullptr;
    string tagname = "";
    vector<pair<string, string>> attr;
    int len = s.size(), i = 1;
    for(; i < len && s[i] != ' '; i++) {
        tagname += s[i];
    }
    string attrName = "", attrValue = "";
    bool getAttrName = true;
    while(s[i] != '>') {
        if(getAttrName) {
            if(s[i] == '=') {
                getAttrName = false;
                while(s[i] != '"') i++;
            }
            else attrName += s[i];
        }
        else {
            if(s[i] == '"') {
                getAttrName = true;
                ltrim(attrName);
                rtrim(attrName);
                attr.push_back({attrName, attrValue});
                attrName = "", attrValue = "";
            }
            else attrValue += s[i];
        }
        i++;
    }
    return new Node(tagname, attr);
}

Node* findNode(Node* node, string tag) {
    if(!node) return nullptr;
    if(node->tagName == tag) return node;
    for(Node* ch : node->childs) {
        Node* chch = findNode(ch, tag);
        if(chch != nullptr) return chch;
    }
    return nullptr;
}

void addNode(Node* root, string parentTag, Node* child) {
    Node* parent = findNode(root, parentTag);
    if(parent) parent->addChild(child);
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q; cin >> n >> q;
    cin.ignore();
    Node* root = new Node("root");
    stack<string> tagSt;
    tagSt.push("root");
    
    for(int i = 0; i < n; i++) {
        string s; getline(cin, s);
        //ltrim(s), rtrim(s);
        if(s[1] == '/') {
            tagSt.pop();
            continue;
        }
        Node* newNode = createNode(s);
        addNode(root, tagSt.top(), newNode);
        tagSt.push(newNode->tagName);
    }
    while(q--) {
        string s, tag = "";
        getline(cin, s);
        int i = 0, len = s.size();
        Node* curNode = root;
        while(i < len) {
            if(s[i] == '.' || s[i] == '~') {
                curNode = findNode(curNode, tag);
                tag = "";
            }
            else {
                tag += s[i];
            }
            i++;
        }
        if(curNode && curNode->attrs[tag].size() > 0) cout << curNode->attrs[tag] << '\n';
        else cout << "Not Found!\n";
    }
    return 0;
}
