//--------------------------------------------------------------------
// File information.

// Name    :   11462 - Age Sort
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210411
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <iostream>
using namespace std;

typedef long long ll;

//--------------------------------------------------------------------
// Main functions
int partition(int a[],ll l,ll r){
   ll i = l-1, j = r; int v = a[r];
   for(;;){
    while(a[++i] < v);
    while(v < a[--j]) if(j == l) break;
    if(i >= j) break;
    swap(a[i],a[j]);
   }
   swap(a[i],a[r]);
   return i;
}

void smksort(int a[],ll l,ll r){
    // any n^2 sorting algo will   fail
    // best case use nlogn algorith
    // implementation of quicksort
    if(r <= l) return;
    ll i = partition(a,l,r);
    smksort(a,l,i-1);
    smksort(a,i+1,r);
}
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n;
    while(cin >> n && n){
        int arr[n];

        for(int  i = 0; i < n; i++)
            cin >> arr[i];

        // write the sort function that works on duplicates also
        // refer to algo.minetest.in

        smksort(arr,0,n-1);

        for(ll  i = 0; i < n-1; i++)
            cout << arr[i] << " ";
        cout << arr[n-1] << endl;
    }

    return 0;
}
