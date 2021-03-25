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

	int t; cin>>t;
	set<string> s;
	for(int k = 0; k< t ; k++){
		int m,n;
		cin>>m>>n >> ws;
		vector<string> x(m);
		vector<string> y(n);
		for(int i = 0; i<m ; i++)
			getline(cin,x[i]);
		for(int i = 0; i<n ; i++)
			getline(cin,y[i]);

		for(int i = 0; i < x.size() ; i++)
			for(int j = 0; j < y.size(); j++)
				s.insert(x[i]+y[j]);
		cout << "Case " << k+1 << ": " << s.size() << endl;
		s.clear();
	}
	return 0;
}