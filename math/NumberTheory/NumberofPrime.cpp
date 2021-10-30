LL n;
vector<LL> p, val;
bool vis[maxn+_];
LL f[maxn+_];
int id1[maxn+_], id2[maxn+_];

inline int getid(LL k) {
    if (k <= n/k) return id1[k];
    return id2[n/k];
}

int main() {
    scanf("%lld", &n);
    memset(vis, 0, sizeof(vis));
    int m = sqrt(n);
    for (LL i = 2; i <= m; ++i) {
        if (!vis[i]) p.PB(i);
        for (int j = 0; j < SZ(p) && i*p[j] <= m; ++j) {
            vis[i*p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
    for (LL L = 1, R; L <= n; L = R+1) {
        R = n / (n/L);
        val.PB(R);
        if (R <= n/R) id1[R] = SZ(val)-1;
        else id2[n/R] = SZ(val)-1;
    }
    for (int i = 0; i < SZ(val); ++i) f[i] = val[i] - val[i]/2 - (val[i] == 1);
    for (int i = 1; i < SZ(p); ++i)
        for (int j = SZ(val)-1; j >= 0 && val[j] >= p[i]*p[i]; --j)
            f[j] += - f[getid(val[j]/p[i])] + i;
    printf("%lld\n", f[SZ(val)-1]);
    return 0;
}