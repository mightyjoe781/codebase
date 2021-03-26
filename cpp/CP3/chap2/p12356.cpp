//--------------------------------------------------------------------
// File information.

// Name:      12356 - Army Buddies
// Purpose:   UHunt - Practice
// License:   MIT
// Revision:  210325
// Author:    smk (Sudhanshu Mohan Kashyap)

//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Global Variables

int ls[1000100];
int rs[1000100];

//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false); //fast input and output
    cin.tie(NULL); //flush output
    //online judge config
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int s,b;
    while(cin>>s>>b && s && b){
        for(int i = 0; i < s+1; i++){
            ls[i] = i-1;
            rs[i] = i+1;
        }
        while(b--){
            int l,r; cin>>l>>r;
            string ans = "";
            if(ls[l] < 1) ans+= "*"; else ans+= to_string(ls[l]);
            ans += " ";
            if(rs[r] > s) ans+= "*"; else ans+= to_string(rs[r]);
            ls[rs[r]] = ls[l];
            rs[ls[l]] = rs[r];
            cout << ans<<endl;
        }
        cout << '-' << endl;
    }


    return 0;
}

//--------------------------------------------------------------------
// Write Up

// Basically using range to go in left and right direction is  too
// slow for the problem constraints.
// First read assumption carefully which indicates that there is no
// intersection query.that means we don't need to worry about trave-
// -rsing the array in either direction. Rather we should  maintain
// these arrays to store the next soldier alive in left and right
// direction respectively
// ls[l] query means leftmost soldier which is alive
// rs[x] query means the rightmost soldier that is alive
// ls : -1, 0, 2, 3, ... , 9
// rs :  1, 2, 3, 4, ... , 11
// real magic comes from assumption so we can safely update the links
// without worry about the soldier alive in mid
// say 2, 5
// ls[rs[5]] = ls[2];
// rs[5] means its right most neighbour that is 6 so we are basically
// setting up ls[6] to point to wherever left of 2 lies :)
//                         <--|
// ls : -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// after update
//              <-------------|
// ls : -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// so now query for ls[6] should give 1 solving the problem
// try doing on same for rs array

//--------------------------------------------------------------------
// EOF