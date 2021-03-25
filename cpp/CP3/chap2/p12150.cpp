//--------------------------------------------------------------------
// File information.

// Name:     12150-Pole Position
// Purpose:  UHunt Practice
// License:  MIT
// Revision: 210325

//--------------------------------------------------------------------
// Standard Libraries
#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Main functions
void solve(int n){
        int arr[n] = {0};
        int c, p;
        int cnt = 0;
        bool flag = true;
        for(int i = 0; i < n; i++){
            cin >> c >> p;
            if(cnt + p < n && cnt+p >=0 && arr[cnt+p] == 0 ){
                arr[cnt+p] = c;
                cnt++;
            } else {
                flag = false;
            }
        }
        if(flag){
            for(int i = 0; i < n-1 ; i++)
                cout << arr[i] << " ";
            cout << arr[n-1];
        } else {
            cout << "-1" ;
        }
}
int main(){

    ios_base::sync_with_stdio(false); //fast input and output
    cin.tie(NULL); //flush output
    //online judge config
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    while(cin >> n && n){
        solve(n);
        cout << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// Write Up
//
// This problem was basically to consider current order as scoreboard
// then figuring out the original ranking of cars.
// Important thing about this question is to remeber about the out of
// index array access.
//
//--------------------------------------------------------------------
// EOF