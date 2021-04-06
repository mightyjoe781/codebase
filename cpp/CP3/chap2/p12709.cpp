//--------------------------------------------------------------------
// File information.

// Name    :   12709 - Falling Ants
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210403
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
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

    int t;
    while(cin >> t && t){
        int L,W,H,V,maxV,maxH = 0;
        while(t--){
            cin >> L >> W >> H;
            V = L*W*H;
            if( H > maxH || (H == maxH && V > maxV))
                maxH = H, maxV = V;
        }
        cout << maxV << endl;
    }
    return 0;
}
