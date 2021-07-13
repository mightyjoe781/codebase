//--------------------------------------------------------------------
// File information.

// Name    :   p1197 - The Suspects
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210525
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
// Main functions
class DisjointSet{
    public:
    // constructor.
    DisjointSet(int len){
        parent.resize(len);
        for(int i = 0; i < len; i++)
            parent[i] = i;

        num_components = len;
    }
    void union_(int x, int y){
        int r_x = find_(x);
        int r_y = find_(y);

        parent[r_x] = r_y;
        num_components--;
    }

    int find_(int x){
        while(x != parent[x])
            x = parent[x];
        return x;
    }
    int getNumComponents(){
        return num_components;
    }

    private:
    vector<int> parent;
    int num_components;
};

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    while(cin >> n >> m && n){
        int len = 30007;
        DisjointSet ds(len);
        while(m--){
            int k; cin >> k;
            vector<int> v(k);
            FOR(i,k) cin >> v[i];
            for(int i = 0;k >1 && i < k-1; i++){
                ds.union_(v[i+1],v[i]);
            }
        }
        int target = ds.find_(0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(ds.find_(i) == target)
                cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
