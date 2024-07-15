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
    int n,x;
    cin>>n>>x;

    vector<int> coins(n);
    forn(n) cin>>coins[i];

    vector<int> dp(x+1,1e9);
    dp[0] = 0; //base

    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j] <= i)
            {
                dp[i] = min(dp[i],1 + dp[i-coins[j]]);
            }
        }
    }
    int ans = (dp[x] >= 1e9 ? -1 : dp[x]);
    cout<<ans<<endl;

}

int32_t main()
{
    
    init();
    solve();
    
    return 0;
}
