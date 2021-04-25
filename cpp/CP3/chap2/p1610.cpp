//--------------------------------------------------------------------
// File information.

// Name    :   1610 - Party Games
// Purpose :   Uhunt - Practice
// License :   MIT
// Revision:   210411
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>

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
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    char s[1024];

    while(cin >> n && n){
        vector< string> A;
        for(int i = 0; i < n; i++){
            cin >> s;
            A.pb(s);
        }

        sort(A.begin(), A.end());

        string p = A[n/2-1], q = A[n/2];
        // since n - even so there is no exact median

        // logic decision on selecting median

        if(p.length() < q.length()){
            // operate on smaller string
            for(int i = 0; i < p.length(); i++){
                // printing as long as we deplete p
                // or p and q have same character
                if(p[i] == q[i] || i == p.length()-1)
                    //equal size strings are printed
                    putchar(p[i]);
                else {
                // less is answer since we want smallest string
                // for comparision
                    putchar(p[i]+1);
                    break;
                }
            }
        } else {
            for(int i = 0; i < q.length(); i++){
                if(p[i] == q[i])
                    putchar(p[i]);
                else {
                    if( i == q.length()-1 ){
                        if( i == p.length()-1){
                            // equal strings
                            putchar(p[i]);
                            break;
                        }
                        if( p[i] + 1 != q[i]){
                            putchar(p[i]+1);
                            break;
                        } else {
                            putchar(p[i]);
                            for(int j = i+1; j < p.length(); j++){
                                if(j == p.length() - 1)
                                    putchar(p[j]);
                                else if(p[j] != 'Z'){
                                    putchar(p[j]+1);
                                    break;
                                } else putchar(p[j]);
                            }
                            break;
                        }
                    } else {
                        putchar(p[i] + 1);
                        break;
                    }
                }
            }
        }
        puts("");

    }

    return 0;
}

//--------------------------------------------------------------------
// Write Up

// Problem is basically given a list of strings find the median string
// also that string should be of minimum size

// Decision on the strings to be carefully taken

//--------------------------------------------------------------------
// EOF