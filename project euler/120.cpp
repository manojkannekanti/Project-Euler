#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007 
#define mod2 9999999900000001
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
    IO
    clock_t begin = clock();
    ll sum = 0;
    for(ll a=3;a<=1000;a++)
    {
        ll ma = 2;
        for(ll n=1;n<=a*a;n+=2)
        {
            ll ans = (2 * n * a);
            ans %= (a*a);
            ma = max(ma,ans);
        }
        sum += ma;
    }
    cout<<sum<<endl;
    cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}