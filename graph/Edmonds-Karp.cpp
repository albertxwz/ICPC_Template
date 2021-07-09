queue<int> Q;
int imp[maxn], p[maxn];

// 不断寻找增广路增广

int MaxFlow(int s, int t) {
	int res = 0;
	for (;;) {
		memset(imp, 0, sizeof(imp));
		while (!Q.empty()) Q.pop();
		Q.push(s);
		imp[s] = inf;
		while (!Q.empty()) {
			int x = Q.front(); Q.pop();
			for (int i = 0; i < g[x].size(); ++i) {
				Edge &e = edges[g[x][i]];
				if (!imp[e.to] && e.cap > e.flow) {
					p[e.to] = g[x][i];
					imp[e.to] = min(imp[x], e.cap-e.flow);
					Q.push(e.to);
				}
			}
			if (imp[t]) break;
		}
		if (!imp[t]) break;
		for (int u = t; u != s; u = edges[p[u]].from) {
			edges[p[u]].flow += imp[t];
			edges[p[u]^1].flow -= imp[t];
		}
		res += imp[t];
	}
	return res;
}