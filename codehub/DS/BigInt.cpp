struct BigInt {
    LL a[20];
    int len;
    BigInt() { memset(a, 0, sizeof(a)); len = 1; }
    BigInt(string sint) {
        BigInt();
        len = sint.length()/nbit;
        reverse(sint.begin(), sint.end());
        for (int i = 0; i < len; ++i) {
            a[i] = 0;
            for (int j = nbit-1; j >= 0; --j)
                a[i] = a[i]*10 + sint[i*nbit+j] - '0';
        }
        DebugP(sint);
        if (sint.length() % nbit) {
            a[len] = 0;
            for (int i = sint.length()-1; i >= len*nbit; --i)
                a[len] = a[len]*10 + sint[i] - '0';
            len++;
        }
    }
    bool operator <= (const BigInt &op) {
        if (len > op.len) return false;
        if (len < op.len) return true;
        for (int i = len-1; i >= 0; --i) {
            if (a[i] > op.a[i]) return false;
            if (a[i] < op.a[i]) return true;
        }
        return true;
    }
    BigInt operator * (const BigInt &op) {
        BigInt res;
        res.len = len + op.len;
        memset(res.a, 0, sizeof(res.a));
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < op.len; ++j)
                res.a[i+j] += a[i]*op.a[j];
        for (int i = 0; i < res.len; ++i) {
            res.a[i+1] += res.a[i]/BASE;
            res.a[i] %= BASE;
        }
        while (res.a[res.len]) {
            res.a[res.len+1] = res.a[res.len]/BASE;
            res.a[res.len++] %= BASE;
        }
        while (res.len > 1 && res.a[res.len-1] == 0) res.len--;
        return res;
    }
    BigInt operator + (const BigInt &op) {
        BigInt res;
        if (len < op.len) res.len = op.len;
        else res.len = len;
        for (int i = 0; i < res.len; ++i) {
            res.a[i] = 0;
            if (i < len) res.a[i] = a[i];
            if (i < op.len) res.a[i] += op.a[i];
        }
        res.a[res.len] = 0;
        for (int i = 0; i < res.len; ++i) {
            res.a[i+1] += res.a[i]/BASE;
            res.a[i] %= BASE;
        }
        if (res.a[res.len]) res.len++;
        return res;
    }
    void div2() {
        BigInt res;
        res.len = len;
        LL carry = 0;
        res.a[len] = 0;
        for (int i = len-1; i >= 0; --i) {
            res.a[i] = (carry*BASE + a[i]) / 2;
            carry = (carry*BASE + a[i]) % 2;
        }
        while (res.len > 1 && res.a[res.len-1] == 0) res.len--;
        *this = res;
    }
    void mul2() {
        for (int i = 0; i < len; ++i)
            a[i] *= 2;
        a[len] = 0;
        for (int i = 0; i < len; ++i) {
            a[i+1] += a[i]/BASE;
            a[i] %= BASE;
        }
        while (a[len]) {
            a[len+1] = a[len]/BASE;
            a[len++] %= BASE;
        }
    }
    void inc() {
        a[0]++;
        a[len] = 0;
        for (int i = 0; a[i] >= BASE; ++i) {
            a[i+1] += a[i]/BASE;
            a[i] %= BASE;
        }
        if (a[len]) len++;
    }
    void dec() {
        a[0]--;
        a[len] = 0;
        for (int i = 0; a[i] < 0; ++i) {
            a[i+1]--;
            a[i] += BASE;
        }
        if (a[len-1] == 0) len--;
    }
    
    friend ostream & operator<<(ostream &out, BigInt &x) {
        out << x.a[x.len-1];
        for (int i = x.len-2; i >= 0; --i)
            out << setw(nbit) << setfill('0') << x.a[i];
        return out;
    }
};
