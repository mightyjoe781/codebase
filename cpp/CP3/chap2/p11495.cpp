//--------------------------------------------------------------------
// File information.

// Name    :   11495 - Bubbles and Buckets
// Purpose :   UHunt - Practices
// License :   MIT
// Revision:   210412
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <iostream>
using namespace std;
typedef long long ll;
const ll maxN = 1000000;
//--------------------------------------------------------------------
// Main functions
// merging step
ll merge(ll a[],ll lo,ll mid, ll hi){

    ll inv = 0;
    static ll aux[maxN];
        // copy to aux[]
        for (ll k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }

        // merge back to a[]
        ll i = lo, j = mid+1;
        for (ll k = lo; k <= hi; k++) {
            if      (i > mid)           a[k] = aux[j++];
            else if (j > hi)            a[k] = aux[i++];
            else if (aux[j] < aux[i]) { a[k] = aux[j++]; inv += (mid - i + 1); }
            else                        a[k] = aux[i++];
        }
    return inv;
}
// actual sort
ll mergesort(ll a[],ll l, ll r){
    ll inv = 0;
    if(r<=l) return 0;
    ll m = l+(r-l)/2;
    inv += mergesort(a,l,m);
    inv += mergesort(a,m+1,r);
    inv += merge(a,l,m,r);
    return inv;
}

ll bubSort(ll a[], ll l, ll r){
    ll cnt = 0;
    for(ll i = l; i < r ; i++)
        for(ll j = r; j > i; j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
                cnt++;}
        }
    return cnt;
}
int main(){

    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll n;
    while(cin >> n && n){
        ll arr[n];
        for(ll i = 0; i < n; i++)
            cin >> arr[i];
        ll exc2 = mergesort(arr,0,n-1);
        if(exc2&1) cout << "Marcelo";
        else cout << "Carlos";
        cout << endl;
    }

    return 0;
}
