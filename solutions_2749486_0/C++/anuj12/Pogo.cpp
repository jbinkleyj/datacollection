#include<iostream>
#include<string>

using namespace std;

int main()
{
	int t,x,y,j;
	cin>>t;
	for(j=1;j<=t;j++)
	{
		cin>>x>>y;
		string str;
		int a=x,b=y;
		if(x<0)
			a=-x;
		if(y<0)
			b=-y;
		int i=1,p=0,q=0;
		if(a<b)
		{
			if(x<0)
			{
				for(;;i++)
				{
					if(p-i<x)
						break;
					p=p-i;
					str+="W";
				}
				i--;
				while(p!=x)
				{
					i+=2;
					p--;
					str+="EW";
				}
			}
			else
			{
				for(;;i++)
				{
					if(p+i>x)
						break;
					p=p+i;
					str+="E";
				}
				i--;
				while(p!=x)
				{
					i+=2;
					p++;
					str+="WE";
				}
			}
				
			if(y<0)
			{
				for(i++;;i++)
				{
					if(q-i<y)
						break;
					q=q-i;
					str+="S";
				}
				i--;
				while(q!=y)
				{
					i+=2;
					q--;
					str+="NS";
				}
			}
			else
			{
				for(i++;;i++)
				{
					if(q+i>y)
						break;
					q=q+i;
					str+="N";
				}
				i--;
				while(q!=y)
				{
					i+=2;
					q++;
					str+="SN";
				}
			}
		}
		else
		{
			if(y<0)
			{
				for(;;i++)
				{
					if(q-i<y)
						break;
					q=q-i;
					str+="S";
				}
				i--;
				while(q!=y)
				{
					i+=2;
					q--;
					str+="NS";
				}
			}
			else
			{
				for(;;i++)
				{
					if(q+i>y)
						break;
					q=q+i;
					str+="N";
				}
				i--;
				while(q!=y)
				{
					i+=2;
					q++;
					str+="SN";
				}
			}

			if(x<0)
			{
				for(i++;;i++)
				{
					if(p-i<x)
						break;
					p=p-i;
					str+="W";
				}
				i--;
				while(p!=x)
				{
					i+=2;
					p--;
					str+="EW";
				}
			}
			else
			{
				for(i++;;i++)
				{
					if(p+i>x)
						break;
					p=p+i;
					str+="E";
				}
				i--;
				while(p!=x)
				{
					i+=2;
					p++;
					str+="WE";
				}
			}
		}
		cout<<"Case #"<<j<<": "<<str<<endl;
	}
	return 0;
}
