#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std;
typedef int128_t ll;
#define N 200000
#define mod1 10000000000 
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

int main()
{
    IO
    clock_t begin = clock();
    ll n;
    cin>>n;
    ll sum = 0;
    for(ll i=1;i<=n;i++)
    {
        ll ans = po(i,i,mod1);
        // cout<<ans<<endl;
        sum = (sum + ans)%mod1;
    }
    cout<<sum<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}