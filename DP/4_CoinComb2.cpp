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

    vector<int> dp(x+1,0);
    dp[0] = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(coins[i] <= j)
            {
                dp[j] =(dp[j] + dp[j-coins[i]])%mod;
            }
        }
    }
    cout<<dp[x]<<endl;

}

int32_t main()
{
    
    init();
    solve();
    
    return 0;
}
