#include<iostream>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include <deque>
#include<map>
#include<string>
#include <sstream>
#include<set>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define ff(i,a,b,c) for(int i=a;i<b;i+=c)
#define w(n) while(n>0)
#define vi vector<int>
#define vll vector<long long int>
typedef pair<pair<int,int> ,int> PII;
typedef pair<long long int,long long int> PI;
typedef pair<long long int, pair<int,int> > Pli;
typedef pair<int,string> PS;
typedef long long int ll;
typedef int I;
typedef string S;
ll mod_pow(ll a,ll n,ll b){ll res = 1;while(n){if(n&1) {res = (res*a)%b;}a = (a*a)%b;n >>= 1;}return res%b;}
ll mod_div(ll a,ll b,ll md){ll ans = (a*mod_pow(b,md-2,md))%md; return ans;}
ll mul(ll a,ll b,ll md){ return (ll)(a*b)%md;}
ll gcd(ll n,ll m){if(m<=n && n%m==0)return m;if(n<m)return gcd(m,n);else return gcd(m,n%m);}
ll add(ll a,ll b,ll md){a=((a%md)+(b%md))%md;return a;}
ll sub(ll a,ll b,ll md){return add(a,md-b,md);}
ll bC(int n,int r){ll ans=1;if(r>n-r)r=n-r;f(i,1,r+1)ans=(ans*(n-i+1))/(i);return ans;}
I ti=1,f=0;
vector<string> F,Se;
I main()
{
    I t;
    cin>>t;
    w(t)
    {
        t--;
        I n;
        cin>>n;
        f(i,0,n)
        {
            S a,b;
            cin>>a>>b;
            F.push_back(a);
            Se.push_back(b);
        }
        f(i,0,n)
        {
            I co=0,po=0;
            f(j,0,n)
            {
                if(i!=j && F[i]==F[j])
                    co=1;
                if(i!=j && Se[i]==Se[j])
                    po=1;
            }
            //cout<<co<<" "<<po<<endl;
            if(co+po>=2)
                f++;
        }
        cout<<"Case #"<<ti<<": "<<f<<endl;
        f=0;
        ti++;
        F.clear();
        Se.clear();
    }
}
///home/anupam/Desktop

