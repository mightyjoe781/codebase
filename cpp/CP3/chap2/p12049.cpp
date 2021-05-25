//--------------------------------------------------------------------
// File information.

// Name    :   12049 - Just Prune the List
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

    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        unordered_multiset<int> s1;
        unordered_multiset<int> s2;
        int tmp;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            s1.insert(tmp);
        }

        for(int i = 0; i < m; i++){
            cin >> tmp;
            auto itr = s1.find(tmp);
            if(itr!=s1.end())
                s1.erase(itr);
            else
                s2.insert(tmp);
        }
        cout << s1.size() + s2.size() << endl;
    }

    return 0;
}
//--------------------------------------------------------------------
// Write-Up
//
// Just watch out the erase function! erase(val) removes all instance
// of val. while using above itr trick only one element is removed.

//--------------------------------------------------------------------
// EOF
