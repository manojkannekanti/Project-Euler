#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000000
#define mod1 1000000007 
#define mod2 9999999900000001
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> sieve(N+5,1),cnt(N+5,0);
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
    cnt[1] = 0;
    primes();
    for(ll i=2;i<=N;i++)
    {
        ll tmp = i;
        while(tmp > 1)
        {
            ll ss = sieve[tmp];
            while(tmp%ss == 0)
                tmp /= ss;
            cnt[i]++;       
        }
    }
    for(ll i=1;i<=N-4;i++)
    {
        if(cnt[i]==4 && cnt[i+1]==4 && cnt[i+2]==4 && cnt[i+3]==4)
        {
            cout<<i<<endl;
            break;
        }
    }
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}