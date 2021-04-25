//--------------------------------------------------------------------
// File information.

// Name    :   13048 - Burger Stand
// Purpose :   UHunt Practice
// License :   MIT
// Revision:   210326
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
    int c = 0;
    while(c++<t){
        string s; cin >> s;
        int n = s.size();
        bool arr[n] = {false};

        for(int i = 0; i < n; i++){
            if(s[i] == 'B' || s[i] == 'S' || s[i] == 'D')
                arr[i] = true;
        }
        for(int i = 1; i < n; i++){
            if(s[i] == 'B'){
                arr[i-1] = true;
                if(i > 1)
                    arr[i-2] = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] == 'S'){
                if(i > 0)
                    arr[i-1] = true;
                if(i < n - 1)
                    arr[i+1] = true;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n; i++)
            if(arr[i] != 1)
                ans++;

        cout << "Case " << c << ": " << ans << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// Write Up

// Made a boolean array marking 1 wherever i can't place my stand
// and 0 at feasible location
// then just with loops marked the spots where i can't mark
// just keep track of indices while creating solution
// Pretty simple question

//--------------------------------------------------------------------
// EOF