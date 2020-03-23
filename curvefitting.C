#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

float a,b,x[50],y[50];
int i,j,m,n,k,l,s,p,q;
void input()
{

	printf("Enter no. of x values:");
	scanf("%d",&m);
	printf("Enter no. of y values:");
	scanf("%d",&n);
	if(m!=n)
	{
		printf("Curve fitting not possible!");
		exit(0);
	}
	printf("Enter x values:");
	for(i=0;i<m;i++)
		scanf("%f",&x[i]);
	printf("Enter y values:");
	for(j=0;j<n;j++)
		scanf("%f",&y[j]);
}
void sl()
{

	float sumx,sumy,sumxy,sumxx;
	sumx=0;
	sumy=0;
	sumxy=0;
	sumxx=0;
	input();
	for(i=0;i<m;i++)
	{
		sumx=sumx+x[i];
	}
	for(j=0;j<n;j++)
	{
		sumy=sumy+y[j];
	}
	for(k=0;k<m;k++)
	{
		sumxy=sumxy+(x[k]*y[k]);

	}
	for(s=0;s<m;s++)
	{
		sumxx=sumxx+(x[s]*x[s]);
	}
	printf("sumx:%f sumy:%f sumxy:%f sumxx:%f",sumx,sumy,sumxy,sumxx);
	a=((sumx*sumy)-(n*sumxy))/((sumx*sumx)-(n*sumxx));
	b=(sumy-(a*sumx))/n;
	printf("The curve is: y= %f x + (%f)",a,b);
}
void loga()
{

	float sumx,sumy,sumxy,sumxx,ly[50],sly,sumxly,a,A,b;
	sumx=0;
	sumy=0;
	sumxy=0;
	sumxx=0;
	sly=0;
	sumxly=0;
	input();
	for(i=0;i<m;i++)
	{
		sumx=sumx+x[i];
	}
	for(j=0;j<n;j++)
	{
		sumy=sumy+y[j];
	}
	for(k=0;k<m;k++)
	{
		sumxy=sumxy+(x[k]*y[k]);

	}
	for(s=0;s<m;s++)
	{
		sumxx=sumxx+(x[s]*x[s]);
	}
	for(j=0;j<m;j++)
	{
		ly[j]=log(y[j]);
	}
	for(i=0;i<n;i++)
	{
		sly=sly+ly[i];
	}
	for(k=0;k<m;k++)
	{
		sumxly=sumxly+(x[k]*ly[k]);
	}
	a=((sumx*sly)-(n*sumxly))/((sumx*sumx)-(n*sumxx));
	b=(sly-(a*sumx))/n;
	A=exp(b);

	printf("The curve is: y= %f * e^ (%f)x\n",A,a);


	printf("sumx:%f sumy:%f sumxy:%f sumxx:%f sumly:%f sumxly:%f",sumx,sumy,sumxy,sumxx,sly,sumxly);


}

void main()
{
	int ch;
	clrscr();

	printf("Curve fitting options : 1. Straight line\n 2.Logarithmic\n");
	printf("Enter your choice:\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: sl();
			break;
		case 2: loga();
			break;
		default:printf("Invalid!");
	}
	getch();
}