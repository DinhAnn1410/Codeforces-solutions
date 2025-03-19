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
const int maxval = 6e5;
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

struct Trie {
    struct Node {
        Node* child[2];
        Node() {
            forf(i, 0, 2)
                child[i] = NULL;
        }
    };
    int curr;
    Node* root;
    Trie() : curr(0) {
        root = new Node();
    }
    void add(int x) {
        Node* pos = root;
        ford(Bit, 20, 0) {
            if (bit(x, Bit)) {
                if (pos->child[1] == NULL) pos->child[1] = new Node();
            }
            else if (pos->child[0] == NULL) pos->child[0] = new Node();
            pos = pos->child[bit(x, Bit)];
        }
    }
    int query(int x) {
        Node* pos = root;
        int ans = 0;
        ford(Bit, 20, 0) {
            if (bit(x, Bit)) {
                if (pos->child[1] != NULL)
                    pos = pos->child[1];
                else {
                    if (pos->child[0] != NULL) {
                        ans += MASK(Bit);
                        pos = pos->child[0];
                    }
                }
            }
            else {
                if (pos->child[0] != NULL)
                    pos = pos->child[0];
                else {
                    if (pos->child[1] != NULL) {
                        ans += MASK(Bit);
                        pos = pos->child[1];
                    }
                }
            }
        }
        return ans;
    }
} trie;

int n, m, curr;
bool used[maxval + 5];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
#endif
    cin >> n >> m;
    forr(i, 1, n) {
        int x;
        cin >> x;
        used[x] = 1;
    }
    forr(val, 0, maxval)
        if (!used[val])
            trie.add(val);
    while (m--) {
        int x;
        cin >> x;
        curr ^= x;
        cout << trie.query(curr) << "\n";
    }
    return 0;
}
