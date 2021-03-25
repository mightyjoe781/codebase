#include <bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false); //fast input and output
	cin.tie(NULL); //flush output
	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; cin >>n;
	while(n--){
		int k; cin>>k;
		int freq[256] = {0};
		double cost[256] = {0};
		while(k--){
			char c; cin>> c;
			int cst; cin >> cst;
			cost[c] = (double)cst/100;
		}
		int m; cin >> m; cin>>ws;
		string str;
		while(m--){
			getline(cin,str);
			for(int i = 0; i< str.size(); i++)
				freq[str[i]]++;
		}

		double ans = 0;
		// for(int i = 0; i<256; i++)
		// 	if(cost[i]) cout<<char(i)<<" " << cost[i]<<" " << freq[i] <<endl;
		for(int i = 0; i < 256; i++)
			ans+= (cost[i]*freq[i]);	
		
		cout <<fixed<<setprecision(2)<< ans<<'$'<<endl;

	}

	return 0;
}