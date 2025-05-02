#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        ll max_sum = accumulate(a.begin(), a.end(), 0LL);
        vector<ll> current = a;
        
        while (current.size() > 1) {
            ll no_rev = current.back() - current[0];
            ll rev = current[0] - current.back();
            ll candidate = max(no_rev, rev);
            if (candidate > max_sum) {
                max_sum = candidate;
            }
            
            vector<ll> new_seq;
            if (no_rev >= rev) {
                for (int i = 0; i < current.size() - 1; ++i) {
                    new_seq.push_back(current[i+1] - current[i]);
                }
            } else {
                reverse(current.begin(), current.end());
                for (int i = 0; i < current.size() - 1; ++i) {
                    new_seq.push_back(current[i+1] - current[i]);
                }
            }
            current = new_seq;
        }
        
        cout << max_sum << "\n";
    }
    return 0;
}