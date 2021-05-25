//--------------------------------------------------------------------
// File information.

// Name    :   11860 - Document Analyzer
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210524
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries and Macros

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;

//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        chra
        string line;
        cout << t << endl;
        int cnt = 0;
        while(getline(cin >> ws,line)){
            if(line == "END\n") break;
            cout << cnt++ << "-";
            cout << line << endl;
        }
    }

    return 0;
}
