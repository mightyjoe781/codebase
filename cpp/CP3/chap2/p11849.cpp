#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){

	ios_base::sync_with_stdio(false); //fast input and output
	cin.tie(NULL); //flush output
	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	ll n,m,x,ans;
	set<ll> cds;
	while(cin>>n>>m, n || m){
		cds.clear();
		while(n--){
			cin>>x;
			cds.insert(x);
		}
		ans = 0;
		while(m--){
			cin>>x;
			if(cds.find(x)!= cds.end()) ans++;
		}
		cout << ans << endl;
	}

	return 0;
}