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
#define fore(i, a, b) for (int i = (a); i < (b); i++)
#define forv(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DEBUG cerr << "DEBUG: " << __LINE__ << endl;

int main() {
    FAST_IO;
    
    int n;
    cin >> n;
    unordered_map<ll, unordered_map<ll, unordered_set<ll>>> entregas;
    entregas.reserve(n);
    vll keys;
    keys.reserve(n);
    forn(i, n) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (!entregas.count(a)) {
            keys.pb(a);
            entregas[a] = unordered_map<ll, unordered_set<ll>>();
        }
        entregas[a][b].insert(c);
    }
    sort(all(keys));
    forv(a, keys) {
        auto& mapB = entregas[a];
        int cntB = sz(mapB);
        ll totalC = 0;
        forv(q, mapB) {
            totalC += sz(q.se);
        }
        cout << a << " " << cntB << " " << totalC << "\n";
    }

    return 0;
}
