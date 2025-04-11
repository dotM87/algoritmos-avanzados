#include <bits/stdc++.h>
using namespace std;

// Tipos de datos comunes
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Macros útiles
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

// Optimización de I/O
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    FAST_IO;

    int n;
    while (cin >> n && n != 0) {
        vector<pii> autos(n);
        rep(i, 0, n) {
            int c, p;
            cin >> c >> p;
            autos[i] = mp(c, p);
        }

        vi pos(n);
        bool valido = true;
        rep(i, 0, n) {
            int pos_actual = i + 1;
            pos[i] = pos_actual + autos[i].se;
            if (pos[i] < 1 || pos[i] > n) {
                valido = false;
            }
        }

        if (valido) {
            unordered_set<int> posiciones(all(pos));
            if (sz(posiciones) != n)
                valido = false;
        }

        if (!valido) {
            cout << "-1\n";
            continue;
        }

        vector<pii> res;
        rep(i, 0, n) {
            res.pb(mp(pos[i], autos[i].fi));
        }

        sort(all(res));

        rep(i, 0, n) {
            if (i > 0)
                cout << ' ';
            cout << res[i].se;
        }
        cout << '\n';
    }

    return 0;
}