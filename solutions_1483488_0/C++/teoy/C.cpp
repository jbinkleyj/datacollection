#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int tran(char *s)
{
	int len=strlen(s);
	int sum=0;
	for(int i=0;i<len;i++)
	{
		sum=sum*10+s[i]-'0';
	}
	return sum;
}
char s[100];
int a[100];
int main(void)
{
	
	int T,A,B;
	a[0]=1;
	for(int i=1;i<=7;i++)
	{
		a[i]=a[i-1]*10;
	}
	set<int> tt;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	int g=0;
	while(T--)
	{
		scanf("%d%d",&A,&B);
		int sum=0;
		for(int i=A;i<=B;i++)
		{
			sprintf(s,"%d",i);			
			tt.clear();
			int len=strlen(s);
			int tmp=i;
			for(int j=0;j<len;j++)
			{
				int now=(tmp%10)*a[len-1]+tmp/10;
				tmp=now;
				if(tmp>i&&tmp<=B)
				{
					tt.insert(tmp);					
				}
			}
			sum+=tt.size();
		}
		printf("Case #%d: %d\n",++g,sum);
	}
	return  0;
}
