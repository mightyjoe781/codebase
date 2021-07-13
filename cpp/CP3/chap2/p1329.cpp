//--------------------------------------------------------------------
// File information.

// Name    :   p1329 - Corporative Network
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
// DisjointSet Class
class DisjointSet{
    public:
    // constructor.
    DisjointSet(int len){
        parent.resize(len);
        dist.resize(len);
        for(int i = 0; i < len; i++){
            dist[i] = 0;
            parent[i] = i;
        }
        num_components = len;
    }
    void union_(int a, int b) {
        // a = find_(a);
        // b = find_(b);
        parent[a] = b;
        dist[a] = abs(a-b)%1000;
        num_components--;
    }

    int find_(int v) {
        if (v != parent[v]) {
            int p = find_(parent[v]);
            dist[v] += dist[parent[v]];
            return parent[v] = p;
        }
        return parent[v];
    }
    int dist_(int x){
        return dist[x];
    }
    int getNumComponents(){
        return num_components;
    }

    private:
    vector<int> parent;
    vector<int> dist;
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
        int n; cin >> n;
        DisjointSet ds(n+1);
        char c;
        while(cin >> c && c!='O'){
            // query
            if(c == 'E'){
                int x; cin >> x;
                ds.find_(x);
                cout << ds.dist_(x) << endl;
            } else {
            // insertion
                int a,b; cin >> a >> b;
                ds.union_(a,b);
            }
        }
    }

    return 0;
}
