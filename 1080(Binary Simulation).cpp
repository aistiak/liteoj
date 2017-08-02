// TLE
// lite oj 1080
#include<bits/stdc++.h>
#define ll long long
#define max 10000000
using namespace std ;
int sum[400005] ;
int arr[100005]  ;
void build(int at , int l , int r)
{
    sum[at] = 0 ;
    if(l == r)
    {
        sum[at] = arr[l] ;
        //cout << at <<"  = " << sum[at] << endl;
        return ;
    }
    int mid = (l+r)/2;
    build(at*2,l,mid);
    build(at*2 + 1,mid+1,r);

    //sum[at] = sum[at*2] + sum[at*2+1];
}

int query(int at , int l , int r , int f )
{
    if( l == r)  // if leaf node
    {
        return sum[at] ;
    }
    else
    {


        int mid = ( l + r ) / 2 ;
        if(f<=mid)
            query(at*2,l,mid,f);
        else
            query(at*2+1,mid+1,r,f);
    }

}
void updaterange(int node, int start, int end, int l, int r)
{

    // out of range
    if (start > end or start > r or end < l)
        return;

    // current node is a leaf node
    if (start == end)
    {
        // add the difference to current node
        sum[node] ^= 1;
        return;
    }

    // if not a leaf node, recur for children.
    int mid = (start + end) / 2;
    updaterange(node*2, start, mid, l, r);
    updaterange(node*2 + 1, mid + 1, end, l, r);


    // use the result of children calls to update this node
    //tree[node] = tree[node*2] + tree[node*2+1];
}


int main()
{
   // freopen("out.txt","w",stdout);
    int tc, q  , I , J ;
    char ch , crr[100005];
    //cin >> tc ;
    scanf("%d\n",&tc) ;
    //scanf("\n");
    for(int i  = 1 ; i<= tc ; i+=1)
    {

//        int k = 1 ;
//        ch = 'a';
        cin >> crr ;
        int len = strlen(crr) ;
        for(int t = 1 ; t <=len ; t++)
        {
            arr[t] = crr[t-1] - '0';
        }
//        while(scanf("%c",&ch))
//        {
//            if(ch == '\n') break ;
//            arr[k++] = ch - '0' ;
//        }
//        cout << "k = " << k << endl;
        build(1,1,len) ;
//        cin >> q ;
        scanf("%d",&q) ;
//        cout << "q  = " << q << endl;
//        cout << "hello" << endl;

//        cout << " k = " << k << endl;
//        for(int p = 0 ; p < k * 4 ; p ++){
//             cout << sum[k] << endl;
//        }
        printf("Case %d:\n",i);
        for(int p = 0  ; p <q; p++)
        {
//            cout << "query num = " << p+1 << endl;
            cin >> ch ;
            //scanf("%c\n",&ch) ;
            if(ch == 'I')
            {
               // cin >>  I >> J  ;
                scanf("%d %d\n",&I,&J);
                updaterange(1,1,len,I,J) ;
            }
            else if(ch == 'Q')
            {
                cin >> I ;
                //scanf("%d\n",&i) ;

                int r = query(1,1,len,I) ;
                printf("%d\n",r);

            }



        }
//        cout << "/////////end ///////" << endl;

    }


    return 0 ;
}

