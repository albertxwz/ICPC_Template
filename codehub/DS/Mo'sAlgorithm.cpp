struct Interval {
	int l, r, t, id;
	int k;
	Interval(int l=0, int r=0, int t=0, int id=0, int k=0):
		l(l), r(r), t(t), id(id), k(k) {}
};

struct UpdateOp {
	int p, x;
	UpdateOp(int p=0, int x=0): p(p), x(x) {}
};

int n, q, S, st, ed, qt; // S is the size of one block
vector<Interval> intervals;
vector<UpdateOp> up;

bool cmp(Interval A, Interval B) {
	return (A.l-1)/S < (B.l-1)/S ||
			((A.l-1)/S == (B.l-1)/S && (A.r-1)/S < (B.r-1)/S) ||
			((A.l-1)/S == (B.l-1)/S && (A.r-1)/S == (B.r-1)/S && A.t < B.t);
}

void add(int loc) {
}

void del(int loc) {
}

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	read(n); read(q);
	for (int i = 1; i <= n; ++i) {
		read(a[i]);
		tmpa[i] = a[i];
	}
	for (int i = 0; i < q; ++i) {
		int cmd;
		read(cmd);
		if (cmd == 1) {
			int l, r, k;
			read(l); read(r); read(k);
			intervals.push_back(Interval(l, r, up.size(), i, k));
		}
		else {
			ans[i] = -2;
			int p, x;
			read(p); read(x);
			up.push_back(UpdateOp(p, x));
		}
	}
	S = (int)pow(2.0*n*n, 1.0/3); // without update operation, S=(int)(n/sqrt(q))
	sort(intervals.begin(), intervals.end(), cmp);
	tot = 0;
	qt = 0;
	st = 1; ed = 1;
	add(1);
	for (auto qj: intervals) {
		if (ed <= qj.r) {
			while (ed < qj.r) add(++ed);
			while (ed > qj.r) del(ed--);
			while (st < qj.l) del(st++);
			while (st > qj.l) add(--st);
		}
		else {
			while (st < qj.l) del(st++);
			while (st > qj.l) add(--st);
			while (ed < qj.r) add(++ed);
			while (ed > qj.r) del(ed--);
		}
		if (qt > qj.t) { // recover the update operation
		}
		for (; qt < qj.t; ++qt) { // update operation
			if (st <= up[qt].p && up[qt].p <= ed)
				del(up[qt].p);
			a[up[qt].p] = up[qt].x;
			if (st <= up[qt].p && up[qt].p <= ed)
				add(up[qt].p);
		}
		ans[qj.id] = solve();
	}
	for (int i = 0; i < q; ++i)
		if (ans[i] > -2) cout << ans[i] << "\n";
	return 0;
}