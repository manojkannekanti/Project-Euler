#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 5000
#define mod1 1000000007 
#define mod2 9999999900000001
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> sieve(N+5,1),V;
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
                sieve[j]=i;
        }
    }
    for(ll i=2;i<N+5;i++)
    {
        if(sieve[i]==i)
            V.push_back(i);
    }
}

int main()
{
    IO
    clock_t begin = clock();
    vector< vector <ll> > dp(N+5 ,vector <ll> (5000,0) );
    primes();
    for(ll i=0;i<V.size();i++)
    dp[0][i] = 1;
    for(ll i=2;i<=N;i++)
    {
        for(ll j=0;j<V.size();j++)
        {
            if(V[j]>i)
                break;
            dp[i][j] += dp[i-V[j]][j];
        }
        for(ll j=V.size()-1;j>=0;j--)
        {
            dp[i][j] = dp[i][j] + dp[i][j+1];
        }
        cout<<dp[i][0]<<' ';
        if(dp[i][0]>=5000)
        {
            cout<<i<<endl;
            break;
        }
    }
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}