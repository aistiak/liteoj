// BIT (binary index tree )
///AC
#include<bits/stdc++.h>
#define ll long long
#define max 100001
using namespace std ;
ll tree[max];
ll query(ll idx)
{
    ll sum=0;
    while(idx>0) {
        sum+=tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
    while(idx<=n) {
        tree[idx]+=x;
        idx += idx & (-idx);
    }
}
int main()
{

    ll tc , n , q ;
    vector <ll> v ;
    ll arr[max];

    scanf("%lld",&tc);

    for(ll i = 1 ; i <=tc ; i++  ) {
        v.clear() ;
        memset(tree,0,sizeof(tree));
        memset(arr,0,sizeof(arr));
        scanf("%lld%lld",&n,&q);
        // making the tree

        for(ll j = 0 ; j < n ; j++) {
            ll temp ;

            scanf("%lld",&temp);
            arr[j] = temp;
            update(j+1,temp,n);
        }
        ////

        ////
        // query
        while(q--) {
            ll choice ;
            scanf("%lld",&choice);
            if(choice == 1) {
                ll index ;
                scanf("%lld",&index);
                v.push_back(arr[index]);
                ll tem = arr[index];
                arr[index] = 0 ;
                update(index+1,-tem,n); // giving all the money of 'index'
            } else if(choice == 2) {
                ll v , index;
                scanf("%lld%lld",&index,&v);
                update(index+1,v,n);
                arr[index]+=v;

            } else if(choice == 3) {
                ll temp, in1 , in2 ;
                scanf("%lld%lld",&in1,&in2);
                temp = query(in2+1) - query(in1);
                v.push_back(temp);
            }

        }

        ll sz = v.size();
        printf("Case %d:\n",i);
        for(ll k = 0 ; k<sz ; k++) {
            printf("%lld\n",v[k]);
        }


    }

    return 0 ;
}
