#include<iostream>
using namespace std;
class string_op
   {
     private:char str1[100],str2[100];
     	     int i=0,j=0;
     	     int count1[256]={0};
     public:
          void accept();
          void length();
          void concat();
          void copy();
          void frequency1();
          void frequency2();
          void reverse();
          void substring();
          void display();
          inline char *str1_r()
              {
                return str1;
              }
                       
          inline char *str2_r()
              {
                 return str2;
              }
              
   };
void string_op::accept()
   {
       cout<<"\nEnter the first string: ";
       cin>>str1;
       cout<<"Enter the second string: ";
       cin>>str2;
       cout<<endl;
   }
   
   
void string_op::display()
   {
        cout<<"\nString 1 : "<<str1_r();
        cout<<"\nString 2 : "<<str2_r()<<endl;
   }
   
   
void string_op::length()   
   {
        for(i=0;str1_r()[i]!='\0';i++);
               cout<<"\nLength of string 1 : "<<i;
        for(j=0;str2_r()[j]!='\0';j++);
               cout<<"\nLength of string 2 : "<<j;
               cout<<endl;
   }
   

void string_op::frequency1()
   {	
           for(i=0;str1[i]!='\0';i++)
                count1[str1[i]]++;
        cout<<"\nCharacter frequency of string 1:\n";
           for(j=0;j<256;j++)  
               {
                  if(count1[j]!=0)
                     cout<<(char)j<<"     "<<count1[j]<<endl;
               }          
   }


void string_op::frequency2()
   {	
        int count2[256]={0};
           for(i=0;str2[i]!='\0';i++)
                count2[str2[i]]++;
        cout<<"\nCharacter frequency of string 1:\n";
           for(j=0;j<256;j++)  
               {
                  if(count2[j]!=0)
                     cout<<(char)j<<"     "<<count2[j]<<endl;
               }          
   }


void string_op::copy()
{
	for(i=0;str1[i]!='\0';i++)
	  {
	      str1[i]=str2[i];
	  }
	 str2[i]='\0';
          cout<<"\nString 1 after copy operation: "<<str1<<endl;
}


void string_op::substring()
{    int l;
     for(l=0;str2[l]!='\0';l++);   
             
     for(i=0,j=0;str1[i]&&str2[j]!='\0';i++)
        {
                   if(str1[i]==str2[j])  
                          j++;
                    else
                         j=0;
        }
       if(j==l)
          cout<<"\nSubstring found!! At position "<<i-j+1<<endl;
       else
          cout<<"\nNo substring found!!"<<endl;  
       
}

void string_op::reverse()
{
   int z=0;
   for(i=0;str1[i]!='\0';i++);
     i=i-1;
     char temp;
     while(z<i)
       {
         temp=str1[z];
         str1[z]=str1[i];
         str1[i]=temp;
          z++;
          i--;
       }
  cout<<"\nReverse string 1: "<<str1<<endl; 
         for(j=0;str2[j]!='\0';j++);
              j=j-1;
         int s=0;
         char temp2;
            while(s<j)
              {
                temp2=str2[s];
                str2[s]=str2[j];
                str2[j]=temp2;
                 s++;
                 j--;
              }
   cout<<"\nReverse string 2: "<<str2<<endl; 
}

void string_op::concat()
{
       int z;
       for(i=0;str1[i]!='\0';i++);
          z=i;
          j=0;
         while(str2[j]!='\0')
           {
                 str1[z]=str2[j];           
            j++;
            z++;
           }
          str1[z]='\0';	
        cout<<"concatenated string: "<<str1;
}
int main()
{
  string_op z;
  int op;

  do
   {
       cout<<"\n1 : Accept string\n2 : Display string\n3 : Calculate length\n4 : Concatenate\n5 : Copy operation\n6 : Frequency of string 1\n7 : Frequency of string 2\n8 : Check substring\n9 : Reverse string\n10 : Exit\nEnter choice : ";
       cin>>op;
             switch(op)
                {
                    case 1:z.accept();break;
                    
                    case 2:z.display();break;
                    
                    case 3:z.length();break; 
                    
                    case 4:z.concat();break;
                    
                    case 5:z.copy();break;
       		             
                    case 6:z.frequency1();break;
                    
                    case 7:z.frequency2();break;
                    
                    case 8:z.substring();break;
                    
                    case 9:z.reverse();break;
                    
                    case 10:break;
                    
                    default:cout<<"\nInvalid!!";
                }
                
   }while(op!=10);
  return 0;
}
