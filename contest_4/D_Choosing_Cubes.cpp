#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> a(n);
        for (int &num : a) {
            cin >> num;
        }
        int val = a[f - 1];
        int cont_g = 0, cont_e = 0;
        for (int num : a) {
            if (num > val) {
                cont_g++;
            } else if (num == val) {
                cont_e++;
            }
        }
        int min_pos = cont_g + 1;
        int max_pos = cont_g + cont_e;
        if (max_pos <= k) {
            cout << "YES\n";
        } else if (min_pos > k) {
            cout << "NO\n";
        } else {
            cout << "MAYBE\n";
        }
    }
    return 0;
}