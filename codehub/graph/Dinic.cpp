struct Edge {
	int from, to, cap, flow;
	Edge(int from, int to=0, int cap=0, int flow=0):
		from(from), to(to), cap(cap), flow(flow) {}
};

vector<Edge> edges;
vector<int> g[maxn];
int d[maxn], cur[maxn];

void addedge(int u, int v, int cap) {
	edges.push_back(Edge(v, cap));
	g[u].push_back(edges.size()-1);
	edges.push_back(Edge(u, 0));
	g[v].push_back(edges.size()-1);
}

/*
 *	时间复杂度: O(n^2*m)
 *	对于特殊的图，所有容量为1的：O(min(n^0.67, m^0.5)*m)
 *				二分图最大匹配：O(n^0.5*m)
 * 
 */

bool BFS(int s, int t) {
	memset(d, -1, sizeof(d));
	queue<int> Q;
	Q.push(s);
	d[s] = 0;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (int i = 0; i < g[x].size(); ++i) {
			Edge &e = edges[g[x][i]];
			if (d[e.to] == -1 && e.cap > e.flow) {
				d[e.to] = d[x] + 1;
				Q.push(e.to);
			}
		}
	}
	return d[t] > -1;
}

int DFS(int x, int a, int t) {
	if (x == t || a == 0) return a;
	int flow = 0, f;
	for (int &i = cur[x]; i < g[x].size(); ++i) {
		Edge &e = edges[g[x][i]];
		if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow), t)) > 0) {
			flow += f;
			e.flow += f;
			edges[g[x][i]^1].flow -= f;
			a -= f;
			if (a == 0) break;
		}
	}
	return flow;
}

int MaxFlow(int s, int t) {
	int res = 0;
	while (BFS(s, t)) {
		for (int i = 0; i <= n; ++i) cur[i] = 0;
		res += DFS(s, inf, t);
	}
	return res;
}