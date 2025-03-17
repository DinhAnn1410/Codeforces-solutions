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
const int maxn = 1e6 + 10;
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

int a, b, c, d, mx = 0, mn = oo;
ll diff[maxn], cnt[maxn], s[maxn], ans = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
#endif
    cin >> a >> b >> c >> d;
    forr(x, a, b) {
        diff[x + b]++;
        diff[x + c + 1]--;
    }
    forr(i, 1, maxn - 10) {
        diff[i] += diff[i - 1];
        if (diff[i]) {
            mx = max(mx, i);
            mn = min(mn, i);
        }
    }
    ford(i, mx, c + 1)
        s[i] = s[i + 1] + diff[i];
    forr(z, c, d)
        ans += s[z + 1];
    cout << ans;
    return 0;
}
