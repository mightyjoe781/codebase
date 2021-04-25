//--------------------------------------------------------------------
// File information.

// Name    :   11360 - Have Fun with Matrices
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210329
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

//--------------------------------------------------------------------
// Main functions

// processing functions
void process(int a[][10],int n, string cmd){

    if(cmd == "transpose")
    {
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                swap(a[i][j],a[j][i]);
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cmd == "inc")
                a[i][j] = (a[i][j]+1)%10;
            if(cmd == "dec")
                a[i][j] = (10+a[i][j]-1)%10;
        }
    }
}
int main(){

    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int cases = 0;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[10][10];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%1d",&arr[i][j]);

        int m; cin >> m;
        while(m--){
            string cmd; cin >> cmd;
            if(cmd == "row" || cmd == "col"){
                int a, b; cin >> a >> b;
                int dir = 0;        // dir = 0 means row
                if(cmd == "col") dir = 1;
                for(int i = 0; i < n; i++){
                    if(dir)
                        swap(arr[i][a-1],arr[i][b-1]);
                    else
                        swap(arr[a-1][i],arr[b-1][i]);
                }
            }
            else process(arr,n,cmd);
        }

        cout << "Case #" << ++cases << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
