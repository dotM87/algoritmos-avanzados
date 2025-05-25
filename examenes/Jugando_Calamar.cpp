#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = LLONG_MAX/4;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve (int n, int c, int arr []){
	vector <int> hombres(n+1, 0);
	for (int i = 0; i<n; i++){
		hombres[i+1] = hombres[i] + (arr[i] == 1);
	}
	vector <vector<ll>> dp(c+1, vector<ll>(n+1, INF));
	dp [0][0] = 0; 

	for(int i=1; i<=c; i++){
		for(int j=i; j<=n; j++){
			for(int k = i-1; k<j; k++){
				int hs = hombres[j] - hombres[k];
				int ms = (j-k) - hs;
				ll costo = (ll)hs*ms;
				dp[i][j] = min(dp[i][j], dp[i-1][k] + costo);
			}
		}
	}
	return (int)dp[c][n];
}

int main() {
	FAST_IO;
	int n, c;
	vector<int> l(n);
	cin >> n >> c;
	for(int i=0; i<n; i++){
		cin >> l[i];
	}
	cout << solve (n,c,l.data());

	return 0;
}