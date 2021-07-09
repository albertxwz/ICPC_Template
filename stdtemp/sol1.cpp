#include <bits/stdc++.h>
#define lc (o<<1)
#define rc ((o<<1)|1)
#define PB push_back
#define MK make_pair
using namespace std;
#define DebugP(x) cout << "Line" << __LINE__ << " " << #x << "=" << x << endl

const int maxn = 3000 + 5;
const int modu = 998244353; // 1e9 + 7
const int inf = 0x3f3f3f3f;
const double eps = 1e-5;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

typedef long long LL;

void read(LL &x) {
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}

void read(int &x) { LL y; read(y); x = (int)y; }
void read(char &ch) { char s[3]; scanf("%s", s); ch = s[0]; }
void read(char *s) { scanf("%s", s); }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }

int main() {
    // freopen("my.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	return 0;
}
