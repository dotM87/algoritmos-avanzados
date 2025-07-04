#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mp;
typedef priority_queue<int> pq;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define fore(i, a, b) for(int i = (a); i < (b); i++)
#define forv(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;

signed main() {
    FAST_IO;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        fore(i, 0, n) cin >> arr[i];

        vi ultimaPos(n + 1, n), siguienteAp(n, n);
        for (int i = n - 1; i >= 0; i--) {
            int x = arr[i];
            siguienteAp[i] = ultimaPos[x];
            ultimaPos[x] = i;
        }

        int res = 0;
        int pos = 0;
        while (pos < n) {
            if (siguienteAp[pos] == n) {
                res++;
                break;
            }
            int sigMin = siguienteAp[pos];
            int i = pos;
            for (; i < n; i++) {
                if (siguienteAp[i] < sigMin) sigMin = siguienteAp[i];
                if (i == sigMin - 1) {
                    break;
                }
            }
            res++;
            pos = i + 1;
        }

        cout << res << endl;
    }
    return 0;
}
