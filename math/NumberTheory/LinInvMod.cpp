const int maxn = 2e5 + 5;
const int modu = 1e9 + 7;
long long inv[maxn]; // k在模modu的意义下的逆元是inv[k]
inv[1] = 1;
for (int i = 2; i < maxn; ++i)
    inv[i] = (modu - (modu/i))*inv[modu%i]%modu;