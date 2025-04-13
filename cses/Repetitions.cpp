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

int main() {
    FAST_IO;
    string dna;
    cin >> dna;
    int conta = 0;
    int res = 0;
    rep(i,0,sz(dna)){
        if (dna[i] == dna[i+1]){
            conta++;
            if (conta>res){
                res = conta;
            }
        }else{
            conta = 0;
        }
    }
    cout << res+1;


    return 0;
}
