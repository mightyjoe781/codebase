//--------------------------------------------------------------------
// File information.

// Name    :   417 - Word Index
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210521
// Author  :   smk
//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s, ss;
    char ch;
    int sl = 1;
    map<string,int> mp;
    queue<string> q;
    for(ch = 'a'; ch <='z'; ch++){
        s = ch;
        q.push(s);
    }
    // q = {a,b,c ... z}
    // q = {b,c ... z, ab,ac,ad,...az}
    // ...
    int t = 83700;
    while(t--){
        ss = q.front();
        for(ch = ss[ss.size()-1]+1; ch <='z'; ch++){
            s = ss;
            s+= ch;
            q.push(s);
        }
        mp[ss] = sl;
        sl++;
        q.pop();
    }
    while(cin >> s){
        cout << mp[s] << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// Write Up
//

// Precompute all pairs before hand to get O(1) query time
// EOF