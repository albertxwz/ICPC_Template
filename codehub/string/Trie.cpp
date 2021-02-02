struct Trie {
	vector<int> ch[26], val; // val可以存储节点的信息
	Trie() {                  // 这里表示字符串的编号
		newNode();
	}

	void newNode() {
		for (int i = 0; i < 26; ++i)
			ch[i].push_back(-1);
		val.push_back(-1);
	}

	void insert(const string &str, int v) {
		int i, u;
		for (i = 0, u = 0; i < str.length(); ++i) {
			int c = str[i]-'a';
			if (ch[c][u] == -1) {
				newNode();
				ch[c][u] = ch[c].size()-1;
			}
			u = ch[c][u];
		}
		val[u] = v;
	}

	int find(const string &str) {
		int i, u;
		for (i = 0, u = 0; i < str.length(); ++i) {
			int c = str[i] - 'a';
			if (ch[c][u] == -1) return -1;
			u = ch[c][u];
		}
		return val[u];
	}

};
