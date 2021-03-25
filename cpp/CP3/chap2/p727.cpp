#include <bits/stdc++.h>
using namespace std;
int Priority(char c){
	switch(c){
		case '(' : return 1;
		case '+' : return 2;
		case '-' : return 2;
		case '*' : return 3;
		case '/' : return 3;
	}
	return 0;
}
int main(){

	ios_base::sync_with_stdio(false); //fast input and output
	cin.tie(NULL); //flush output
	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	char s[10],c;
	cin >> t; gets(s); gets(s);
	while(t--){
		stack<char> st;
		while(gets(s) && strlen(s)){
			c = s[0];
			if (c == ' ') break;
			if (c == '(') st.push(c);
			else if (c == '+' || c == '-' || c == '*' || c == '/'){
				while(!st.empty() && Priority(c) <= Priority(st.top())){
					cout << st.top();
					st.pop();
				}
				st.push(c);
			}
			else if( c == ')'){
				while(st.top() != '(') { 
					cout << st.top(); ; st.pop();
				}
			}
			else cout << c;
		}
		// empty the stack

		while(!st.empty()){
			cout << st.top(); st.pop();
		}
		cout << endl;
		if(t) cout << endl;
	}

	return 0;
}