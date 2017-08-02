// https://www.johndcook.com/blog/2015/10/06/number-of-digits-in-n/
#include<bits/stdc++.h>
#define ll long long
#define pi 3.1416
using namespace std ;

ll digits(ll n ){
    return floor(lgamma(n+1)/log(10)) + 1 ;
}
ll fun(ll n , ll b ){
    if( n == 0 || n == 1) return 1 ;
    return floor( ((n+0.5)*log(n) - n + 0.5*log(2*pi))/log(b) ) + 1;
}
int main(){

    ll tc , a, b  ;
    scanf("%lld",&tc);
    for(ll k = 1 ; k<= tc ; k+=1){
        scanf("%lld%lld",&a,&b);
        printf("Case %lld: %lld\n",k,fun(a,b)) ;
    }

    return 0 ;
}

