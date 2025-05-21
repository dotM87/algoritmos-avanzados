#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define DEBUG cerr << "DEBUG: " << __LINE__ << endl;

int x_global, y_global;
vi memo;

int dfs(int k) {
    if (k == y_global) return 0;
    int& res = memo[k];
    if (res != -1) return res;
    int best = INT_MAX;
    
    if (k + 1 <= y_global) {
        int steps = dfs(k + 1);
        if (steps >= 0) best = min(best, 1 + steps);
    }

    int rem = y_global - k;
    int base = 1;
    while (x_global * base <= rem) {
        int nxt = k + x_global * base;
        int steps = dfs(nxt);
        if (steps >= 0) best = min(best, 1 + steps);
        base *= 10;
    }

    res = (best == INT_MAX ? -1 : best);
    return res;
}

int main() {
    FAST_IO;
    int T;
    cin >> T;
    while (T--) {
        cin >> x_global >> y_global;
        memo.assign(y_global + 1, -1);
        cout << dfs(0) << '\n';
    }
    return 0;
}
