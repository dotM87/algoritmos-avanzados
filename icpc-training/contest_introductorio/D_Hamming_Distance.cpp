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

signed main() {
    FAST_IO;
    int n, res;
    cin >> n;
    string pal, palx;
    cin >> pal,
    cin >> palx;
    res = 0;
    rep(i,0, n){
      if (pal[i] != palx[i]){
        res = res +1;
      }
    }
    cout << res;
    
    return 0;
}