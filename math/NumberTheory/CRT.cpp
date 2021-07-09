// x mod a[i] == b[i] mod a[i]
// gcd(a[i], a[j]) == 1 (i != j)
LL crt(LL *a, LL *b, int n) {
    LL res = 0;
    LL tota = 1;
    for (int i = 0; i < n; ++i) tota *= a[i];
    for (int i = 0; i < n; ++i) {
        LL m = tota / a[i];
        LL r, tmp;
        exgcd(m, a[i], r, tmp);
        r = (r%a[i]+a[i])%a[i];
        res = (res + b[i]*m%tota*r%tota) % tota;
    }
    return res;
}

// extended version
// x mod a[i] == b[i] mod a[i]
// gcd(a[i], a[j]) >= 1
LL excrt(LL *a, LL *b, int n) {
    for (int i = 1; i < n; ++i) {
        LL x, y;
        LL g = exgcd(a[0], a[i], x, y);
        x %= a[i];
        a[0] /= g;
        x = ((__int128)(b[i] - b[0])%a[i]*x%a[i] + a[i])%a[i];
        LL lcm = a[0]*a[i];
        b[0] = ((__int128)x*a[0] + b[0])%lcm;
        a[0] = lcm;
    }
    return b[0];
}
