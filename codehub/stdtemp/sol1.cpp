#include <bits/stdc++.h>
#define lc (o<<1)
#define rc ((o<<1)|1)
using namespace std;
#define DebugP(x) cout << "Line" << __LINE__ << " " << #x << "=" << x << endl

const int maxn = 5e5 + 5;
const int modu = 998244353; // 1e9 + 7
const double eps = 1e-5;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

typedef long long LL;

template<class T>
inline void read(T &x)
{
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}

int main() {
    // freopen("my.txt", "w", stdout);
	ios::sync_with_stdio(false); // do not use endl
	cin.tie(0); // cannot use cout/printf or cin/scanf at the same time.
	return 0;
}
