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
#define           all(v)  v.begin(),v.end()

vector<ll>v;

int main()
{
    ll T,X,i,P,j;

    scanf("%lld",&T);

    for( i = 0 ; i < T ; i++ )
    {
        v.clear();
        scanf("%lld",&X);
        for( j = 0 ; j < X ; j++)
        {
            scanf("%lld",&P);
            v.pb(P);
        }
        sort(all(v));
        ll p = v[0]*v[X-1];
        printf("Case %lld: %lld\n",i+1,p);
    }
    return 0 ;
}
//https://algo.codemarshal.org/contests/icpc-dhaka-19-preli/problems/J
