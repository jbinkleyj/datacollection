#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
#define llu long long unsigned int
#define lli long long int
#define li long int
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define mod 1000000007
int scan()    {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
li scanli()    {int ip=getchar_unlocked(),flag=1;li ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lli scanlli()    {int ip=getchar_unlocked(),flag=1;lli ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scanllu()    {int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
void print(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void printli(li n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void printlli(lli n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void printllu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}

int main()
{
	int t=scan(),i,j,k;
	for(j=1;j<=t;j++)
	{
		int n=scan();
		string s;
		cin>>s;
		int ans=0,currentAudience=0;
		if(s[0]=='0')
		{
			ans++;
			currentAudience++;
		}
		else
			currentAudience+=(s[0]-'0');
		for(i=1;i<=n;i++)
		{
			if(currentAudience>=i)
			{
				currentAudience+=(s[i]-'0');
			}
			else
			{
				ans+=(i-currentAudience);
				currentAudience+=(i-currentAudience+s[i]-'0');	
			}
		}
		cout<<"Case #"<<j<<": "<<ans<<endl;
	}
	return 0;
}