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
#define fore(i, a, b) for(int i = (a); i <(b); i++)
#define forv(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DEBUG cerr << "DEBUG: " << __LINE__ << endl;

const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;

ll mean(const vector<ll>& arr){
    ll sum = accumulate(all(arr), 0LL);
    if ((2 * sum) % sz(arr) != 0) return -1;
    return (2 * sum) / sz(arr);
}

ll solve(vector<ll> arr){
    ll target = mean(arr);
    if(target == -1) return 0;
    unordered_map<ll, int> reps;
    ll count = 0;
    forv (a, arr) {
        count += reps[target - a];
        reps[a]++;
    }
    return count;
}

signed main() {
    FAST_IO;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> arr(n);
        forn(i, n) cin >> arr[i];
        ll res = solve(arr);
        cout << res << endl;
    }
    return 0;
}

