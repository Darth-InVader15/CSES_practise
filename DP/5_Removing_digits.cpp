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
    int x;
    cin>>x;

    // vector<int> coins(n);
    // forn(n) cin>>coins[i];

    vector<int> dp(x+1,1e9);
    dp[0]=0;
    unordered_set<int> digs;
    for(int i=1;i<=x;i++)
    {
        int temp = i;
        while(temp)
        {
            digs.insert(temp%10);
            temp/=10;
        }
        for(int j=1;j<10;j++)
        {
            if(i>=j && digs.count(j))
            {
                dp[i] = min(dp[i], 1 + dp[i-j]);
            }
        }
        digs.clear();
    }
    cout<<dp[x]<<endl;
}

int32_t main()
{
    
    init();
    solve();
    
    return 0;
}
