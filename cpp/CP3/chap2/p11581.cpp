//--------------------------------------------------------------------
// File information.

// Name    :   11581 - Grid Successors
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210326
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Main functions

int arr[3][3];
void f(){
    int h[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int sum = 0;
            if(i > 0) sum+= arr[i-1][j];
            if(i < 2) sum+= arr[i+1][j];
            if(j > 0) sum+= arr[i][j-1];
            if(j < 2) sum+= arr[i][j+1];
            h[i][j] = sum%2;
        }
    }
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            arr[i][j] = h[i][j];

}

bool empty(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(arr[i][j]!=0)
                return false;
    return true;
}
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    string s;
    while(t--){
        //-----------------------------------
        // Taking input (stupid way)
        // note should have used the printf("%1d",&x);
        // above function scans only 1 digit

        vector<string> v(3);
        for(int i = 0; i < 3; i++)
            cin >> v[i];

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                arr[i][j] = v[i][j]-'0';

        int ans = -1;

        while(!empty()){
            f();
            ans++;
        }
        cout << ans << endl;
        v.clear();
    }
    return 0;
}

//--------------------------------------------------------------------
// Write Up

// Simulate what is given in question
// Basically recursively follow the adjacent neighbour sum untill the
// array becomes all zero

//--------------------------------------------------------------------
// EOF