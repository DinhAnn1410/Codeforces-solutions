#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define file "test"
#define forr(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define forf(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define MASK(i) (1LL << (i))
#define bit(x, i) (((x) >> (i)) & 1)
#define bp __builtin_popcountll
const int maxn = 2e2 + 10;
const int MOD = 1e9 + 7; // 998244353 // 1e9 + 2277 // 1e9 + 5277
const ll inf = 1e18;
const int oo = 1e9 + 7;
const float eps = 1e-6;

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        }
        return 0;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        }
        return 0;
    }
/* END OF TEMPLATE. WHAT A SIGMA! TAKE A DEEP BREATH AND READY FOR CODING :D */

ll R, G, B, r[maxn], g[maxn], b[maxn], n;
ll dp[maxn][maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
#endif
    cin >> R >> G >> B;
    forr(i, 1, R)
        cin >> r[i];
    forr(i, 1, G)
        cin >> g[i];
    forr(i, 1, B)
        cin >> b[i];
    sort(r + 1, r + R + 1);
    sort(g + 1, g + G + 1);
    sort(b + 1, b + B + 1);
    forr(i, 0, R)
        forr(j, 0, G)
            forr(k, 0, B) {
                if (i > 0 && j > 0) 
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i] * g[j]);
                if (i > 0 && k > 0) 
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i] * b[k]);
                if (j > 0 && k > 0) 
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j] * b[k]);
            }
    cout << dp[R][G][B];
    return 0;
}
