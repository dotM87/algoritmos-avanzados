#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

unordered_map<pair<int, int>, int, pair_hash> memo;

int f(int k, const vi& a, int l, int r) {
    int ans = 0;
    rep(i, l, r + 1) {
        if (k == 1) {
            ans += (r - i + 1);
            break;
        }

        pair<int, int> key = {k, a[i]};
        if (memo.count(key)) {
            k = memo[key];
        } else {
            int original_k = k;
            if (a[i] != 1 && k >= a[i]) {
                while (k % a[i] == 0) k /= a[i];
                memo[key] = k;
            }
        }

        ans += k;
    }
    return ans;
}

int main() {
    FAST_IO;
    int t;
    cin >> t;
    rep(tc, 0, t) {
        memo.clear();
        int n, q;
        cin >> n >> q;
        vi a(n);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, q) {
            int k, l, r;
            cin >> k >> l >> r;
            cout << f(k, a, l - 1, r - 1) << "\n";
        }
    }
    return 0;
}
