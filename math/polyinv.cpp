int tmp1[maxn*4+_], tmp2[maxn*4+_];
void polyinv(int *f, int *invf, int n) {
    if (n == 1) {
        invf[0] = powmod(f[0], modu-2);
        return;
    }
    polyinv(f, invf, (n+1)/2);
    int N = log(n*2);   // pay attention to the space!!!
    for (int i = 0; i < N; ++i) tmp1[i] = tmp2[i] = 0;
    for (int i = 0; i < n; ++i) tmp1[i] = f[i];
    for (int i = 0; i < (n+1)/2; ++i) tmp2[i] = invf[i];
    NTT::NTT(tmp1, N, 1);
    NTT::NTT(tmp2, N, 1);
    for (int i = 0; i < N; ++i) tmp1[i] = 1ll*tmp2[i]*(2ll - 1ll*tmp1[i]*tmp2[i]%modu)%modu;
    NTT::NTT(tmp1, N, -1);
    for (int i = 0; i < n; ++i)
        invf[i] = tmp1[i];
}