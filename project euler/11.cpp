#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 20
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
    ll a[N+1][N+1];
    for(ll i=1;i<=N;i++)
    {
        for(ll j=1;j<=N;j++)
        {
            cin>>a[i][j];
        }
    }
    // for(ll i=1;i<=N;i++)
    // {
    //     for(ll j=1;j<=N;j++)
    //     {
    //         cout<<a[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    ll prod = 1;
    for(ll i=1;i<=N;i++)
    {
        for(ll j=1;j<=N;j++)
        {
            if((N-j+1) >= 4)
                prod = max(prod , (a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3]));
            if((N-i+1) >= 4)
                prod = max(prod , (a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j]));
            if((N-i+1) >= 4 && (N-j+1) >= 4)
                prod = max(prod , (a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3]));
            if(i <= (N-3) && j >= 4)
                prod = max(prod , (a[i][j] * a[i+1][j-1] * a[i+2][j-2] * a[i+3][j-3]));
        }
    }
    cout<<prod<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}