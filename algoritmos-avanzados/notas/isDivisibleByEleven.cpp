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

bool isDivisibleByEleven(string n) {
    int sum = 0;
    function<void(int)> dfs = [&](int i) {
        if (i >= n.size()) return;
        sum += (i % 2 == 0 ? 1 : -1) * (n[i] - '0');
        dfs(i + 1);
    };
    dfs(0);
    return sum % 11 == 0;
}

int main() {
    FAST_IO;
    string n;
    cin >> n;
    cout << isDivisibleByEleven(n) << endl;

    return 0;
}
