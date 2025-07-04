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

int main() {
    FAST_IO;
    
    int t;
    cin >> t;
    
    while (t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        
        int row1_seats = min(a, m);
        int row2_seats = min(b, m);
        
        int remaining_seats = 2 * m - row1_seats - row2_seats;
        int seated_c = min(remaining_seats, c);
        
        int total_seated = row1_seats + row2_seats + seated_c;
        cout << total_seated << "\n";
    }

    return 0;
}