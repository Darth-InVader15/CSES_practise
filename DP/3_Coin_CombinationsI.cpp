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

// int maxx = INT_MIN; //for storing the max count
//this is where the recursion happens 

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}


void init()
{
    fast_cin();
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);     //opened in reading mode
    freopen("output.txt","w",stdout);  //opened in writing mode 
    #endif
}
// int dp[1000000][1000000];
// map<pair<int,int>,int> mpp;
int dp[1000002];
int solve(int tar, vector<int> &coins)
{
    if(tar == 0)    return 1;
    // if(ind < 0)    return 0;

    // if(mpp.find({ind,tar}) != mpp.end())   return mpp[{ind,tar}];
    if(dp[tar] != -1) return dp[tar];

    int take =0, dont = 0;
    
    for(int i=0;i<coins.size();i++)
    {
        if(coins[i] <= tar) take = (take + solve(tar-coins[i],coins)%mod)%mod;
    }

    return dp[tar] = (take + dont)%mod;
}

void solve()
{
    int n, tar;
    cin>>n>>tar;

    vector<int> coins(n);
    forn(n) cin>>coins[i];

    auto arr= coins;

    // sort(coins.begin(),coins.end());

    memset(dp,0,sizeof(dp));
    // int ans = solve(tar,coins);
    int ans = 0;

    dp[0] = 1;
    
    for(int i=1;i<=tar;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(coins[j] > i)    continue;
            dp[i] = (dp[i] + dp[i - coins[j]])%mod;
        }
    }
    //Tabulation
    //we first determined the state/subproblem parameters
    //Relate it with the bigger problem
    // Then we made the relation
    // dp[x] = Sum(dp[x-coins[i]])

    //Then the base cases and largest subproblems

    cout<<dp[tar]<<endl;
}

int32_t main()
{
    
    init();
    int t;
    // cin>>t;
    t=1;

    // vector<int> stt = help();
    while(t--)
        solve();
    
    return 0;
}
