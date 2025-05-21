#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define forn(i, n) for(int i = 0; i < (n); i++)
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
    int n; cin >> n;
    vi arr (n);
    int res = 0;
    int partial = 1;
    forn(i, n){
        cin >> arr[i];
        if (i>=1){
            if (arr[i]>arr[i-1]){
                partial++;
            }else{
                partial = 1;
            }
        }
        res = res>partial ? res : partial;
    }

    cout << res;


    return 0;
}
