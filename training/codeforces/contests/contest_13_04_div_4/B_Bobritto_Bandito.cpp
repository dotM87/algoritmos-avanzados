#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main() {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        int n, m, l, r, pm, l1, r1, vel;
        cin >> n >> m >> l >> r;
        pm = (l + r) / 2;
        vel = abs(l) <= abs(r) ? r/n : l/n;
        l1 = - (vel*m);
        r1 = (vel*m);
        cout << l1 << " " << r1 << endl;
    }
    return 0;
}
