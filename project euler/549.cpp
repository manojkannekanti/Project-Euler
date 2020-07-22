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
int main()
{
    IO
    clock_t begin = clock();
    primes();
    dp[1]=1;
    ll final_ans =0;
    for(ll i=2;i<=N;i++)
    {
        ll val=i,ma=0;
        while(val>1)
        {
            ll sie=sieve[val],cnt=0,lo=2,hi=1e9,mid,ans=1e9,dup=sie,ss=0;
            while(sieve[val]==sie)
            {
                cnt++;
                val/=sie;
            }
            // cout<<sie<<' '<<cnt<<endl;
            while(lo<=hi)
            {
                mid=(lo+hi)/2;
                ss=0;
                dup=sie;
                while(dup<=mid)
                {
                    ss+=(mid/dup);
                    dup*=sie;
                }
                if(ss>=cnt)
                {
                    hi=mid-1;
                    ans=min(ans,mid);
                }
                else
                    lo=mid+1;
            }
            // cout<<ans<<endl;
            ma=max(ma,ans);
            // cout<<ma<<endl;
        }
        final_ans+=ma;
    }
    cout<<final_ans<<endl;
    cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}