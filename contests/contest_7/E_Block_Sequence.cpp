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
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> dp(n + 1, n);
        
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == n) continue;

            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            
            int len = a[i];
            
            if (len > 0 && i + len <= n) {
                dp[i + len] = min(dp[i + len], dp[i]);
            }
        }
        
        cout << dp[n] << endl;
    }
    
    return 0;
}