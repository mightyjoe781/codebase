//--------------------------------------------------------------------
// File information.

// Name    :   11286 - Conformity
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


    int n;
    while(cin>>n && n){
        map<vector<int> , int> m;
        int maxm = 1;
        while(n--){
            vector<int> v(5);
            for(int i = 0; i < 5; i++)
                cin >> v[i];
            sort(v.begin(),v.end());
            m[v] += 1;
            maxm = max(maxm,m[v]);
        }
        int tot = 0;
        for(auto it : m)
            if(maxm == (it).second)
                tot += (it).second;

        cout << tot << endl;
    }

    return 0;
}
//--------------------------------------------------------------------
// Write Up
//
// Basically find the vector that occurs most in case of tie count
// them all.
// Statement is not that clear in question.

// EOF
