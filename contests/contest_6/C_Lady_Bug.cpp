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


void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int zeros_C1 = 0;
    int zeros_C2 = 0;

    for (int k = 0; k < n; ++k) {
        if ((k + 1) % 2 != 0) {
            if (a[k] == '0') {
                zeros_C1++;
            }
            if (b[k] == '0') {
                zeros_C2++;
            }
        } else {
            if (a[k] == '0') {
                zeros_C2++;
            }
            if (b[k] == '0') {
                zeros_C1++;
            }
        }
    }

    int req_C1 = (n + 1) / 2;
    int req_C2 = n / 2;

    if (zeros_C1 >= req_C1 && zeros_C2 >= req_C2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}