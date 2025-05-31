#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mp;
typedef priority_queue<int> pq;

#define forn(i,n) for(int i = 0; i < (n); i++)
#define fore(i,a,b) for(int i = (a); i < (b); i++)
#define forv(a,x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll modPow(ll base, ll exp, ll mod) {
    ll res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    FAST_IO;
    int n;
    cin >> n;

    int mcm = 210;

    if (n < 3) {
        cout << -1;
        return 0;
    }
    if (n == 3) {
        cout << mcm;
        return 0;
    }

    ll potencia = modPow(10, n - 1, mcm);
    ll rem = potencia % mcm; 
    int sufijo = (mcm - rem) % mcm;
    string sufijoStr = to_string(sufijo);

    while (sz(sufijoStr) < 3) sufijoStr = "0" + sufijoStr;

    string prefijo = "1";
    prefijo += string(n - 4, '0');

    cout << prefijo << sufijoStr;

    return 0;
}
