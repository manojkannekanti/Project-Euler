#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
void Google(ll tt){
    cout<<"Case #"<<tt<<": ";
}
vector <ll> sieve(N+5,1);
void primes()
{
    sieve[0]=sieve[1]=1;
    for(ll i=2;i<N+5;i++)
        sieve[i]=i;
    for(ll i=2;i<N+5;i++)
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
    ll ss=0;
    for(ll i=2;i<=N;i++)
    {
        ll val=i,ans=i;
        while(val>1)
        {
            ll sie=sieve[val];
            while(sieve[val]==sie)
                val/=sie;
            ans*=(sie-1);
            ans/=sie;
        }
        if(ans==0)
        cout<<i<<endl;
        ss+=ans;
    }
    cout<<ss<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}