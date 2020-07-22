#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10000
#define NN 50000000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
void Google(ll tt){
    cout<<"Case #"<<tt<<": ";
}
vector <ll> sieve(N+5,1),V;
set <ll> S;
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
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]==i)
            V.push_back(i);
    }
}
int main()
{
    IO
    clock_t begin = clock();
    primes();
    for(auto it:V)
    {
        if(it>10000)
            break;
        for(auto it1:V)
        {
            if(it1>1000)
                break;
            for(auto it2:V)
            {
                if(it2>100)
                    break;
                ll ss=(it*it)+(it1*it1*it1)+(it2*it2*it2*it2);
                if(ss<=NN)
                    S.insert(ss);
            }
        }
    }
    cout<<S.size()<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}