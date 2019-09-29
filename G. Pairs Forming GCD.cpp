#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pii              pair < ll, ll>
#define           pll              pair < pii, ll>
#define           fs               first
#define           scnd             second
#define           pb               push_back
#define           rall(v)        v.rbegin(),v.rend()
#define           N              10000002

ll phi[N];
ll S[N];
void computeTotient()
{
    for (ll i = 1; i < N; i++)
        phi[i] = i;

    for (ll p = 2; p < N; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p - 1;
            for (ll i = 2 * p; i < N; i += p)
            {
                phi[i] = (phi[i] / p) * (p - 1);
            }
        }
    }
}
void CoPrimes()
{
    computeTotient();
    for (ll i = 1; i < N; i++)
    {
        S[i] = S[i - 1] + phi[i];
    }
}

ll solve(ll X, ll P)
{
    ll low = 1;
    ll high = X ;
    ll ans = -1 ;

    while(low<=high)
    {
        ll mid = (low+high)/2;

        ll x = X / mid ;
        ll M = S[x];

        if(M>=P)
        {
            low=mid+1;
            ans=mid;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int main()
{

    CoPrimes();

    ll T,X ,i;
    ll P;

    scanf("%lld",&T);

    for( i = 0 ; i < T ; i++ )
    {
        scanf("%lld%lld",&X,&P);

        printf("Case %lld: %lld\n",i+1,solve(X,P));
    }
    return 0 ;
}

//https://algo.codemarshal.org/contests/icpc-dhaka-19-preli/problems/G
