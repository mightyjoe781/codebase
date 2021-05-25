//--------------------------------------------------------------------
// File information.

// Name    :   12650 - Dangerous Dive
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

    int n,r;
    while(cin >> n >> r){
        bool arr[n+1] = {false};
        int tmp;
        for(int i = 0; i < r; i++){
            cin >> tmp;
            arr[tmp] = true;
        }
        if(n == r){
            cout << '*' << endl;
            continue;
        }
        for(int i = 1; i <= n; i++)
            if(!arr[i])
                cout << i << " ";
        cout << endl;
    }

    return 0;
}
//--------------------------------------------------------------------
// EOF