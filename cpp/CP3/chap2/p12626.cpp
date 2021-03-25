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

	int n; cin>>n;
	int inp[256] = {0};
	inp['M'] = 1;
	inp['A'] = 3;
	inp['R'] = 2;
	inp['G'] = 1;
	inp['I'] = 1;
	inp['T'] = 1;
	string s;
	while(n--){
		cin>>s;
		int freq[256] = {0};
		for(int i = 0; i < s.length(); i++)
			freq[s[i]]++;
		int minp = INT_MAX;
		for(int i = 0; i < 256; i++)
			if(inp[i]){
				minp = min(minp,freq[i]/inp[i]);
			}
		cout<<minp<<endl;
	}

	return 0;
}