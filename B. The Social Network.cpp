#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define           ll               long long int

ll parent[100005] ;
map<ll,ll>mp;

struct info
{
    ll val,id;
    info(ll a,ll b)
    {
        val = a;
        id = b;
    }

    bool operator<(const info& present)const
    {

        if(val==present.val)
        {
            return id<present.id;
        }
        else
        {
            return val<present.val;
        }
    }
};

orderset<info>ord[100005] ;
orderset<info>::iterator it ;

void initialization(ll x)
{
    for( ll i = 1 ; i <= x ; i++ )
    {
        parent[i] = i ;
        ord[i].clear();
    }
    mp.clear();
}

ll findParent( ll x )
{
    if( x != parent[x] )
    {
        return parent[x]=findParent(parent[x]);
    }
    return x ;
}

void unionSet(ll x, ll y )
{
    ll px = findParent(x);
    ll py = findParent(y);

    if(px!=py)
    {
        ll xx = ord[px].size();
        ll yy = ord[py].size();

        if(xx>yy)
        {
            parent[py]=px ;

            for( it = ord[py].begin() ; it != ord[py].end() ; it++ )
            {
                ord[px].insert(*it);
            }
        }
        else
        {
            parent[px]=py ;

            for( it = ord[px].begin() ; it != ord[px].end() ; it++ )
            {
                ord[py].insert(*it);
            }
        }
    }
}

int main()
{
    ll TC, N, Q, U, V, T, L, R, i, j,inp ;

    scanf("%lld", &TC );

    for( i = 0 ; i < TC ; i++ )
    {
        scanf("%lld%lld",&N,&Q);

        initialization(N);

        printf("Case %lld:\n",i+1);

        for( j = 0 ; j < Q ; j++ )
        {
            scanf("%lld",&inp);

            if( inp == 0 )
            {
                scanf("%lld%lld",&U,&V);
                unionSet( U, V ) ;
            }
            else if( inp == 1 )
            {
                scanf("%lld%lld",&U,&T);
                mp[T]++;
                ll o = findParent(U);
                ord[o].insert(info(T,mp[T]));
            }
            else
            {
                scanf("%lld%lld%lld",&U,&L,&R);
                ll x = findParent(U);

                ll m = ord[x].order_of_key(info(L,1));
                ll n = ord[x].order_of_key(info(R,mp[R]));
                ll ele = (*ord[x].find_by_order(n)).val;
                if(ele!=R)
                {
                    n--;
                }
                ll p = n-m+1;
                if(p<0)
                    p=0;
                printf("%lld\n",p);
            }
        }
    }
    return 0;
}

//https://algo.codemarshal.org/contests/icpc-dhaka-19-preli/problems/B
