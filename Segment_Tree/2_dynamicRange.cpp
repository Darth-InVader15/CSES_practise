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

int tree[800000];

void build(int ind,int l,int r,vector<int> &arr)
{
    if(l == r)
    {
        tree[ind] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*ind +1,l,mid,arr);
    build(2*ind +2,mid+1,r,arr);

    tree[ind] = tree[2*ind +1] + tree[2*ind +2]; //sum
}
void update(int ind,int l,int r,int pos,int val)
{
    if(l == r)
    {
        if(r == pos)    tree[ind] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*ind +1,l,mid,pos,val);
    update(2*ind +2,mid+1,r,pos,val);

    tree[ind] = tree[2*ind +1] + tree[2*ind +2];
}
int query(int ind,int l,int r,int lq,int rq)
{
    if(lq>r || rq<l)    return 0; //no overlap
    else if(l>=lq && rq>= r)    return tree[ind]; //complete overlap
    else //partial overlap
    {
        int mid = (l+r)/2;
        int lt = query(2*ind +1,l,mid,lq,rq);
        int rt = query(2*ind +2,mid+1,r,lq,rq);

        return (lt+rt);
    }    
}
void solve()
{
    int n,q;
    cin>>n>>q;
    
    vector<int> arr(n);
    forn(n) cin>>arr[i];

    build(0,0,n-1,arr);

    vector<int> qu(3);
    while(q--)
    {
        cin>>qu[0]>>qu[1]>>qu[2];
        
        if(qu[0] == 1)
        {
            update(0,0,n-1,qu[1]-1,qu[2]);
        }
        else
        {
            cout<<query(0,0,n-1,qu[1]-1,qu[2]-1)<<endl;
        }
    }
}

int32_t main()
{
    
    fast_cin();
    solve();
    
    return 0;
}
