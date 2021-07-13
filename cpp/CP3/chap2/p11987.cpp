//--------------------------------------------------------------------
// File information.

// Name    :   11987 - Almost Union-Find
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
// Disjoint Set Class
// class DisjointSet{
//     public:
//     // constructor.
//     DisjointSet(int len) {
//         parent.resize(len);
//         size.resize(len);
//         for(int i = 0; i < len; i++){
//             size[i] = 1;
//             parent[i] = i;
//         }

//         num_components = len;
//     }
//     void union_(int x, int y){
//         x = find_(x);
//         y = find_(y);
//         if(x != y){
//             size[y] += size[x];
//             parent[x] = y;
//             num_components--;
//         }
//     }
//     void move_(int x,int y){
//         int x_r = find_(x);
//         int y_r = find_(y);
//         if(x_r != y_r){
//             ++size[y_r];
//             --size[x_r];
//             parent[x] = y_r;
//         }
//     }

//     int find_(int x){
//         if(parent[x] == x) return x;
//         return parent[x] = find_(parent[x]);
//     }
//     int size_(int x){
//         return size[x];

//     }
//     int getNumComponents(){
//         return num_components;
//     }

//     private:
//     vector<int> parent;
//     vector<int> size;
//     int num_components;
// };
// Main functions
int p[2000001],r[2000001],mapped[2000001];
long long s[2000001];
void init(int n){
    static int i;
    for(i = 0; i <= n; i++){
        p[i] = i, s[i] = 0, r[i] = 1;
        mapped[i] = i;
    }
}
int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}
void joint(int x, int y, int i, int j){
    if( x == y )
        return;
    s[x] += s[y];
    s[x] += r[y];
    s[y] = r[y] = 0;
    p[y] = x;
}
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m, op, i, j, t, x, y;
    while(cin >> n >> m){
        // DisjointSet ds(n+1);
        // FOR(i,m){
        //    int cmd; cin >> cmd;
        //    int p,q;
        //    if(cmd == 1 || cmd == 2){
        //         cin >> p >> q;
        //         if(cmd == 1)
        //             ds.union_(p,q);
        //         if(cmd == 2)
        //             ds.move_(p,q);
        //     } else {
        //         cin >> p;
        //         int target = ds.find_(p);
        //         int sum = 0;
        //         FOR(i,n+1){
        //             if(ds.find_(i) == target)
        //                 sum+=i;
        //         }
        //     cout << ds.size_(target) << " "  << sum << endl;
        //     }
        // }
        init(n+m);
        for(int i = 0; i <= n; i++)
            s[i] = i;
        while(m--){
            cin >> op >> i;
            if(op == 3){
                t = find(mapped[i]);
                cout << r[t] << " " << s[t] << endl;
            } else if(op == 2){
                cin >> j;
                x = find(mapped[i]);
                y = find(mapped[j]);
                if(x != y){
                    s[x] -= i, r[x]--;
                    mapped[i] = ++n;
                    s[mapped[i]] = i;
                    r[mapped[i]] = 1;
                    joint(find(mapped[i]), find(mapped[j]),i,j);
                }
            } else {
                cout << j;
                joint(find(mapped[i]), find(mapped[j]),i,j);
            }
        }
    }

    return 0;
}
