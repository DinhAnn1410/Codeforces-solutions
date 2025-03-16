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
const int maxn = 1505;
const int MOD1 = 1e9 + 2277; // 998244353 // 1e9 + 2277 // 1e9 + 5277
const int MOD2 = 1e9 + 5277;
const int base = 256;
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

string s;
char a[30];
int k, n, d[maxn][28];
ll pw1[maxn], hs1[maxn], pw2[maxn], hs2[maxn];
vector<pll> ans;

pll get(int l, int r) {
    ll get1 = ((hs1[r] - hs1[l - 1] * pw1[r - l + 1]) % MOD1 + MOD1) % MOD1;
    ll get2 = ((hs2[r] - hs2[l - 1] * pw2[r - l + 1]) % MOD2 + MOD2) % MOD2;
    return mp(get1, get2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
#endif
    cin >> s;
    forf(i, 0, 26)
        cin >> a[i];
    cin >> k;
    n = s.size();
    s = " " + s;
    pw1[0] = pw2[0] = 1;
    forr(i, 1, n) {
        pw1[i] = (pw1[i - 1] * base) % MOD1;
        hs1[i] = (hs1[i - 1] * base + s[i]) % MOD1;
        pw2[i] = (pw2[i - 1] * base) % MOD2;
        hs2[i] = (hs2[i - 1] * base + s[i]) % MOD2;
    }
    forr(i, 1, n)
        forf(j, 0, 26)
            d[i][j] = d[i - 1][j] + (int(s[i] - 'a') == j);
    forr(i, 1, n)
        forr(j, i, n) {
            int cnt = 0;
            forf(c, 0, 26)
                if (a[c] == '0') {
                    cnt += d[j][c] - d[i - 1][c];
                    if (cnt > k)
                        break;
                }
            if (cnt <= k)
                ans.pb(get(i, j));
        }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << ans.size();
    return 0;
}
