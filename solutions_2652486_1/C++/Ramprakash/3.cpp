#include<fstream>
#include<iostream>
using namespace std;
#include<math.h>
int max(int a,int b)
{
	if(a>=b)return a;return b;
}
int main()
{
	ifstream f("1.in");
	ofstream g("1.out");
	int t,i,j,p2,p3,p5,p7,q,n,m,k,l;
	f>>t>>k>>n>>t>>l;
	g<<"Case #1:\n";
	m=n;
	for(i=0;i<k;i++)
	{
		p2=p3=p5=p7=0;
		for(j=0;j<l;j++)
		{
			f>>t;
			q=0;
			while(t%2==0){t/=2;q++;}
			p2=max(p2,q);
			q=0;
			while(t%3==0){t/=3;q++;}
			p3=max(p3,q);
			q=0;
			while(t%5==0){t/=5;q++;}
			p5=max(p5,q);
			q=0;
			while(t%7==0){t/=7;q++;}
			p7=max(p7,q);
		}
		g<<p2<<p3<<p5<<p7<<" ";
		n=m;
		for(j=0;j<p5;j++)g<<"5";
		for(j=0;j<p7;j++)g<<"7";
		n-=p5;
		n-=p7;
		while(n>0&&p3>0&&p2>0&&n<p2+p3){g<<"6";n--;p2--;p3--;}
		for(j=0;j<p3;j++)g<<"3";n-=p3;
		while(n>0&&n<p2-1){g<<"8";n--;p2-=3;}
		while(n>0&&n<p2){g<<"4";n--;p2-=2;}
		for(j=0;j<n;j++)g<<"2";
		g<<"\n";
	}
	return 0;
}
