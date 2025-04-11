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
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string a;
        cin >> a;
        
        int counts[7] = {0};
        for (char c : a) {
            int idx = c - 'A';
            counts[idx]++;
        }
        
        int required = 0;
        for (int i = 0; i < 7; ++i) {
            required += max(0, m - counts[i]);
        }
        
        cout << required << '\n';
    }
    
    return 0;
}