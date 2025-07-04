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

int optofashionable(vector<int> v) {
  vector<int> ordenado = v;
  sort(all(ordenado));
  
  if ((ordenado[0] + ordenado.back()) % 2 == 0) {
    return 0;
  }
  
  map<int, int> reps;
  forn(i, sz(v)) {
    reps[v[i]]++;
  }
  
  int op_min = 0;
  int idx = 0;
  while (idx < sz(ordenado) && (ordenado[idx] + ordenado.back()) % 2 != 0) {
    int act_min = ordenado[idx];
    op_min += reps[act_min];
    while (idx < sz(ordenado) && ordenado[idx] == act_min) {
      idx++;
    }
  }
  
  if (idx >= sz(ordenado)) {
    op_min = INT_MAX;
  }
  
  int op_max = 0;
  idx = sz(ordenado) - 1;
  while (idx >= 0 && (ordenado[0] + ordenado[idx]) % 2 != 0) {
    int act_max = ordenado[idx];
    op_max += reps[act_max];
    while (idx >= 0 && ordenado[idx] == act_max) {
      idx--;
    }
  }
  
  if (idx < 0) {
    op_max = INT_MAX;
  }
  
  return min(op_min, op_max);
}

signed main() {
  FAST_IO;
  int t; cin >> t;
  while (t--){
    int n; cin >> n;
    vector <int> v (n);
    forn(i,n){
      cin >> v[i];
    }
    cout << optofashionable(v) << endl;
  }



  return 0;
}
