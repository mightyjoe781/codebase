#include <bits/stdc++.h>
using namespace std;
#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define DBG cerr << "debug here" << endl;
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}

int main(){

	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n ; cin>> n;
	getc(stdin);
	while(n--){
		char s[140];
		gets(s);
		int len = strlen(s);
		stack<char> st;
		for(int i = 0 ; i<len ; i++){
			if(s[i] == '(' || s[i] == '['){
				st.push(s[i]);
			}
			else if(s[i] == ')') {
				if(st.empty() || st.top() != '('){
					st.push('a');
					break;
				}
				st.pop();
			} else if(s[i] == ']'){
				if(st.empty() || st.top() != '['){
					st.push('a');
					break;
				}
				st.pop();
			}

		}
		if(st.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}