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