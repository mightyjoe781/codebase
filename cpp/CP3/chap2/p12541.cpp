//--------------------------------------------------------------------
// File information.

// Name    :   12541 - Birthdates
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210402
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//--------------------------------------------------------------------

struct data
{
   string name;
   int d,m,y;
   data(string s,int day,int month,int year){
    name = s; d = day; m = month; y = year;
   };
};
typedef data *link;

//--------------------------------------------------------------------
// Main functions

int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    int sz = t-1;
    vector<link> v;
    while(t--){
        string str;
        int date,month,year;
        cin >> str >> date >> month >> year;
        v.push_back(new data(str,date,month,year));
    }
    sort(v.begin(),v.end(), [] (const link lhs, const link rhs)
    {
        if(lhs->y == rhs->y){
            if(lhs->m == rhs->m){
                if(lhs->d == rhs->d){
                    return lhs->name < rhs->name;
                }
                else return lhs->d < rhs->d;
            }
            else return lhs->m < rhs->m;
        }
        else
            return lhs->y < rhs->y;
    });

    cout << v[sz]->name << endl << v[0]->name << endl;
    return 0;
}

//--------------------------------------------------------------------
// Write Up

// Don't laugh at the implementation its just good for practicing
// Structs jk :)
//
// Better approach would have been ( only because of bounded input )
// create a integer x = yyyy*10000+mm*100+dd
// this integer converts 3 integer into 1 single integer
//
// now we can easily find max/min.

//-------------------------------------------------------------------
//EOF