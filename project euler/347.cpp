#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10000000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
void Google(ll tt){
    cout<<"Case #"<<tt<<": ";
}
vector <ll> sieve(N+5);
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
    map <pair<ll,ll>,ll> mp;
    ll sum=0;
    primes();
    for(ll i=N;i>=2;i--)
    {
        ll p=0,q=0,aa=0;
        ll ii=i;
        // cout<<i<<' '<<ii<<endl;
        // cout<<sieve[ii]<<endl;
        while(ii>1)
        {
            if(p==0)
                p=sieve[ii];
            else if(p!=0 && q==0 && p!=sieve[ii])
                q=sieve[ii];
            else if(p!=0 && q!=0 && p!=q && p!=sieve[ii] && q!=sieve[ii])
            {
                aa=1;
                break;
            }
            ii/=sieve[ii];
        }
        // cout<<p<<' '<<q<<endl;
        if(aa==0 && mp[{p,q}]==0 && p!=0 && q!=0)
        {
            sum+=i;
            mp[{p,q}]++;
            mp[{q,p}]++;
        }
    }
    cout<<sum<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}