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


const ll INF = (1LL<<60);

struct SegTree {
    int n;
    vector<ll> st, lazy;
    SegTree(int _n): n(_n) {
        st.assign(4*n, INF);
        lazy.assign(4*n, 0);
    }
    void build(int p, int l, int r, vector<ll> &a) {
        if(l == r) {
            st[p] = a[l];
            return;
        }
        int m = (l+r)/2;
        build(p<<1,   l,   m, a);
        build(p<<1|1, m+1, r, a);
        st[p] = min(st[p<<1], st[p<<1|1]);
    }
    void apply(int p, ll val) {
        st[p] += val;
        lazy[p] += val;
    }
    void push(int p) {
        if(lazy[p] != 0) {
            apply(p<<1,   lazy[p]);
            apply(p<<1|1, lazy[p]);
            lazy[p] = 0;
        }
    }
    void update(int p, int l, int r, int i, int j, ll val) {
        if(i > r || j < l) return;
        if(i <= l && r <= j) {
            apply(p, val);
            return;
        }
        push(p);
        int m = (l+r)/2;
        update(p<<1,   l,   m, i, j, val);
        update(p<<1|1, m+1, r, i, j, val);
        st[p] = min(st[p<<1], st[p<<1|1]);
    }
    ll query(int p, int l, int r, int i, int j) {
        if(i > r || j < l) return INF;
        if(i <= l && r <= j) return st[p];
        push(p);
        int m = (l+r)/2;
        return min(
            query(p<<1,   l,   m, i, j),
            query(p<<1|1, m+1, r, i, j)
        );
    }
    void build(vector<ll> &a) { build(1, 0, n-1, a); }
    void update(int i, int j, ll v) { update(1, 0, n-1, i, j, v); }
    ll query(int i, int j)      { return query(1, 0, n-1, i, j); }
};

int main() {
    FAST_IO;
    int n, m;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    SegTree st(n);
    st.build(a);

    cin >> m;
    rep(_,0,m) {
        vector<ll> mov;
        ll x;
        string line;
        getline(cin, line);
        if(line.empty()) { getline(cin, line); }
        stringstream ss(line);
        while(ss >> x) mov.push_back(x);

        if(mov.size() == 2) {
            int L = mov[0], R = mov[1];
            ll ans;
            if(L <= R) {
                ans = st.query(L, R);
            } else {
                ans = min(st.query(L, n-1), st.query(0, R));
            }
            cout << ans << "\n";
        }
        else if(mov.size() == 3) {
            int L = mov[0], R = mov[1];
            ll v = mov[2];
            if(L <= R) {
                st.update(L, R, v);
            } else {
                st.update(L, n-1, v);
                st.update(0, R, v);
            }
        }
    }
    return 0;
}
