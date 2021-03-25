#include <bits/stdc++.h>
using namespace std;

int main(){
	map<char,int> soundex;

	soundex['B'] = 1;
    soundex['P'] = 1;
    soundex['F'] = 1;
    soundex['V'] = 1;
    soundex['C'] = 2;
    soundex['S'] = 2;
    soundex['K'] = 2;
    soundex['G'] = 2;
    soundex['J'] = 2;
    soundex['Q'] = 2;
    soundex['X'] = 2;
    soundex['Z'] = 2;
    soundex['D'] = 3;
    soundex['T'] = 3;
    soundex['L'] = 4;
    soundex['M'] = 5;
    soundex['N'] = 5;
    soundex['R'] = 6;
    
    soundex['A'] = 0;
    soundex['E'] = 0;
    soundex['I'] = 0;
    soundex['O'] = 0;
    soundex['U'] = 0;
    soundex['Y'] = 0;
    soundex['W'] = 0;
    soundex['H'] = 0;

	ios_base::sync_with_stdio(false); //fast input and output
	cin.tie(NULL); //flush output
	//online judge config
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;
	while(cin>>s){
		char mem = s[0];
		if(soundex[mem])
			cout<<soundex[mem];
		for(int i = 1; i < s.size(); i++){
			if(soundex[s[i]] == 0){
				mem = s[i];
				continue;
			}
			if(soundex[mem] == soundex[s[i]]) continue;
			mem = s[i];
			cout<<soundex[s[i]];
		}
		cout<<endl;
	}

	return 0;
}