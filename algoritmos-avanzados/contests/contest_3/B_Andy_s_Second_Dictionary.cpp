#include <bits/stdc++.h>
using namespace std;

// Tipos de datos comunes
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Macros útiles
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

// Optimización de I/O
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// Debugging (desactivar para envío)
// #define DEBUG cerr << "DEBUG: " << __LINE__ << endl;

int main(){
    FAST_IO;
    string line, fullText = "";
    bool firstLine = true;
    while(getline(cin, line)){
        if(!fullText.empty() && fullText.back() == '-'){
            fullText.pop_back();
            fullText += line;
        } else {
            if(!firstLine) fullText += " ";
            fullText += line;
        }
        firstLine = false;
    }
    
    vector<string> words;
    string token = "";
    for (char c : fullText) {
        if(isalpha(c) || c == '-') {
            token.push_back(c);
        } else {
            if(!token.empty()){
                bool hasLetter = false;
                for(auto ch: token)
                    if(isalpha(ch)) { hasLetter = true; break; }
                if(hasLetter) {
                    for(auto &ch : token)
                        ch = tolower(ch);
                    words.pb(token);
                }
                token = "";
            }
        }
    }
    if(!token.empty()){
        bool hasLetter = false;
        for(auto ch: token)
            if(isalpha(ch)) { hasLetter = true; break; }
        if(hasLetter){
            for(auto &ch : token)
                ch = tolower(ch);
            words.pb(token);
        }
    }
    
    set<string> uniqueWords(all(words));

    for(auto &w : uniqueWords)
        cout << w << "\n";
    
    return 0;
}
