#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
#include<sstream>
#include<ctime>
#define pb push_back
using namespace std;
int a[15][20];
vector<int> ans;
int main()
{
    freopen("C-small-1-attempt5.in","r",stdin);
    freopen("C-small-1-attempt5.out","w",stdout);
    srand(time(NULL));
    int t,tt=0,n,i,j;
    int r,m,k,mmax;
    scanf("%d",&t);
    while(t--)
    {
        tt++;
        scanf("%d%d%d%d",&r,&n,&m,&k);
        puts("Case #1:");
        while(r--)
        {
            memset(a,0,sizeof(a));
            ans.clear();
            for(i=0;i<k;i++)
            {
                scanf("%d",a[i]);
                a[i][1]=a[i][0];
                while(a[i][1]%2==0)
                {
                    a[i][1]/=2;
                    a[i][2]++;
                }
                while(a[i][1]%3==0)
                {
                    a[i][1]/=3;
                    a[i][3]++;
                }
                while(a[i][1]%5==0)
                {
                    a[i][1]/=5;
                    a[i][5]++;
                }
            }
            for(i=0;i<k;i++)
            {
                if(a[i][5])ans.push_back(5);
                if(a[i][3])ans.push_back(3);
                if(a[i][2]==1)ans.push_back(2);
            }
            if(ans.size()==3)
            {
                for(i=0;i<3;i++)printf("%d",ans[i]);
                puts("");
                continue;
            }
            for(i=0;i<k;i++)
            {
                if(ans.size()==3)break;
                a[i][1]=a[i][0];
                int cnt=0;
                for(j=0;j<ans.size();j++)
                    if(a[i][1]%ans[j]==0)
                    {
                        a[i][1]/=ans[j];
                        cnt++;
                    }
                if(cnt==ans.size())
                {
                    if(a[i][1]==12)
                    {
                        ans.pb(3);
                        ans.pb(4);
                    }
                    if(a[i][1]==15)
                    {
                        ans.pb(3);
                        ans.pb(5);
                    }
                    if(a[i][1]==20)
                    {
                        ans.pb(4);
                        ans.pb(5);
                    }
                    if(a[i][1]==9)
                    {
                        ans.pb(3);
                        ans.pb(3);
                    }
                    if(a[i][1]==16)
                    {
                        ans.pb(3);
                        ans.pb(4);
                    }
                    if(a[i][1]==8)
                    {
                        ans.pb(4);
                        ans.pb(2);
                    }
                    if(a[i][1]==25)
                    {
                        ans.pb(5);
                        ans.pb(5);
                    }
                    if(a[i][1]<=5 && ans.size()==2)ans.pb(a[i][1]);
                    if(a[i][1]==4 && ans.size()==1)
                    {
                        ans.pb(2);
                        ans.pb(2);
                    }
                }
            }
            for(i=0;i<k;i++)
            {
                if(ans.size()==3)break;
                a[i][1]=a[i][0];
                int cnt=0;
                for(j=0;j<ans.size();j++)
                    if(a[i][1]%ans[j]==0)
                    {
                        a[i][1]/=ans[j];
                        cnt++;
                    }
                if(cnt==ans.size()-1)
                {
                    ans.pb(a[i][1]);
                }
            }
            if(ans.size()<3)
            {
                for(i=ans.size();i<3;i++)
                {
                    if(rand()%4==0)ans.pb(2);
                    if(rand()%4==1)ans.pb(4);
                    if(rand()%4==2)ans.pb(5);
                    if(rand()%4==3)ans.pb(3);
                }
            }
            for(i=0;i<3;i++)printf("%d",ans[i]);
            puts("");
        }
    }
    return 0;
}
