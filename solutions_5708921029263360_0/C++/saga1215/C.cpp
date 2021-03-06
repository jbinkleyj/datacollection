#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <algorithm>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;
/*****************************************macros************************************/
#define TYPE(m,a) __typeof(a) m = a
#define FOR(i,a,b) for(TYPE(i,(a)); i < (b); ++i)
#define DFOR(i,a,b) for(TYPE(i,(a)); i >= (b); --i)
#define ZFOR(i,N) FOR(i,0,N)
#define DZFOR(i,N) FOR(i,N,0)
#define SORT(x) sort((x).begin() , (x).end())
#define PB(x) push_back((x))
#define FORALL(it,v) for(TYPE(it, (v).begin()); it != (v).end(); ++it)
#define S2C(st, c) for(int i=0;i<st.size();i++) c[i] = st[i];
#define IA2CA(ia, ca, l) for(int i=0;i<l;i++) ca[i] = i2c(ia[i]);
#define CA2IA(ca, ia, l) for(int i=0;i<l;i++) ia[i] = c2i(ca[i]);
#define fout(x) cout<<"Case #"<<i+1<<": "<<x<<endl;
#define cfout(x) {cout<<"Case #"<<i+1<<": "<<x<<endl; continue;}
/****************************************typedefs**********************************/
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef vector<long long> VL;
typedef vector<VL> VLL;
typedef vector<bool> VB;
typedef vector<VB> VBB;
/*****************************************Math************************************/
bool isPrime(int a){ if(a <= 1) return false; if(a == 2) return false;
	if(a%2 == 0) return false; for(int i=3;i<sqrt(a);i+=2) if(a%i == 0) return false; return true; }
int GCD(int a,int b){ if(b==0) return a; return GCD(b,a%b);}
int LCM(int a,int b){return a*b/GCD(a,b);}
int getInt() { int x=0; scanf("%d",&x); return x;}

/*************************************Input Output*******************************/
char getChar(){ char x=' '; scanf("%c",&x); return x;}
string getString(){char c[1024]=""; scanf("%s",c); return c;}
long long getLong(){long long x= 0; scanf("%lld",&x); return x;}
void fileIO(){freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}
void sfileIO(){freopen("C-small-attempt1.in","r",stdin); freopen("C-small-attempt1.out","w",stdout);}
void lfileIO(){freopen("C-large.in","r",stdin); freopen("C-large.out","w",stdout);}

/********************************char, int, string, array************************/
int c2i(char c){int i=0; i=(int)c; i=i-48; if(i>=0 && i<=9) return i; else return -1;}
char i2c(int i){char c; c=(char)i; c=c+'0'; if(i>=0 && i<=9) return c; else return '0';}

//char* c2i(char c){int i=0; i=(int)c; i=i-48; if(i>=0 && i<=9) return i; else return -1;}

int countchar(string s,char c){int i=0;for(int j=0;j<s.length();j++) if(s[j] == c) i++; return i; }
vector<string> ex2s(string s, char c){vector<string> vs; string tmp=""; for(int i=0;i<s.length();i++){
    if(s[i]==c){vs.PB(tmp); tmp=""; continue;} tmp=tmp+s[i];} if(tmp!="") vs.PB(tmp); return vs;}

string ia2s(int a[],int sz){string c=""; stringstream ss; for(int i=0;i<sz;i++){ss<<a[i];} ss>>c; return c;}
int* s2ia(string s,int ar[50]){ar[0]=0;for(int i=1;i<=s.length();i++){ ar[i]=c2i(s[i-1]); ar[0]++;} return ar;}

string ca2s(char a[],int sz){string c=""; stringstream ss; for(int i=0;i<sz;i++){ss<<a[i];} ss>>c; return c;}
//macro for string to character array

/****************************************cases************************************/
char toup(char c){ if(c>='a' && c<='z') return c-' '; return NULL;}
char tolo(char c){ if(c>='A' && c<='Z') return c+' '; return NULL;}
char toswap(char c){ if(c>='A' && c<='Z') return c+' '; else if(c>='a' && c<='z') return c-' '; return NULL;}

const int INFIN = 1000000000;
/*********************************************************************************
WELCOME TO CODING

*********************************************************************************/
/*****************************user defined functions*****************************/


/***********************************main*****************************************/
int main(int argc, char** argv)
{
    sfileIO();
    int cases;
    cin>>cases;

    for(int eachCase = 0; eachCase<cases; eachCase++){
        int j,p,s,k;
        cin>>j>>p>>s>>k;
        int ans = min(j*p*s, j*p*k);
        vector<int> sh;
        vector<int> pn;
        vector<int> jk;
        if(ans==j*p*s){
               // cout<<"s";
            for(int i1=1;i1<=j;i1++) {
                for(int i2=1;i2<=p;i2++){
                    for(int i3=1;i3<=s;i3++){
                        jk.PB(i1);
                        pn.PB(i2);
                        sh.PB(i3);

                    }
                }
            }
        //cout<<"s done";
        } else {
            for(int i1=1;i1<=j;i1++) {
                for(int i2=1;i2<=p;i2++){
                    for(int i3=1;i3<=k;i3++){
                        jk.PB(i1);
                        pn.PB(i2);
                    }
                }
            }
            int cc = 1;
            int qq = min(p, s);
            for(int i=1;i<=j*k*p;) {
                for(int k1=cc, p1=0;p1<qq  && i<=j*k*p; k1++,p1++){
                    int q = k1;
                    if(q>s){
                        q = q-s;
                    }
                    i++;
                    sh.PB(q);
                }
                cc++;
            }
        }

        cout<<"Case #"<<eachCase+1<<": "<<ans<<endl;
       vector<int> r1(1000, 0);
       vector<int> r2(1000, 0);
        vector<int> r3(1000, 0);
        for(int i=0;i<ans;i++){
            cout<<jk[i]<<" "<<pn[i]<<" "<<sh[i]<<endl;
          r1[jk[i]*10 + pn[i]]++;
           r2[jk[i]*10 + sh[i]]++;
            r3[sh[i]*10 + pn[i]]++;
        }
        for(int i=0;i<1000;i++){
            if(r1[i] > k || r2[i] > k || r3[i]>k) {
                cout<<"invalid-----------------"<<j<<" "<<p<<" "<<s<<" "<<k<<endl;
            }
        }
    }
}
