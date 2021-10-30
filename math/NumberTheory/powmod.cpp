LL powmod(LL a, LL b, LL modu) {
    LL res = 1;
    for (a %= modu; b; b >>= 1, a = a*a%modu)
        if (b&1) res = res * a % modu;
    return res;
}