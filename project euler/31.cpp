#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000
#define mod1 1000000007 
#define mod2 9999999900000001
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    IO
    clock_t begin = clock();
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    ll dp[k+1][n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[0][i] = 1;
    }
    for(ll i=1;i<=k;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            dp[i][j] = 0;
        }
    }
    for(ll i=1;i<=k;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            // dp[i][j] - > ways to get i with a[j] max value.
            if(i >= a[j])
                dp[i][j] = dp[i-a[j]][j];
        }
        for(ll j=1;j<=n;j++)
            cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
        cout<<endl;
        for(ll j=1;j<=n;j++)
        {
            dp[i][j] += dp[i][j-1];
        }
    }
    cout<<dp[k][n]<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}