template <typename T>
struct hungarian {  // km
    int n;
    vector<int> matchx;  // �󼯺϶�Ӧ��ƥ���
    vector<int> matchy;  // �Ҽ��϶�Ӧ��ƥ���
    vector<int> pre;     // �����Ҽ��ϵ����
    vector<bool> visx;   // �ݷ����� ��
    vector<bool> visy;   // �ݷ����� ��
    vector<T> lx;
    vector<T> ly;
    vector<vector<T> > g;
    vector<T> slack;
    T inf;
    T res;
    queue<int> q;
    int org_n;
    int org_m;

    hungarian(int _n, int _m) {
        org_n = _n;
        org_m = _m;
        n = max(_n, _m);
        inf = numeric_limits<T>::max();
        res = 0;
        g = vector<vector<T> >(n, vector<T>(n));
        matchx = vector<int>(n, -1);
        matchy = vector<int>(n, -1);
        pre = vector<int>(n);
        visx = vector<bool>(n);
        visy = vector<bool>(n);
        lx = vector<T>(n, -inf);
        ly = vector<T>(n);
        slack = vector<T>(n);
    }

    void addEdge(int u, int v, T w) {
        g[u][v] = max(w, 0);  // ��ֵ�����粻ƥ�� �����Ϊ0��Ӱ��
    }

    bool check(int v) {
        visy[v] = true;
        if (matchy[v] != -1) {
            q.push(matchy[v]);
            visx[matchy[v]] = true;  // in S
            return false;
        }
        // �ҵ��µ�δƥ��� ����ƥ��� pre �����¼��"��ƥ���"����֮�����ĵ�
        while (v != -1) {
            matchy[v] = pre[v];
            swap(v, matchx[pre[v]]);
        }
        return true;
    }

    void bfs(int i) {
        while (!q.empty()) {
            q.pop();
        }
        q.push(i);
        visx[i] = true;
        while (true) {
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v = 0; v < n; v++) {
                    if (!visy[v]) {
                        T delta = lx[u] + ly[v] - g[u][v];
                        if (slack[v] >= delta) {
                            pre[v] = u;
                            if (delta) {
                                slack[v] = delta;
                            } else if (check(v)) {  // delta=0 �����л�����������ͼ ������·
                                // �ҵ���return �ؽ�������
                                return;
                            }
                        }
                    }
                }
            }
            // û������· �޸Ķ���
            T a = inf;
            for (int j = 0; j < n; j++) {
                if (!visy[j]) {
                    a = min(a, slack[j]);
                }
            }
            for (int j = 0; j < n; j++) {
                if (visx[j]) {  // S
                    lx[j] -= a;
                }
                if (visy[j]) {  // T
                    ly[j] += a;
                } else {  // T'
                    slack[j] -= a;
                }
            }
            for (int j = 0; j < n; j++) {
                if (!visy[j] && slack[j] == 0 && check(j)) {
                    return;
                }
            }
        }
    }

    void solve() {
        // ��ʼ����
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                lx[i] = max(lx[i], g[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            fill(slack.begin(), slack.end(), inf);
            fill(visx.begin(), visx.end(), false);
            fill(visy.begin(), visy.end(), false);
            bfs(i);
        }

        // custom
        //for (int i = 0; i < n; ++i) res -= g[i][matchx[i]];
        for (int i = 0; i < n; i++) {
            if (g[i][matchx[i]] > 0) {
                res += g[i][matchx[i]];
            } else {
                matchx[i] = -1;
            }
        }
        cout << res << "\n";
        for (int i = 0; i < org_n; i++) {
            cout << matchx[i] + 1 << " ";
        }
        cout << "\n";
    }
};
