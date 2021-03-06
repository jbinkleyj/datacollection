/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define PB push_back
#define MP make_pair
#define sz(a) (int)(a).size()

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define CLEAR(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define PI 3.1415926535897932

using namespace std;
typedef long long ll;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

int convertString(string s)
{
    int num;
    stringstream sstr(s); // create a stringstream
    sstr>>num; // push the stream into the num
    return num;
}

int modulo (int m, int n) { return m >= 0 ? m % n : ( n - abs ( m%n ) ) % n; }

int dp[10000001];

bool isPalindrome(long long n) {
	long long num = n, digit, rev = 0;
	do
     {
        digit = num%10;
        rev = (rev*10) + digit;
        num = num/10;
     }while (num!=0);
     if (n == rev)
     	return true;
     else
     	return false;

}

void init() {
	dp[0] = 0;
	for(int i = 1; i < 10000001; i++) {
		dp[i] = dp[i-1];
		if (isPalindrome(i) && isPalindrome(i*1LL*i))
			dp[i]++;
	}
}

int main()
{
	int t;
	init();
	cin>>t;
	for(int k = 1; k <= t; k++) {
		double a, b;
		cin>>a>>b;
		int l = (int)sqrt(a-1);
		int r = (int)sqrt(b);
		cout<<"Case #"<<k<<": "<<dp[r]-dp[l]<<endl;
	}
	return 0;
}
