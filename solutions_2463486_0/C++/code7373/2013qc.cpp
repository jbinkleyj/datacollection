#include <cstdio>
#include <conio.h>
#include <ctime>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;

int C, TC=1;

typedef unsigned long long ll;
ll fns[]={
1
,4
,9
,121
,484
,10201
,12321
,14641
,40804
,44944
,1002001
,1234321
,4008004
,100020001
,102030201
,104060401
,121242121
,123454321
,125686521
,400080004
,404090404
,10000200001
,10221412201
,12102420121
,12345654321
,40000800004
,1000002000001
,1002003002001
,1004006004001
,1020304030201
,1022325232201
,1024348434201
,1210024200121
,1212225222121
,1214428244121
,1232346432321
,1234567654321
,4000008000004
,4004009004004
,100000020000001
,100220141022001
,102012040210201
,102234363432201
,121000242000121
,121242363242121
,123212464212321
,123456787654321
,400000080000004
,10000000200000001};
const int n = sizeof(fns)/sizeof(fns[0]); 
int main()
{
    for (scanf ("%d", &C); TC <= C; TC++)
    {
////////////////////////////////////
        ll a,b;
        scanf("%lld %lld",&a,&b);
        int i,j=0;
        for(i=0;fns[i]<a;++i);
        cout<<" ";
        while(fns[i]<=b)
            ++i,++j;
        cout<<" ";
        cout<<"Case #"<<TC<<": "<<j<<endl;
////////////////////////////////////
    }
    return 0;
}
