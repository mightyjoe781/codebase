#include <bits/stdc++.h>
using namespace std;
int ls[1000100];
int rs[1000100];
int main(){

	ios_base::sync_with_stdio(false); //fast input and output
	cin.tie(NULL); //flush output
	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int s,b;
	while(cin>>s>>b && s && b){
		for(int i = 0; i < s+1; i++){
			ls[i] = i-1;
			rs[i] = i+1;
		}
		while(b--){
			int l,r; cin>>l>>r;
			string ans = "";
			if(ls[l] < 1) ans+= "*"; else ans+= to_string(ls[l]);
			ans += " ";
			if(rs[r] > s) ans+= "*"; else ans+= to_string(rs[r]); 
			ls[rs[r]] = ls[l];
			rs[ls[l]] = rs[r];
			cout << ans<<endl;
		}
		cout << '-' << endl;
	}


	return 0;
}