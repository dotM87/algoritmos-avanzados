#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n), b(n+1);
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        b[n] = 0;

        ll ans = 0;
        rep(i, 0, n) {
            if (a[i] > b[i+1])
                ans += a[i] - b[i+1];
        }
        cout << ans << '\n';
    }

    return 0;
}
