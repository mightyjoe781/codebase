//--------------------------------------------------------------------
// File information.

// Name    :   13148 - A giveaway
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

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    set<int> s;
    long arr[21] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144,
     531441,1000000, 1771561, 2985984, 4826809, 7529536, 11390625,
      16777216, 24137569, 34012224,47045881, 64000000,85766121};
    for(auto x: arr)
        s.insert(x);

    long n;
    while(cin >> n && n){
        if(s.find(n)!=s.end())
            cout << "Special" << endl;
        else
            cout << "Ordinary" << endl;
    }

    return 0;
}
//--------------------------------------------------------------------
// EOF