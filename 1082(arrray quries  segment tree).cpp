#include<bits/stdc++.h>
#define max  1000000000
#define df 100010
using namespace std ;
int sum[df*4] ;
int arr[df]  ;
void build(int at , int L , int R)
{
    sum[at] =  max ;
    if(L == R)
    {
        sum[at] = arr[L] ;
        return ;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2 + 1,mid+1,R);

    sum[at] = min( sum[at*2]  , sum[at*2+1] ) ;
}

int query(int at , int L , int R , int l , int r )
{

    if(r <L || R< l)
    {
        return max ;
    }

    if(r>=R && l <=L)
    {
        return sum[at];
    }

    int mid = (L + R) / 2 ;
    int x = query(at*2,L,mid,l,r);
    int y = query(at*2+1,mid + 1 , R , l ,r);
//    cout << "x = " << x << "y = " << y << endl;
    return min(x,y) ;
}


int main()
{

    int tc , n , q ;


    scanf("%d",&tc);

    for(int i = 0 ; i < tc ; i+=1)
    {

        scanf("%d%d",&n,&q);
        for(int k = 1 ; k<=n ; k+=1)
        {
            scanf("%d",&arr[k]);
        }


        build(1,1,n) ;
        printf("Case %d:\n",i+1);

        for(int k = 0 ; k< q ; k+=1)
        {
            int I , J ;
            scanf("%d%d",&I,&J);

            int ans = query(1,1,n,I,J) ;
            printf("%d\n",ans);
        }





    }

    return 0;
}

