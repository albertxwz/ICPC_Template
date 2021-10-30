// convolution for F(x) * G(x)
/* N = 2^k
 * init: f[i] = ... 0 <= i < N
 *       g[i] = ... 0 <= i < N
 * call :
 * NTT(f, N, 1);
 * NTT(g, N, 1);
 * for (int i = 0; i < N; ++i) f[i] = (LL)f[i]*g[i];
 * NTT(f, N, -1);
 */
inline void change(int y[], int len) {
    for (int i = 1, j = len / 2, k; i < len - 1; i++) {
        if (i < j) swap(y[i], y[j]);
        k = len / 2;
        while (j >= k) {
            j = j - k;
            k = k / 2;
        }
        if (j < k) j += k;
    }
}

// g is the primitive root of modu
inline void NTT(int y[], int len, int on) {
    int g = 3; // modu = 998244353 or 1004535809
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        LL wn = powmod(g, (modu-1)/h);
        if (on == -1) wn = powmod(wn, modu-2);
        for (int j = 0; j < len; j += h) {
            LL w = 1;
            for (int k = j; k < j + h / 2; k++) {
                LL u = y[k];
                LL t = (w * 1ll * y[k + h / 2])%modu;
                y[k] = (u + t)%modu;
                y[k + h / 2] = (u - t + modu)%modu;
                w = w * wn % modu;
            }
        }
    }
    if (on == -1) {
        LL INV = powmod(len, modu-2);
        for (int i = 0; i < len; ++i)
            y[i] = 1ll * y[i] * INV % modu;
    }
}