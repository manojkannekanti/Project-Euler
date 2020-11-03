#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000
#define mod1 1000000007 
#define mod2 9999999900000001
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector <ll> cnt(N*N + 5,0) , prst(N + 5 , 0);

int main()
{
    IO
    clock_t begin = clock();
    for(ll i=1;i<=N;i++)
        cnt[i*i]++;
    for(ll i=1;i<=N;i++)
    {
        for(ll j=1;j<=N;j++)
        {
            ll ans = (i*i) +(j*j);
            if(ans <= (N*N) && cnt[ans])
            {
                ll perimeter = sqrtl(ans) + i + j;
                if(perimeter <= N)
                    prst[perimeter]++;
            }
        }
    }
    ll ma = 0,val = 0;
    for(ll i=1;i<=N;i++)
    {
        if(prst[i] > ma)
        {
            val = i;
            ma = prst[i];
        }
    }
    // cout<<prst[120]<<endl;
    cout<<val<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}