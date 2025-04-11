#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i, a, b) for (int i = a; i < (b); i++)

ll countPairsLE(vector<ll>& arr, ll X) {
    int n = arr.size();
    ll cnt = 0;
    int l = 0, r = n - 1;
    while(l < r) {
        if(arr[l] + arr[r] <= X) {
            cnt += (r - l);
            l++;
        } else {
            r--;
        }
    }
    return cnt;
}

int main(){
    FAST_IO;
    int numCases;
    cin >> numCases;
    while(numCases--){
        int n;
        ll x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        ll S = 0;
        rep(i, 0, n) {
            cin >> a[i];
            S += a[i];
        }
        ll L = S - y;
        ll R = S - x;
        sort(a.begin(), a.end());
        ll ans = countPairsLE(a, R) - countPairsLE(a, L - 1);
        cout << ans << "\n";
    }
    return 0;
}
