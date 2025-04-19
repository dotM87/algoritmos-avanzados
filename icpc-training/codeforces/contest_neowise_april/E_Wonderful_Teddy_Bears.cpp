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

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        ll instructions = 0;
        bool flag = true;

        while (flag) {
            flag = false;
            rep(i, 0, n - 2) {
                if (s[i] == 'P' && (s[i + 1] == 'B' || s[i + 2] == 'B')) {
                    int blackcount = (s[i] == 'B') + (s[i + 1] == 'B') + (s[i + 2] == 'B');
                    rep(j, 0, 3) s[i + j] = (j < blackcount ? 'B' : 'P');
                    instructions++;
                    flag = true;
                }
            }
        }

        cout << instructions;
        if (t) cout << '\n';
    }
    return 0;
}
