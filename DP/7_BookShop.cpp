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

// int solve(int ind,int amt, vector<int> &pages, vector<int> &price, vector<vector<int>> &dp)
// {
//     if(ind >= price.size()) return 0;
//     if(amt <= 0)    return 0;

//     if(dp[amt][ind] != -1)  return dp[ind][amt];
//     int take = 0, dont = 0;
//     if(price[ind] <= amt) take = pages[ind] + solve(ind+1,amt-price[ind],pages,price,dp);
//     dont = solve(ind+1,amt,pages,price,dp);

//     return dp[amt][ind] = max(take,dont);
// }
void solve()
{
    int n,x;
    cin>>n>>x;

    vector<int> price(n), pages(n);

    forn(n) cin>>price[i];
    forn(n) cin>>pages[i];

    vector<vector<int>> dp(x+1,vector<int>(n+1,-1));

    // int ans = solve(0,x,pages,price,dp);
    // cout<<ans<<endl;
    int ans = 0;
    for(int i=0;i<n;i++)    dp[0][i] = 0; //for money 0 all will be 0
    for(int i=0;i<=x;i++)   dp[i][n] = 0; //for no book, all will be 0
    
    for(int i=0;i<=x;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(price[j] <= i)
            {
                dp[i][j] = max((pages[j] + dp[i-price[j]][j+1]), dp[i][j+1]);
                ans = max(ans,dp[i][j]);
            }
        }
    }

    cout<<ans<<endl;

}

int32_t main()
{
    
    init();
    solve();
    
    return 0;
}
