// no solution = -1
int log_mod(int a, int b, int n) {
    LL m, v, e = 1, i;
    m = S; // S = int(sqrt(n) + 0.5)
    v = powmod(powmod(a, m), n-2);
    unordered_map<int, int> x;
    x[1] = 0;
    for (i = 1; i < m; ++i) {
        e = e*a %n;
        if (!x.count(e)) x[e] = i;
    }
    for (i = 0; i < m; ++i) {
        if (x.count(b)) return (LL)i*m + x[b];
        b = (LL)b*v%n;
    }
    return -1;
}