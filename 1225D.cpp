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

int n, k, a[maxn];
map<vector<pii>, int> d;

vector<pii> pt(int x) {
    map<int, int> facts;
    for (int i = 2; i * i <= x; ++i)
        while (x % i == 0) {
            facts[i]++;
            x /= i;
        }
    if (x > 1) facts[x]++;
    vector<pii> ret;
    for (pii primes : facts)
        if (primes.se % k > 0)
            ret.pb(mp(primes.fi, primes.se % k));
    return ret;
}

vector<pii> find_inverse(vector<pii> a) {
    vector<pii> ret;
    for (pii it : a)
        ret.pb(mp(it.fi, k - it.se));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
#endif
    cin >> n >> k;
    forr(i, 1, n) {
        cin >> a[i];
        d[pt(a[i])]++;
    }
    ll ans = 0;
    forr(i, 1, n)
        if (pt(a[i]) == find_inverse(pt(a[i])))
            ans += d[pt(a[i])] - 1;
        else
            ans += d[find_inverse(pt(a[i]))];
    cout << ans / 2;
    return 0;
}
