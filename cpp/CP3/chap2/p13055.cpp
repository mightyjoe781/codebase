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

	int n; cin>>n >> ws;
	stack<string> s;
	string cmd;
	string inp;
	while(n--){
		cin>>cmd; 
		if(cmd == "Sleep"){
			cin >> inp;
			s.push(inp);
		}
		if(cmd == "Kick")
			if(!s.empty()) 
				s.pop();
		if(cmd == "Test"){
			if(!s.empty()) cout << s.top() << endl;
			else cout << "Not in a dream" << endl;
		}
	}

	return 0;
}