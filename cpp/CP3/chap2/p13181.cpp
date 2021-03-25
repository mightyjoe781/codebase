//--------------------------------------------------------------------
// File information.

// Name:      13181-Sleeping in hostels
// Purpose:   Uhunt Practice
// License:   MIT
// Revision:  210325

//--------------------------------------------------------------------
// Standard Libraries
#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Main Functions
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string s;
    while(cin >> s){
        int n = s.size();
        int ans = 0;
        int prev = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'X'){
                if(prev == -1){
                    ans = max(ans,i-1);
                    prev = i;
                } else {
                    ans = max(ans,(i-prev-2)/2);
                    prev = i;
                }
            }
        }
        if(prev != n-1)
            ans = max(ans,n-prev-2);
        cout << ans << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// Write-Up
// Problem was basically finding the middle dot inside the pair of two
// X's
// Code's ingenuity is the way it handles the edge case of only 1 X
// without adding any extra lines.

//--------------------------------------------------------------------
// EOF