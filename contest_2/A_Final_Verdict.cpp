#include <bits/stdc++.h> // Incluye todas las librerías estándar
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

// Debugging (desactivar para envío)
#define DEBUG cerr << "DEBUG: " << __LINE__ << endl;

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &num : a) {
            cin >> num;
        }
        if (n == 1) {
            cout << (a[0] == x ? "YES" : "NO") << '\n';
        } else {
            int sum = accumulate(a.begin(), a.end(), 0);
            cout << (sum == x * n ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}