// Name:- Kunal Sheth

//header files

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
using namespace std;

//end of header files


//definitions

#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long
#define getchar_unlocked getchar
#define putchar_unlocked putchar
//end of definitions


//fast input

int scan_d()    {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld()    {int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lld scan_lld()    {int ip=getchar_unlocked(),flag=1;lld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu()    {int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}

//end of fast input

//fast output

//no line break
void print_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(llu n)     {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}

//new line
void println_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void println_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void println_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void println_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

//special char
char sp;
void printsp_d(int n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void printsp_ld(ld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void printsp_lld(lld n)     {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void printsp_llu(llu n)     {int i=21;char output_buffer[22];output_buffer[21]=sp;do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

//end of fast output


//extra functions

//end of extra fnctions


//main

int main()
{
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    int t=scan_d();
    int cs=1;
    while(t--)
    {
        cout<<"Case #"<<cs++<<": ";
        int n=scan_d();
        string arr[n];
        string s[n];
        int no[n][101];
        for(int i=0;i<n;i++)
        {
            s[i]="";
            for(int j=0;j<101;j++)
                no[i][j]=0;
            cin>>arr[i];
            int len=arr[i].length();
            int k=0;
            for(int j=0;j<len;j++)
            {
                char ch=arr[i][j];
                int temp=j;
                while((j+1)<len&&arr[i][j+1]==arr[i][j])
                    j++;
                s[i]+=ch;
                no[i][k++]=j-temp+1;
            }
        }
            bool flag=0;
            for(int i=1;i<n;i++)
            {
                if(s[i].compare(s[i-1]))
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                cout<<"Fegla Won\n";
            else
            {
                int ans=0;
                int len=s[0].length();
                for(int j=0;j<len;j++)
                {
                    int mn=999999999;
                    for(int k=0;k<n;k++)
                    {
                        int curr=0;
                        for(int i=0;i<n;i++)
                            curr+=abs(no[i][j]-no[k][j]);
                        if(curr<mn)
                            mn=curr;
                    }
                   //cout<<mn<<" ";
                    ans+=mn;

                }
              //cout<<endl;
                println_d(ans);
            }
    }
    return 0;
}

//end of main
