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

ll po(ll x,ll y,ll z)
{
    if(y==0)
        return 1;
    ll pp=po(x,y/2,z);
    if(y%2==0)
        return (pp*pp)%z;
    else
        return (((pp*pp)%z)*(x%z))%z;
}

vector <bool> sieve(N+5,1);
void primes()
{
    sieve[0]=sieve[1]=0;
    for(ll i=2;i<N+5;i++)
        sieve[i]=1;
    for(ll i=2;i*i<N+5;i++)
    {
        if(sieve[i]==1)
        {
            for(ll j=i*i;j<N+5;j+=i)
                sieve[j]=0;
        }
    }
}

int main()
{
    IO
    clock_t begin = clock();
    primes();
    ll final_ans = 0;
    for(ll i=5;i<=N;i++)
    {
        ll sum = 0;
        if(sieve[i]==1)
        {
            ll ans = (i-1);
            // cout<<ans<<' ';
            sum = (sum + ans + 2*i)%i;
            ans = (ans * po(-1,i-2,i))%i;
            // cout<<ans<<' ';
            sum = (sum + ans + 2*i)%i;
            ans = (ans * po(-2,i-2,i))%i;
            // cout<<ans<<' ';
            sum = (sum + ans + 2*i)%i;
            ans = (ans * po(-3,i-2,i))%i;
            // cout<<ans<<' ';
            sum = (sum + ans + 2*i)%i;
            ans = (ans * po(-4,i-2,i))%i;
            // cout<<ans<<' ';
            // cout<<endl;
            sum = (sum + ans + 2*i)%i;
            // cout<<po(-1,i-2,i)<<' '<<po(-2,i-2,i)<<' '<<po(-3,i-2,i)<<' '<<po(-4,i-2,i)<<endl;
            // cout<<i<<' '<<sum<<endl;
            final_ans = (final_ans + sum);
        }
    }
    cout<<final_ans<<endl;
    cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}