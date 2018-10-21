 #include<iostream>
using namespace std;
class student
{int a[50],b,c,d,e,x[50],h,f,l,ab,y[50];
public:
void intake()
{     d=0;
		cout<<"enter the number of student"<<endl;
		cin>>b;
		cout<<"NOTE :: enter negative for abscent student"<<endl;
		cout<<"enter the marks of student"<<endl;
		for(c=0;c<b;c++)
			cin>>a[c];
}
void abscent()
{     int z[50];
		for(c=0;c<b;c++)
					z[c]=a[c];
		for(c=0;c<b;c++)
		{   if(z[c]<0)
				d++;
		}
		cout<<"the number of abscent student is"<<d<<endl;
}
void marks()
{   int marks;
	float avg;
		d=b;
		for(c=0;c<b;c++)
			y[c]=a[c];
		for(c=0;c<b;c++)
		{   if(y[c]<0)
			{
				y[c]=0;
				d--;
			}
		}
		marks=0;
		for(c=0;c<b;c++)
		{
			marks=marks+y[c];
		}
		avg=marks/d;
		cout<<"the avg of all student is"<<avg<<endl;
}
void highlow()
{   l=b;
	for(c=0;c<b;c++)
		y[c]=a[c];
	for(c=0;c<b;c++)
	{   if('y[c]=0')
		    l--;
	}
	for(c=0;c<b;c++)
	{   for(f=0;f<b;f++)
		{   if(a[c]>a[f])
			{
				h=a[c];
				a[c]=a[f];
				a[f]=h;
			}
		}
	}
	cout<<"highest"<<a[0]<<endl;
	cout<<" lowest"<<a[l-1]<<endl;
}
void max()
{   int x[50],m,o,n,f,w[50];
	ab=b;
	for(c=0;c<b;c++)
	{
		x[c]=0;
	}
	for(c=0;c<b;c++)
    {
		w[c]=a[c];
	}
	for(c=0;c<b;c++)
	{
		if(w[c]<0)
		{
            ab--;
		}
	}
		for(c=0;c<b;c++)
	   {   for(f=0;f<b;f++)
			{   if(a[c]>a[f])
				{
						h=a[c];
						a[c]=a[f];
						a[f]=h;
				}
			}
		}
	for(c=0;c<ab;c++)
	{   for(m=0;m<ab;m++)
		{   if(a[c]==a[m])
				x[c]++;
		}
	}
	for(c=0;c<ab;c++)
		{   for(f=0;f<ab;f++)
			{   if(x[c]>x[f])
				{  n=x[c];
				  x[c]=x[f];
				  x[f]=n;
					o=a[c];
					a[c]=a[f];
					a[f]=o;
				}
			}
		}
	cout<<"the"<<a[0]<<"is repeated maximum"<<x[0]<<"times"<<endl;
	for(c=1;c<ab;c++)
	{  if(x[0]==x[c]&&a[0]!=a[c])
	  {
	      cout<<"the"<<a[c]<<"is repeated maximum"<<x[c]<<"times"<<endl;
	      a[0]=a[c];
	  }
	}
  }
}arb;
int main()
{   int a,b;
    arb.intake();
    do
    {  cout<<"1.abscent"<<endl<<"2.average"<<endl<<"3.highest"<<endl<<"4.repetation"<<endl;
       cin>>a;
       switch(a)
       {  case 1:arb.abscent();
	            break;
          case 2:arb.marks();
	            break;
          case 3:arb.highlow();
	            break;
          case 4:arb.max();
	            break;
        }
	   cout<<"do u want to continue enter 1 if u want 0 if u dont";
	   cin>>b;
    }while(b==1);
	return 0;
}
