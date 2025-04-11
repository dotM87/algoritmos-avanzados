#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line)) {
        list<char> text;
        auto current = text.end();

        trav(c, line) {
            if (c == '[') {
                current = text.begin();
            } else if (c == ']') {
                current = text.end();
            } else {
                current = text.insert(current, c);
                current++;
            }
        }

        string result(all(text));
        cout << result << '\n';
    }

    return 0;
}