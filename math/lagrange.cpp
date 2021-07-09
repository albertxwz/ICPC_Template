#include <cstdio>

const int maxn = 2010;
using ll = long long;
ll mod = 998244353;
ll n, k, x[maxn], y[maxn], ans, s1, s2;

ll powmod(ll x, ll n) {
  ll ret = 1ll;
  while (n) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

ll inv(ll x) { return powmod(x, mod - 2); }

int main() {
  scanf("%lld%lld", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", x + i, y + i);
  for (int i = 1; i <= n; i++) {
    s1 = y[i] % mod;
    s2 = 1ll;
    for (int j = 1; j <= n; j++)
      if (i != j) s1 = s1 * (k - x[j]) % mod, s2 = s2 * (x[i] - x[j]) % mod;
    ans += s1 * inv(s2) % mod;
  }
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}

// Lagrange interpolation O(n^2)
// n is the highest degree of polynomial
// return f(x) where x = n
// x[i] = i-1, x[i] sorted from low to high
LL lagrange(LL n, LL *x, LL *y, int m) {
    LL res = 0;
    for (int i = 0; i < m; ++i) {
        LL tmp = 1;
        for (int j = 0; j < m; ++j)
            if (i != j) {
                tmp = (n - x[j]) % modu * inv[abs(x[i] - x[j])] % modu * tmp % modu;
            }
        if ((m-i-1)%2) tmp *= -1;
        res = (res + tmp*y[i]%modu) %modu;
    }
    return res;
}
