#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 64000000 
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
void Google(ll tt){
    cout<<"Case #"<<tt<<": ";
}

int main()
{
    IO
    clock_t begin = clock();
    vector <ll> dp(N+5,0);
    for(ll i=1;i<=N;i++)
    {
        for(ll j=i;j<=N;j+=i)
            dp[j]+=(i*i);
    }
    ll ans=0;
    for(ll i=1;i<N;i++)
    {
        ll sqr=sqrtl(dp[i]);
        if(sqr*sqr==dp[i])
            ans+=i;
    }
    cout<<ans<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}