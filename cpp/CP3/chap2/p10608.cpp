//--------------------------------------------------------------------
// File information.

// Name    :   10608 - Friends
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

class DisjointSet{
    public:
    // constructor.
    DisjointSet(int len){
        parent.resize(len);
        size.resize(len);
        for(int i = 0; i < len; i++){
            size[i] = 1;
            parent[i] = i;
        }

        num_components = len;
    }
    void union_(int x, int y){
        int r_x = find_(x);
        int r_y = find_(y);
        if(r_x != r_y){
            if(size[r_x] < size[r_y])
                swap(r_x,r_y);

            parent[r_y] = r_x;
            size[r_x] += size[r_y];
            num_components--;
        }
    }

    int find_(int x){
        while(x != parent[x])
            x = parent[x];
        return x;
    }
    int size_(int x){
        return size[find_(x)];
    }
    int getNumComponents(){
        return num_components;
    }

    private:
    vector<int> parent;
    vector<int> size;
    int num_components;
};

// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        DisjointSet ds(n+1);
        FOR(i,m){
            int a, b;
            cin >> a >> b;
            ds.union_(a,b);
        }
        // find the max size
        int ans = 0;
        FOR(i,n+1){
            ans = max(ans,ds.size_(i));
        }
        cout << ans << endl;
    }

    return 0;
}
