//--------------------------------------------------------------------
// File information.

// Name    :   12667 - Last Blood
// Purpose :   Uhunt - Practice
// License :   MIT
// Revision:   210327
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

    int n, t, m;
    cin >> n >> t >> m;

    int  arr[m][2];
    string s[m][2];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < 2; j++)
            cin >> arr[i][j];
        for(int j = 0; j < 2; j++)
            cin >> s[i][j];
    }

    char ch = 'A';
    int cnt = 0;
    while(cnt++ < n){
        vector< int > solv(t+1,-1);
        for(int i = 0; i < m ; i++){
            if(s[i][0][0] == ch && s[i][1] == "Yes" && solv[arr[i][1]]
                == -1){
                solv[arr[i][1]] = arr[i][0];
            }
        }
        int solv_team = -1;
        int solv_time = -1;
        for(int i = 1; i <= t; i++)
            if(solv[i]!=-1 && solv[i] > solv_time){
                solv_time = solv[i];
                solv_team = i;
            }

        if(solv_team != -1 && solv_time != -1)
            cout << ch << " " << solv_time << " " << solv_team;
        else
            cout << ch << " - -";
        cout << endl;
        solv.clear();
        ch++;
    }

    return 0;
}

//--------------------------------------------------------------------
// Write up

// Maintain a DAT Table for the solv - 1st correct attempt by a team
// Problem reduces to finding the min in an array :)

//--------------------------------------------------------------------