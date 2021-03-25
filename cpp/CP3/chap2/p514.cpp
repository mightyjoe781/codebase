#include <bits/stdc++.h>
using namespace std;
int n,c;
stack<int> cars;
void solve(){
	for(;;){
		while(!cars.empty()) cars.pop();
		int i = 0, j = 0;
		while(i < n){
			i++;
			cin >> c;
			if(c == 0) return;
			while( j < n && j!=c){
				if(!cars.empty() && cars.top() == c) break;
				j++;
				cars.push(j);
			}
			if(cars.top() == c) cars.pop();
		}
		if(cars.empty()) cout << "Yes\n";
		else cout << "No\n";
	}
}
int main(){

	ios_base::sync_with_stdio(false); //fast input and output
	cin.tie(NULL); //flush output
	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	while(cin>> n){
		if( n == 0 ) break;
		solve();
		cout << endl;	
	}
	return 0;
}