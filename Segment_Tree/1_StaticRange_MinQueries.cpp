#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ull unsigned long long
#define ll long long 
#define forn(n) for (int i = 0; i < int(n); i++)
#define pb push_back
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

int mod = 1e9+7;
struct node{
    int val;
    node()
    {
        val = 0;
    }
};
int tree[8*100000];
int merge(node a, node b)
{
    return min(a.val,b.val);
}
void build(int id,int l,int r,vector<int> &arr)
{
    if(l == r)
    {
        tree[id] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*id+1,l,mid,arr);
    build(2*id+2,mid+1,r,arr);

    tree[id] = min(tree[2*id+1],tree[2*id+2]);
}
int query(int id,int l,int r, int lq,int rq)
{
    if(lq>r || rq<l)    return 1e9; //no overlap
    else if(l>=lq && r<=rq) return tree[id];
    else
    {
        int mid = (l+r)/2;
        int lt = query(2*id +1, l,mid,lq,rq);
        int rt = query(2*id +2,mid+1,r,lq,rq);
        return min(lt,rt);
    }
}
void init()
{
    fast_cin();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);     //opened in reading mode
    // freopen("output.txt","w",stdout);  //opened in writing mode 
    // #endif
}


void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);

    forn(n) cin>>arr[i];

    // forn(n) cout<<arr[i]<<"--\n";
    build(0,0,n-1,arr); // initialise the segment tree
    vector<pair<int,int>> ans(q);
    // for(int i=0;i<80000;i++)
        // cout<<i<<" - "<<tree[i]<<endl;
    int l,r;
    forn(q)
    {
        cin>>l>>r;
        // int anss = query(0,0,n-1,l-1,r-1);
        ans[i] = {l,r};
    }
    forn(q)
    {
        cout<<query(0,0,n-1,ans[i].first-1,ans[i].second-1)<<endl;
    }
    // for(auto x:ans) cout<<x<<endl;
}

int32_t main()
{
    
    init();
    solve();
    
    return 0;
}
