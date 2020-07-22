#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100000000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
void Google(ll tt){
    cout<<"Case #"<<tt<<": ";
}
vector <ll> sieve(N+5,1),dp(N+5,0);
void primes()
{
    sieve[0]=sieve[1]=1;
    for(ll i=2;i<N+5;i++)
        sieve[i]=i;
    for(ll i=2;i*i<N+5;i++)
    {
        if(sieve[i]==i)
        {
            for(ll j=i*i;j<N+5;j+=i)
            {
                if(sieve[j]==j)
                    sieve[j]=i;
            }
        }
    }
}
ll po(ll x,ll y,ll z){
    if(y==0)
        return 1;
    ll pp=po(x,y/2,z);
    if(y%2==0)
        return (pp*pp)%z;
    else
        return (((pp*pp)%z)*(x%z))%z;
}
int main()
{
    IO
    clock_t begin = clock();
    primes();
    for(ll i=1;i<=N;i++)
    {
        ll val=i;
        while(val>1)
        {
            dp[sieve[val]]++;
            val/=sieve[val];
        }
    }
    ll prod=1;
    for(ll i=1;i<=N;i++)
    {
        if(dp[i]==0)
            continue;
        ll ans=po(i,dp[i],mod2);
        ans=(ans*ans)%mod2;
        prod=(prod*(1+ans))%mod2;
    }
    cout<<prod<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}