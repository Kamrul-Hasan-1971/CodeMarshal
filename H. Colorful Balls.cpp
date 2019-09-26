#include<bits/stdc++.h>
using namespace std;
#define           ll               long long
#define           mod             1000000007


string s1, s2 ;
ll n ;

ll dp[100005][5] ;

string mask ="WRGB" ;

ll fun(ll pos,ll k)
{
    if(pos==n)
    {
        return 1 ;
    }
    if( dp[pos][k] != -1 )
        return dp[pos][k] ;
    ll ret = 0 ;
    if(s1[pos]=='W')
    {
        for( int i = 1 ; i <= 3 ; i ++ )
        {
            if( mask[i] != mask[k] )
                ret += fun( pos + 1, i ) ;
        }
    }
    else
    {
        for( int i = 1 ; i <= 3 ; i ++ )
        {
            if( mask[i] == s1[pos] )
            {
                if( mask[k] != s1[pos] )
                    ret += fun( pos + 1, i ) ;
                break ;
            }
        }
    }
    return dp[pos][k] = ret % mod ;

}

int main()
{

    ll  a, i;

    scanf("%lld",&a);

    for( i = 0 ; i < a ;  i++ )
    {
        cin >> s1;
        n = s1.size();
        memset( dp, -1, sizeof dp ) ;
        printf("Case %lld: %lld\n",i+1,fun(0,0));
    }
    return 0;
}

//https://algo.codemarshal.org/contests/icpc-dhaka-preli-18/problems/H
