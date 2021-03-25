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

	int n; cin>>n;cin>>ws;

	while(n--){
		string str;
		getline(cin,str);
		transform(str.begin(), str.end(), str.begin(),[](unsigned char c){return std::tolower(c);});
		int freq[256] = {0};
		for(int i = 0; i<str.size(); i++)
			if(str[i] >='a' && str[i] <= 'z')
				freq[str[i]]++;
		int max_f = INT_MIN;
		for(int i = 0; i<256 ; i++)
			max_f = max(max_f,freq[i]);
		for(int i = 0; i<256 ; i++)
			if(max_f == freq[i])
				cout<<char(i);
		cout <<endl;
	}

	return 0;
}