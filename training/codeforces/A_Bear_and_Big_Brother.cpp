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
    int n, m, res;
    res = 0;
    cin >> n >> m;
    if (n == m){
      res = 1;
    } else {
      while (n <= m){
        n = n*3;
        m = m*2;
        res = res + 1;
      }
    }
    cout << res;


    return 0;
}
