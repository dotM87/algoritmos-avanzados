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

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vll L(n), R(n);
        rep(i, 0, n) cin >> L[i];
        rep(i, 0, n) cin >> R[i];

        ll sum_max = 0;
        vll mins(n);
        rep(i, 0, n) {
            ll mn = min(L[i], R[i]);
            ll mx = max(L[i], R[i]);
            sum_max += mx;
            mins[i] = mn;
        }

        sort(all(mins), greater<ll>());
        ll sum_mins = 0;
        rep(i, 0, min(k - 1, n)) sum_mins += mins[i];

        ll result = sum_max + sum_mins + 1;
        cout << result;
        if (t) cout << '\n';
    }
    return 0;
}
