#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100000000
#define M 100000
#define mod1 1000000007 
#define mod2 9999999900000001
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> sieve(N+5,1),div_cnt(N+5,0);
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
    div_cnt[1] = 1;
    for(ll i=2;i<=N;i++)
    {
        ll ss = i,prod = 1;
        while(ss>1)
        {
            ll prst_prm = sieve[ss],cnt = 1;
            while(prst_prm == sieve[ss])
            {
                ss/=prst_prm;
                cnt++;
            }
            prod = (prod * (cnt));
        }
        // cout<<prod<<endl;
        div_cnt[i] = prod;
    }
    long long sum = 0;
    deque <ll> Q;
    for(ll i=1;i<M;i++)
    {
        while(!Q.empty() && div_cnt[i]>div_cnt[Q.front()])
        {
            Q.pop_front();
        }
        Q.push_front(i);
        while(Q.back() <= (i - M))
            Q.pop_back();
    }
    for(ll i=M;i<=N;i++)
    {
        while(!Q.empty() && div_cnt[i]>div_cnt[Q.front()])
        {
            Q.pop_front();
        }
        Q.push_front(i);
        while(Q.back() <= (i - M))
            Q.pop_back();
        sum += div_cnt[Q.back()];
    }
    cout<<sum<<endl;
    cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}