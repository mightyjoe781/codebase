//--------------------------------------------------------------------
// File information.

// Name    :   Richness of special subset
// Purpose :   Compre-Lab 2
// License :   MIT
// Revision:   210430
// Author  :   smk

//--------------------------------------------------------------------
// Standard Libraries

#include <bits/stdc++.h>
using namespace std;
#define ll long long
//--------------------------------------------------------------------
// Main functions
ll n;
struct node
{ ll item; node *l,*r;
  node(ll x)
  { item = x; l=0; r=0;}
};
typedef node * link;
struct Info {
    int max;
    int min;
    bool isBST;
    int sum;
    int currmax;
};
void tree_maker(link root,vector<ll>& v){
    ll cnt = 0;
    queue<link> q;
    q.push(root);
    link cur = nullptr;
    // constructing the tree!
    for(int i = 1; i < n; i++){
        link t = new node(v[i]);
        if(cnt == 0){
            cur = q.back();
            q.pop();
        }
        if(cnt == 0){
            cnt++;
            cur->l = t;
        } else {
            cnt = 0;
            cur->r = t;
        }
        if(v[i] != -9999999)
            q.push(t);
    }
}
void dfs(link s){
    if(!s) return;
    cout << s->item << " ";
    dfs(s->l);
    dfs(s->r);
}
bool isBST(link node){
    if(node) return 1;

    if(node->l != NULL && node->l->item > node->item)
        return 0;

    if(node->r != NULL && node->r->item < node->item)
        return 0;

    if(!isBST(node->l) || !isBST(node->r))
        return 0;

    return 1;
}
int sumBST(link root) {
    if(root == nullptr)
        return 0;
    return (root->item + sumBST(root->l) + sumBST(root->r));
}

int solve(link root) {
    if(isBST(root))
        return sumBST(root);
    else
        return max(solve(root->l),solve(root->r));
}
int main(){

    ios_base::sync_with_stdio(false);   //Fast input and output
    cin.tie(NULL);                      //Flush output
    #ifndef ONLINE_JUDGE                //Online judge config
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];


    link root = new node(v[0]);
    tree_maker(root,v);

    cout << solve(root) << endl;

    return 0;
}
