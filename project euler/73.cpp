#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 12000
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
    ll cnt = 0;
    double L = (1.0)/3 , R = (1.0)/2;
    for(ll i=1;i<=N;i++)
    {
        ll left = i/3;
        ll right = i/2;
        for(ll j=left;j<=right;j++)
        {
            double dd = (j*1.0)/i;
            if(dd > L && dd < R && __gcd(j,i)==1)
                cnt++;
        }
    }
    cout<<cnt<<endl;
    cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}