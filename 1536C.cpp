#include <bits/stdc++.h>
#include <map>
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

int t, n;
string s;

pii get(int d, int k) {
    int g = __gcd(d, k);
    d /= g;
    k /= g;
    return mp(d, k);
}

void solve() {
    cin >> n;
    cin >> s;
    map<pii, int> cnt;
    int d = 0, k = 0;
    forf(i, 0, n) {
        if (s[i] == 'D') d++;
        else k++;
        cout << ++cnt[get(d, k)] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}
