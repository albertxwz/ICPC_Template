// f是系数数组，处理完后，f表示：
// rev=1,是点表示法
// rev=-1,除N后是系数
// N=2^n
typedef complex<double> Comp; // 先导入头文件complex
void DFT(Comp *f, int N, int rev) {
	if (N == 1) return;
	for (int i = 0; i < N; ++i) tmp[i] = f[i];
	for (int i = 0; i < N; ++i)
		if (i%2) f[i/2+N/2] = tmp[i];
		else f[i/2] = tmp[i];
	Comp *g = f, *h = f + N/2;
	DFT(g, N/2, rev); DFT(h, N/2, rev);
    // c[N]=cos(2*pi/N), s[N]=sin(2*pi/N)
	Comp w(c[N], s[N]*rev), cur(1, 0);
	for (int k = 0; k < N/2; ++k) {
		tmp[k] = g[k] + cur*h[k];
		tmp[k+N/2] = g[k] - cur*h[k];
		cur *= w;
	}
	for (int i = 0; i < N; ++i) f[i] = tmp[i];
}
// Important!!!!
//for (N = 1; N < n+m; N <<= 1) {
//    s[N] = sin(2*pi/N);
//    c[N] = cos(2*pi/N);
//}
//s[N] = sin(2*pi/N);
//c[N] = cos(2*pi/N);
// no recursion
inline void change(Comp y[], int len) {
    int i, j, k;
    for (int i = 1, j = len / 2; i < len - 1; i++) {
        if (i < j) swap(y[i], y[j]);
        // 交换互为小标反转的元素，i<j 保证交换一次
        // i 做正常的 + 1，j 做反转类型的 + 1，始终保持 i 和 j 是反转的
        k = len / 2;
        while (j >= k) {
            j = j - k;
            k = k / 2;
        }
        if (j < k) j += k;
    }
}
/*
 * 做 FFT
 *len 必须是 2^k 形式
 *on == 1 时是 DFT，on == -1 时是 IDFT
 */
inline void fft(Comp y[], int len, int on) {
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        Comp wn(c[h], on*s[h]);
        for (int j = 0; j < len; j += h) {
            Comp w(1, 0);
            for (int k = j; k < j + h / 2; k++) {
                Comp u = y[k];
                Comp t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < len; ++i)
            y[i] = Comp(floor(y[i].real()/len+0.5), 0);
    }
}
