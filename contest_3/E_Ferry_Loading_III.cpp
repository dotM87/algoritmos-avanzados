#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep(i, a, b) for(int i = a; i < (b); ++i)

int main() {
    FAST_IO;
    
    int c;
    cin >> c;
    
    while(c--) {
        int n, t, m;
        cin >> n >> t >> m;
        
        queue<pair<int, int>> bank[2];
        vector<int> ans(m, 0);
        
        rep(i, 0, m) {
            int time;
            string side;
            cin >> time >> side;
            if(side == "left")
                bank[0].push({time, i});
            else
                bank[1].push({time, i});
        }
        
        int currentTime = 0;
        int currentBank = 0;
        
        while(!bank[0].empty() || !bank[1].empty()){
            if(!bank[currentBank].empty() && bank[currentBank].front().first <= currentTime){
                int cnt = 0;
                while(cnt < n && !bank[currentBank].empty() && bank[currentBank].front().first <= currentTime) {
                    auto car = bank[currentBank].front();
                    bank[currentBank].pop();
                    ans[car.second] = currentTime + t;
                    cnt++;
                }
                currentTime += t;
                currentBank = 1 - currentBank;
            }
            else if(!bank[1 - currentBank].empty() && bank[1 - currentBank].front().first <= currentTime){
                currentTime += t;
                currentBank = 1 - currentBank;
            }
            else {
                int nextArrival = INT_MAX;
                if(!bank[0].empty())
                    nextArrival = min(nextArrival, bank[0].front().first);
                if(!bank[1].empty())
                    nextArrival = min(nextArrival, bank[1].front().first);
                
                if(currentTime < nextArrival)
                    currentTime = nextArrival;
            }
        }
        
        rep(i, 0, m) {
            cout << ans[i] << "\n";
        }
        if(c) cout << "\n";
    }
    
    return 0;
}
