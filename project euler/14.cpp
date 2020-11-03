#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100000000
#define mod1 1000000007 
#define mod2 9999999900000001
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// vector <ll> vis(N+5,0);
map <ll,ll> dp,vis;

ll dfs(ll node)
{
    if(dp[node])
        return dp[node];
    vis[node] = 1;
    if(node==1)
        return dp[node] = 1;
    if(node%2==1)
    {
        dp[node] = 1 + dfs(3*node + 1);
    }
    else
    {
        dp[node] = 1 + dfs(node/2);
    }
    return dp[node];
}

int main()
{
    IO
    clock_t begin = clock();
    ll n;
    cin>>n;
    for(ll i=n;i>=1;i--)
    {
        if(!vis[i])
        {
            dp[i] = dfs(i);
        }
    }
    ll ma = 0,ans;
    for(ll i=1;i<10;i++)
        cout<<dp[i]<<' ';
    cout<<endl;
    for(ll i=n;i>=1;i--)
    {
        if(dp[i] > ma)
        {
            ma = dp[i];
            ans = i;
        }
    }
    cout<<ans<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}