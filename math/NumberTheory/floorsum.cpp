// sigma(floor(a*i+b/c)) 0 <= i <= n
LL floor_sum(LL a, LL b, LL c, LL n) {
    if (a == 0) return (n+1)*(b/c);
    if (n == 0) return b/c;
    if (n < 0) return 0;
    LL res = (a/c)*n*(n+1)/2 + (n+1)*(b/c);
    a %= c;
    b %= c;
    LL m = (a*n+b)/c;
    return res + n*m - floor_sum(c, c-b-1, a, m-1);
}

// atcoder
using ll = long long;
ll floor_sum(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    ll y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}