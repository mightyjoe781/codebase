//--------------------------------------------------------------------
// File information.

// Name    :   The Efficient Janitor
// Purpose :   Compre Lab : Q1
// License :   MIT
// Revision:   210430
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

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
    // IO
    int n;
    cin >> n;
    vector<double> data(n);
    for(int i = 0; i < n; i++)
        cin >> data[i];

    // Sort the data.
    sort(data.begin(), data.end());
    int i = 0, j = n-1, cnt = 0;

    //Using 2-pointers!
    while( i < j){
        if(data[i]+data[j] <= 3.00)
            { cnt++; i++; j--; }
        else
            { cnt++; j--; }
    }
    if(i == j)
        cnt++;
    cout << cnt << endl;

    return 0;
}

//--------------------------------------------------------------------
// EOF