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
#define trav(a, x) for(auto& a : x)
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

bool isConsonant(char c){
    bool res = false;
    if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' && c!='y'){
        res = true;
    }
    return res;
}

signed main() {
    FAST_IO;
    string x; cin >> x;
    string res;
    trav(ch, x){
        ch = tolower(ch);
        if (isConsonant(ch)){
            res.append(".");
            res.append(1, ch);
        }
    }
    cout << res;

    return 0;
}
