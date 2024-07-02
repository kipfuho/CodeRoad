struct Node {
	vector<int> chr;
	bool end;
	
	Node() {
		chr.resize(26, 0);
		end = false;
	}
};

struct trie {
	vector<Node> nodes;

	trie() {
		nodes.push_back(Node());
	}
		
	void add(string s) {
		int pos = 0;
		for(char c : s) {
			if(nodes[pos].chr[c - 'a']) {
				pos = nodes[pos].chr[c - 'a'];
			}
			else {
				nodes[pos].chr[c - 'a'] = nodes.size();
				pos = nodes.size();
				nodes.push_back(Node());
			}
		}
		nodes[pos].end = true;
	}

	// find shortest root for s
	string find(string s) {
			string root = "";
			int pos = 0;
			for(char c : s) {
				if(nodes[pos].chr[c - 'a']) {
					root += string(1, c);
					pos = nodes[pos].chr[c - 'a'];
					if(nodes[pos].end) break;
				}
				else break;
			}
			if(nodes[pos].end) return root;
			else return s;
	}
};