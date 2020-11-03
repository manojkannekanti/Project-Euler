#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1500000
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
    vector <ll> dp(N+5,0);
    map <pair<ll,pair<ll,ll>>,ll> mp;
    for(ll i=1;i<=1300;i++)
    {
        for(ll j=1;j<i;j++)
        {
            ll a = (i*i - j*j);
            ll b = (2*i*j);
            ll c = (i*i + j*j);
            // cout<<a<<' '<<b<<' '<<c<<endl;
            if(a>b)
                swap(a,b);
            for(ll k=1;;k++)
            {
                ll A = a*k,B = b*k,C = c*k;
                if((A+B+C)>N)
                    break;
                if(mp[{A,{B,C}}]==0)
                {
                    dp[A+B+C]++;
                    mp[{A,{B,C}}] = 1;
                }
            }
        }
    }
    ll sum = 0;
    for(ll i=1;i<=N;i++)
    {
        if(i==120)
            cout<<dp[i]<<endl;
        if(dp[i]==1)
            sum ++;
    }
    cout<<sum<<endl;
    cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}