//--------------------------------------------------------------------
// File information.

// Name    :   11423 - Cache Simulator
// Purpose :   Uhunt - Practice
// License :   MIT
// Revision:   210615
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
const int MAXT = (1e+7) + 5;
//--------------------------------------------------------------------
// Main functions
struct BIT {
    int tree[MAXT], n;
    void init(int n) {
        this->n = n;
        memset(tree,0,sizeof(tree[0])*n);
    }
    void add(int x, int val) {
        for (; x < n; x += x&(-x))
            tree[x] += val;
    }
    int query(int x) {
        int ret = 0;
        for (; x; x -= x&x(-x))
            ret += tree[x];
        return ret;
    }
    int query(int l, int r) {
        return query(r) - query(l-1);
    }
} tree;

static const int MAXN = 32;
static const int MAXM = 1<<24;
static int n, miss[MAXN], cache[MAXN];
static int stamp[MAXM], mtime;

void access(int addr) {
    int &st = stamp[addr];
    if (st == 0) {
        FOR(i,n)
            miss[i]++;
    } else {
        int cnt = tree.query(st, mtime);
        for (int i = 0; i < n && cnt > cache[i]; i++)
            miss[i]++;
        tree.add(st, -1);
    }
    st = ++mtime;
    tree.add(st, 1);
}
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif



    return 0;
}
