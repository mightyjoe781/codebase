//--------------------------------------------------------------------
// File information.

// Name    :   11933 - Splitting Numbers
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210413
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <iostream>
#include <cstdio>
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
    while(scanf("%d",&n) && n){
        bool arr[32];
        int a = 0, b = 0;
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            if(n & (1<<i)){
                if(cnt++ & 1) b += n & (1 << i);
                else a += n & (1 << i);
            }
        }
        cout << a << " " << b << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// Write Up

// Problem is quite simple just keeping track of which bit is on
// Its just traversing through the whole number and keeping the track
// of whether we are turning the odd or even bit.
