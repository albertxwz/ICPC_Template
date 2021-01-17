int f[maxn];

void getfail(char *P, int *f) {
	f[0] = 0;
	f[1] = 0;
	int m = strlen(P);
	for (int i = 1; i < m; ++i) {
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		if (P[i] == P[j]) f[i+1] = j+1;
		else f[i+1] = 0;
	}
}

int find(char *T, char *P, int *f) {
	int res = 0;
	int n = strlen(T), m = strlen(P);
	getfail(P, f);
	for (int i = 0, j = 0; i < n; ++i) {
		while (j && P[j] != T[i]) j = f[j];
		if (P[j] == T[i]) j++;
		if (j == m) {	// 出现一次
			res++;
			j = f[m];
		}
	}
	return res;
}