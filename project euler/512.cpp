#include<bits/stdc++.h>
using namespace std;
typedef int ll;
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
    ll n;
    cin>>n;
    vector <ll> phi(n+1);
    for(ll i=1;i<n+1;i++)
        phi[i] = i;
    for(ll i=2;i<n+1;i++)
    {
        if(phi[i]==i)
        {
            for(ll j=i;j<n+1;j+=2*i)
                phi[j] -= phi[j]/i;
        }
    }
    // for(ll i=1;i<10;i++)
    //     cout<<phi[i]<<' ';
    // cout<<endl;
    long long sum = 0;
    for(ll i=1;i<=n;i+=2)
    {
        if(i%2==1)
            sum += phi[i];
    }
    cout<<sum<<endl;
    cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}