#include <bits/stdc++.h>
using namespace std;
//dir -> 0 : front and 1 : tail;
void insert(string &str, deque<string> &dq, bool dir){
	if(!str.empty()){
		if(dir)
			dq.push_front(str);
		else dq.push_back(str);
	}
	str.clear();
}
int main(){

	ios_base::sync_with_stdio(false); //fast input and output
	cin.tie(NULL); //flush output
	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;
	char prev_ch;
	while(cin>>s){
		// solve for each string
		string str;
		deque<string> dq;
		bool dir = false; // to maintain the state of pointer 
		int n = s.size();
		for(int i = 0 ; i< n; i++){
			if(s[i] == '['|| s[i] == ']'){
				insert(str,dq,dir);
				if(s[i] == '[') dir = true;
				else dir = false; 
			} else str = str+s[i];
		}
		 // last fallback case handled here otherwise all cases handled by loop
		if(s[n-1] != '[' &&  s[n-1] != ']')
			insert(str,dq,dir);
		for(auto d : dq)
			cout << d;
		cout << endl;
	}

	return 0;
}