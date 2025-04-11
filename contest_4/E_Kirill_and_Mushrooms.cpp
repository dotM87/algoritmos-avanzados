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

struct BIT {
    int n;
    vector<int> fenw;
    BIT(int n): n(n), fenw(n+1, 0) {}
    void update(int i, int delta) {
        for(; i <= n; i += i & -i) fenw[i] += delta;
    }
    int query(int i) {
        int s = 0;
        for(; i > 0; i -= i & -i) s += fenw[i];
        return s;
    }
    int findKth(int k) {
        int idx = 0;
        for (int bit = 1 << 20; bit; bit >>= 1) {
            int nxt = idx + bit;
            if(nxt <= n && fenw[nxt] < k) {
                k -= fenw[nxt];
                idx = nxt;
            }
        }
        return idx + 1;
    }
};

int main() {
    FAST_IO;
    int numTests;
    cin >> numTests;
    while(numTests--) {
        int numMush;
        cin >> numMush;
        vector<ll> magic(numMush+1);
        rep(i, 1, numMush+1) cin >> magic[i];
        vector<int> perm(numMush+1);
        rep(i, 1, numMush+1) cin >> perm[i];
        vector<ll> comp;
        rep(i, 1, numMush+1) comp.pb(magic[i]);
        sort(all(comp));
        comp.erase(unique(all(comp)), comp.end());
        int compSize = sz(comp);
        auto getId = [&](ll val) {
            return (int)(lower_bound(all(comp), val) - comp.begin()) + 1;
        };
        BIT bit(compSize);
        rep(i, 1, numMush+1) {
            int id = getId(magic[i]);
            bit.update(id, 1);
        }
        ll bestStr = 0;
        int bestK = 0;
        rep(k, 1, numMush+1) {
            int safeSize = numMush - k + 1;
            int m = min(k, safeSize);
            int pos = safeSize - m + 1;
            int id = bit.findKth(pos);
            ll cand = comp[id - 1];
            ll strength = (ll)m * cand;
            if(strength > bestStr) {
                bestStr = strength;
                bestK = k;
            }
            if(k < numMush) {
                int idxRemove = perm[k];
                int idRemove = getId(magic[idxRemove]);
                bit.update(idRemove, -1);
            }
        }
        cout << bestStr << " " << bestK << "\n";
    }
    return 0;
}
