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
    int n;
    cin>> n;

    vector<vector<char>> arr(n,vector<char>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    if(arr[n-1][n-1] == '*' || arr[0][0] == '*')
    {
        cout<<"0"<<endl;
        return;
    }

    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arr[i-1][j-1] != '*' && (i>1 || j>1))
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            // cout<<i<<" "<<j<<" : "<<dp[i][j]<<" "<<arr[i-1][j-1]<<endl;
            
            // cout<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][n]<<endl;

}

int32_t main()
{
    
    init();
    solve();
    
    return 0;
}
