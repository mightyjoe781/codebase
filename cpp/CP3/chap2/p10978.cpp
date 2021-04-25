//--------------------------------------------------------------------
// File information.

// Name:      p10978-Let's Play Magic
// Purpose:   UHunt-Practice
// License:   MIT
// Revision:  250321

//--------------------------------------------------------------------
// Standard Libraries
#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Debug Macro
#define FORE(i,w) for(__typeof(w.begin())i=w.begin();i!=w.end();++i)
#define DBG cerr << "debug here" << endl;
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define dee(w) {cerr<<#w<<" = ";FORE(i,w)cerr<<*i<<", ";cerr<<"\n";}

//--------------------------------------------------------------------
// Main Functions

int main(){

	ios_base::sync_with_stdio(false); //fast input and output
	cin.tie(NULL); //flush output
	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	while(cin >> n && n){
		vector<string> v(n);
		string name, word;
		int indx = -1;
		for(int i = 0; i < n; i++){
			cin >> name >> word ;
			int sz = word.size();
			while(sz){
				indx = (1+indx) % n;	// Important Calculation Step
				if(v[indx] == "")
					--sz;
			}
			v[indx] = name;
		}
		for(int j = 0; j < n; j++)
			cout << v[j] << (j+1<n ? ' ':'\n');
	}

	return 0;
}

//--------------------------------------------------------------------
// Write Up
//
// Problem was basically to cycle thru the array with the increment
// amount given as per problem.
// Common mistake was jumping directly to the size while problem meant
// jumping that amount of empty spaces.
// Another Important observation was to cycle thru array that is hand-
// -led by Code quite well.
//
//--------------------------------------------------------------------
// EOF