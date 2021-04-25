//--------------------------------------------------------------------
// File information.

// Name    :   10107 - What is the Median
// Purpose :   UHunt - Practice
// License :   MIT
// Revision:   210329
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <cstdio>
#include <iostream>
#include <queue>
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

    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // max heap declaration stores smaller half elements
    priority_queue<long long> s;
    // min heap declaration stores larger half elements
    priority_queue<long long , vector<long long>,
     greater<long long>> g;
    // greater flag actually creates a min heap
    // bydefault PQs are max heap type
    long long x;
    cin >> x;
    long long med = x;
    s.push(x);
    printf("%d\n",med);
    while(cin >> x){
        // case 1 left heap has more elements
        if(s.size() > g.size()){
            if(x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
            med = (s.top() + g.top()) /2;
        }

        // case 2 equal size heaps
        else if (s.size() == g.size())
        {
            if(x < med)
            {
                s.push(x);
                med = s.top();
            }
            else
            {
                g.push(x);
                med = g.top();
            }
        }

        //case 3 right side heap has more elements
        else
        {
            if( x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);

            med = (s.top() + g.top())/2;
        }

        printf("%d\n", med);
    }

    return 0;
}

//--------------------------------------------------------------------
// Write Up
//
// Also use long long integers
//
// Hmm well this problem can be solved in many ways
// Once simple way is to store in array -> sort the array then boom
// Since thats too obvious we will try to do it other way
//
// Use Max-Min Heap to solve the problem as Solving Running Median of
// of a stream
// Read up on Heaps from notes :
//
// Maintain 2 heaps, max heap stores the min elements ( so its top
// has the max elements at its root) (left side median data)
// second heap is min heap whose root elements is smallest in that
// heap ( right side of median data)
// finding median is just average of the top of the both heaps
//
// There is a 3 posibility of insertion
// when right heap is smaller in size
// check if given element is larger than than root at left heap ( max
// heap ) if it is we sent it right ( min heap )
// in case it is not then we send in to max heap on left but we try
// to keep both heaps balanced so that means that one element from
// max heap should go to min heap so as to keep the size of both heap
// -s same

// Another cases are quite intuitive to implement


// Related Problem : Famous problem of finding the median of two
// arrays.
//--------------------------------------------------------------------
// EOF