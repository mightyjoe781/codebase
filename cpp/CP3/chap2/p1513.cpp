//--------------------------------------------------------------------
// File information.
// Name    :   p1513 - Movie Collection
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210530
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries and Macros
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define dbg(vari) cerr << #vari<< " = "<< (vari) <<endl;

//--------------------------------------------------------------------
// Fenwick Tree Implementation
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

//--------------------------------------------------------------------
// Main function.
int maxN = 100000+10;
int main() {
    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int pos[maxN];
        int n, m;
        cin >> n >> m;
        // Create Fenwick Tree.
        FenwickTree ft(n+m);
        for(int i = 1; i <= n; i++){
            pos[i] = n-i+1;
            ft.add(i,1);
        }

        // Answer Queries.
        int tot = n;
        FOR(i,m){
            int x;
            cin >> x;
            cout << n - ft.sum(pos[x]);
            ft.add(pos[x],-1);
            ft.add(++tot,1);
            pos[x] = tot;
            if(i < m-1) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}
//--------------------------------------------------------------------
// Write Up

// To better understand solve Problem : Counting number of inversion
// using the fenwick tree.
// This requires maintaining a frequency DAT which is marked as how
// many occurence of the item occur.
// Similarly here we indicate the same using pos array.

// This is exactly same problem, when we pick out a cd we remove its
// count from the fenwick tree and put it behind int pos array
// and increment the fenwick tree index at that position.
