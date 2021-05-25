//--------------------------------------------------------------------
// File information.

// Name    :   10815 - Andy's first dictionary
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210523
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

//--------------------------------------------------------------------
// Main functions
bool valid(char c){
    return (c >='a' && c <= 'z');
}

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string line;
    set<string> s;
    while(cin >> line){
        string word = "";
        for(auto c:line){
            c = tolower(c);
            if(valid(c)){
                word+=c;
            } else if(word!="") {
                std::transform(word.begin(), word.end(), word.begin(),
    [](unsigned char c){ return std::tolower(c); });
                s.insert(word);
                word = "";
            }
        }
        if(word!="") s.insert(word);
        // cout << line << endl;
    }
    for(auto x: s)
        cout << x << endl;

    return 0;
}
