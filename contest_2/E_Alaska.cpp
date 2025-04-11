#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        sort(stations.begin(), stations.end());
        
        bool possible = true;
        for (int i = 1; i < n; i++) {
            if (stations[i] - stations[i-1] > 200) {
                possible = false;
                break;
            }
        }
        
        if (possible && (1422 - stations.back() > 100)) {
            possible = false;
        }
        
        cout << (possible ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
    }
    return 0;
}
