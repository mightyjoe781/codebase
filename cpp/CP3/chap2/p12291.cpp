//--------------------------------------------------------------------
// File information.

// Name    :   12291 - Polyomino Composer
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210329
// Author  :   smk
// Credits :   https://github.com/lamphanviet

//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;

//--------------------------------------------------------------------
// Macro Utility-1

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second

//--------------------------------------------------------------------
// Global Variables

int n, m, r, c;             // nxm and rxc 2 matrices
char s[15][15],a[15][15];   // overhead even tho max bound is 10

//--------------------------------------------------------------------
// Sovler Functions

pii findFirst(char s[15][15], int n, int m){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(s[i][j] == '*')
                return (pii(i,j));

    return pii(-1,-1);
}

bool isInside(int x, int y) {return (0<= x && x <n && 0<= y && y<m);}

bool solve(){
    vpii p;     // see the discription of p vector below
    pii fa = findFirst(a,r,c);
    for(int i = 0; i <r; i++)
        for(int j = 0; j <c; j++)
            if(a[i][j] == '*')
                p.pb(pii(i-fa.fi, j - fa.se));

    int x,y;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(s[i][j] == '*')
                for(int k = 0; k < p.size(); k++){
        // for each star in the given Polyomino, we pick up our p
        // vector. Now we process the relative distances to see
        // the matching status.
        // Keep track of not going out of bound
                    x = i + p[k].fi;
                    y = j + p[k].se;
                    if(!isInside(x,y) || s[x][y] != '*')
                        return false;
                    s[x][y] = '.';
                }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(s[i][j] == '*') return false;
    return true;
}

//--------------------------------------------------------------------
// Main functions


int main(){

    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    while(scanf("%d %d ",&n, &r)&& (n||r) ){

        for(int i = 0; i < n; i++)
            gets(s[i]);
        for(int i = 0; i < r; i++)
            gets(a[i]);

        m = strlen(s[0]);
        c = strlen(a[0]);

        if(solve()) puts("1");
        else puts("0");
    }
    return 0;
}

//--------------------------------------------------------------------
// Write Up

// Vector P stores up all the relative distances of the next stars
// with respect to the first star:processing on pattern to be matched
// v = [(0,0) ,(0,1), (1,1), (1,2)];
// See the remaining description in the solve function
//

//--------------------------------------------------------------------
// EOF
