#include<stdio.h>
main()
{
int t,av=1,count,x,y,flagx,flagy,i,x1,y1;
char ch[200],c;
FILE *fp,*fq;
fp=fopen("/home/awanish/check","r");
fq=fopen("/home/awanish/sol","w");
fscanf(fp,"%d",&t);
while(t--)
{
fscanf(fp,"%d%d",&x,&y);
flagx=0;
flagy=0;
if(x<0)
{
x=-1*x;
flagx=1;
}
if(y<0)
{
y=-1*y;
flagy=1;
}
x1=0;
count=0;
for(i=1;;i++)
{
x1+=i;
if(x1>x)
{
x1=x1-i;
ch[i]='\0';
break;
}
ch[count++]='E';
}
y1=0;
for(;;i++)
{
y1+=i;
if(y1>y)
{
y1=y1-i;
break;
}
ch[count++]='N';
}
while(x1!=x)
{
x1++;
ch[count++]='W';
ch[count++]='E';
}
while(y1!=y)
{
y1++;
ch[count++]='S';
ch[count++]='N';
}
fprintf(fq,"Case #%d: ",av++);
for(i=0;i<count;i++)
{
if(flagx==1)
{
c=ch[i];
if(c=='E')
ch[i]='W';
else if(c=='W')
ch[i]='E';
}
if(flagy==1)
{
c=ch[i];
if(c=='N')
ch[i]='S';
else if(c=='S')
ch[i]='N';
}
fprintf(fq,"%c",ch[i]);
}
fprintf(fq,"\n");
}
return 0;
}
