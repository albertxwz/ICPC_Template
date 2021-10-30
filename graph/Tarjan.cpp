/*
 * 点双连通分量，割点，桥
 */

struct Edge {
    int x, y;
};

vector<int> g[maxn+_];
int n, m, pre[maxn+_], low[maxn+_], dfs_clock, cutv, cute, s1, s2;
bool iscut[maxn+_];
stack<Edge> S;

void dfs(int x, int fa) {
    pre[x] = low[x] = ++dfs_clock;
    int child = 0;
    for (int y: g[x]) {
        if (!pre[y]) {
            child++;
            S.push((Edge){x, y});
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] > pre[x]) // bridge
                cute++;
            if (low[y] >= pre[x]) { // cut vertex
                iscut[x] = 1;
                int tmp = 0;
                for (;;) {      // pop the edges of one component
                    tmp++;
                    Edge e = S.top();
                    S.pop();
                    if (e.x == x && e.y == y) break;
                };
            }
        }
        else if (y != fa && pre[y] < pre[x]) {
            S.push(Edge{x, y});
            low[x] = min(low[x], pre[y]);
        }
    }
    if (child == 1 && fa == 0) iscut[x] = 0;
}

