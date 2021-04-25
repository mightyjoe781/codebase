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
	vector <stack<char>> v;
	string s;
	int cnt = 0;
	while(cin>>s){
		cnt++;
		if(s == "end") break;
		stack<char> temp;
		for(int i = 0 ; i < s.size(); i++){
			bool flag = false;
			for(int j = 0; j < v.size(); j++){
				if(v[j].top() >= s[i]){
					flag = true;
					v[j].push(s[i]);
					break;
				}
			}
			if(!flag){
				stack<char> tmp;
				tmp.push(s[i]);
				v.push_back(tmp);
			}
		}

		cout << "Case "<<cnt<<": " << v.size() << endl;
		v.clear();
	}

	return 0;
}