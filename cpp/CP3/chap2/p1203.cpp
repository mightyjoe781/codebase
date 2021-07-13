//--------------------------------------------------------------------
// File information.

// Name    :   1203 - Argus
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210518
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Main functions
typedef pair<int,int> pii;

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    int q,t,n;
    priority_queue<pii, vector<pii>, greater<pii>> minq;
    unordered_map<int,int> m;
    while(cin >> s){
        if(s == "Register"){
            cin >> q >> t;
            m[q] = t;
            minq.push({t,q});
        } else break;
    }
    cin >> n;

    while(n--){
        pii x = minq.top(); minq.pop();
        minq.push({x.first+m[x.second],x.second});
        cout << x.second << endl;
    }
    return 0;
}
