#include<bits/stdc++.h>
using namespace std;
#define           ll               long long int
#define           pii              pair < ll, ll>
#define           pll              pair < pii, ll>
#define           fs               first
#define           scnd             second
#define           pb               push_back
#define           rall(v)        v.rbegin(),v.rend()

vector<pii>v1[60];
vector<ll>serial;


int main()
{

    ll K, N, ID, S, TP, M, inp, i, j,chk=0,k;

    cin>>K;

    for( i = 0 ; i < K ; i++ )
    {
        for(j=1; j<55; j++)
        v1[j].clear();
        serial.clear();
        chk = 0 ;

        cin>>N;

        for(j=0; j<N; j++)
        {
            cin>>ID>>S>>TP>>M;
            v1[ID].pb({S,TP});

            for( k = 1 ; k <= M ; k++ )
            {
                cin>>inp;
                S++;
                TP+=inp;
                v1[ID].pb({S,TP});
            }
        }

        for(j=0; j<N; j++)
        {
            cin>>inp;
            serial.pb(inp);
        }

        ll ssss = 200;
        ll ttpp = 10000000;

        for( j = 0 ; j <N; j++)
        {
            inp = serial[j];
            chk=0;

            for( k = v1[inp].size()-1 ; k >= 0 ; k-- )
            {
                if(v1[inp][k].fs<ssss )
                {

                    chk=1;
                    ssss = v1[inp][k].fs;
                    ttpp = v1[inp][k].scnd;
                    break;
                }
                else if(v1[inp][k].fs==ssss )
                {
                    if( v1[inp][k].scnd>=ttpp )
                    {
                        chk=1;
                        ssss = v1[inp][k].fs;
                        ttpp = v1[inp][k].scnd;
                        break;

                    }
                }
            }
            if(chk==0)
            {
                break;
            }
        }

        if(chk==0)
        {
            printf("Case %lld: Say no to rumour >:\n",i+1);
        }
        else
        {
            printf("Case %lld: We respect our judges :)\n",i+1);
        }
    }
    return 0 ;
}
//https://algo.codemarshal.org/contests/icpc-dhaka-19-preli/problems/C
