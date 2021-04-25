#include <bits/stdc++.h>
using namespace std;
#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define DBG cerr << "debug here" << endl;
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}
int main(){

	ios_base::sync_with_stdio(false); //fast input and output
	cin.tie(NULL); //flush output
	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;
	stack<char> st;
	while(cin>>s){
		while(!st.empty()) st.pop();
		for(int i = 0 ; i < s.size(); i++){
			if(s[i] == '('){
				if(i < s.size()-1 && s[i+1] == '*'){
					st.push(s[i]);
					st.push(s[i+1]);
					i++;
					continue;
				} 
				else st.push(s[i]);
			}
			if(s[i] == '{' || s[i] == '[' || s[i] == '<') {st.push(s[i]); continue; }

			switch(s[i]){
				case '}' : if(st.top() == '{') st.pop();
							break;
				case '>' : if(st.top() == '<') st.pop();
							break;
				case ']' : if(st.top() == '[') st.pop();
							break;
				case '*' : if(st.top() == '*') {
								if(!st.empty()) st.pop();
								if(st.top() == '(' && s[i+1] == ')' && i < s.size()-1) {st.pop(); i++;}
								else st.push('*');
							}
							break;
				case ')' : if(st.top() == '(') st.pop();
							break;
			}

		}
		if(st.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}