#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int &x : a) cin >> x;
        
        vector<int> freq(n + 2, 0);
        for (int x : a) {
            if (x >= 1) {
                freq[1]++;
                if (x + 1 <= n) {
                    freq[x + 1]--;
                }
            }
        }
        
        vector<int> cnt(n + 1, 0);
        for (int s = 1; s <= n; s++) {
            cnt[s] = cnt[s-1] + freq[s];
        }
        
        vector<long long> prefijo(n + 1, 0);
        for (int s = 1; s <= n; s++) {
            prefijo[s] = prefijo[s-1] + cnt[s];
        }
        
        long long respuesta = 0;
        for (int u = 0; u < m; u++) {
            int a_u = a[u];
            int s_min = max(1, n - a_u);
            int s_max = n - 1;
            
            if (s_min > s_max) continue;
            
            long long suma_cnt = prefijo[s_max] - (s_min > 0 ? prefijo[s_min - 1] : 0);
            int lim_sup = min(s_max, a_u);
            long long suma_restar = 0;
            
            if (lim_sup >= s_min) {
                suma_restar = lim_sup - s_min + 1;
            }
            
            respuesta += suma_cnt - suma_restar;
        }
        
        cout << respuesta << '\n';
    }
    return 0;
}