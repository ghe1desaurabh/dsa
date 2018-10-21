#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class sparse
{
   private:
            int s[10][10],a[10][10],j,i;
            int row,col,count=0;
            int b[10][10],s2[10][10],s3[10][10];
   public:
           void accept()
            {
               cout<<"\nEnter no of rows: ";
               cin>>row;
               cout<<"\nEnter no of coloumns: ";
               cin>>col;
               for(i=0;i<row;i++) 
                  {
                      for(j=0;j<col;j++)
                          {
                             cin>>a[i][j];
                          }
                  }
                cout<<"\nEntered matrix:\n";
                for(i=0;i<row;i++) 
                  {
                    
                     cout<<endl;
                      for(j=0;j<col;j++)
                          {
                              cout<<a[i][j]<<"\t";
                          }
                  }
                cout<<endl;
            }
          
          void sparse_mat()
            {
               s[0][0]=row;
               s[0][1]=col;
             //  s[0][2]=count;
               int k=1;
                 for(i=0;i<row;i++)
                   {
                       for(j=0;j<col;j++)
                          {
                             if(a[i][j]!=0)
                               {
                                  s[k][0]=i;
                                  s[k][1]=j;
                                  s[k][2]=a[i][j];
                                  k++;
                               }
                          }
                   }
                   s[0][2]=k-1;
                 cout<<"Row\tCol\tElement\n";
                 cout<<s[0][0]<<"\t";
                 cout<<s[0][1]<<"\t";
                 cout<<s[0][2]<<endl;
                for(i=1;i<=s[0][2];i++)
                  {
                        cout<<s[i][0]<<"\t";
                        cout<<s[i][1]<<"\t";
                        cout<<s[i][2]<<endl;    
                  }
                 
            }
         
         
         void strans()
           { 
             int st[10][10];
             /*st[0][0]=col;
             st[0][1]=row;
             st[0][2]=count;*/
             int k=1;
             if(s[0][2]>0)
             {
                 for(i=0;i<col;i++)
                   {
                     for(j=1;j<=s[0][2];j++)
                        {
                           if(s[j][1]==i)
                              {
                                 st[k][0]=i;
                                 st[k][1]=s[j][0];
                                 st[k][2]=s[j][2];
                                 k++;
                              }  
                        }
                   }
               }
              cout<<"\nRow  Coloumn  Element\n";
              cout<<s[0][1]<<"\t";
              cout<<s[0][0]<<"\t";
              cout<<s[0][2]<<endl;
              for(i=1;i<=s[0][2];i++)
                 {
                    cout<<st[i][0]<<"\t";
                    cout<<st[i][1]<<"\t";
                    cout<<st[i][2]<<"\n";
                 }
           }
           
       void ftrans()
         {
            int rpos[100];
            int rterms[100];
            int j;
            int ft[10][10];
            for(int i=0;i<s[0][2];i++)
              rpos[i]=0;
            for(int i=1;i<s[0][2];i++)
               rpos[s[i][1]]++;
            rterms[0]=1;
            for(i=1;i<col;i++)
               rterms[i]=rterms[i-1]+rpos[i-1];
             for(i=1;i<=s[0][2];i++)
               {
                 j=s[i][1];
                 ft[rterms[j]][1]=s[i][0];
                 ft[rterms[j]][0]=s[i][1];
                 ft[rterms[j]][2]=s[i][2];
                 rterms[j]++;
               }
           cout<<"\nFast transpose\n";
           cout<<"\nRow  Coloumn  Element\n";
           cout<<s[0][1]<<"\t";
              cout<<s[0][0]<<"\t";
              cout<<s[0][2]<<endl;
              for(i=1;i<=s[0][2];i++)
                 {
                    cout<<ft[i][0]<<"\t";
                    cout<<ft[i][1]<<"\t";
                    cout<<ft[i][2]<<"\n";
                 }
         }
        void add_sparse()
          {
            int i,j,k;
            int cols,rows;
             cout<<"\nEnter another matrix:\n";
             cout<<"\nEnter row: ";
             cin>>rows;
             cout<<"\nEnter col: ";
             cin>>cols;
             
             
             for(i=0;i<rows;i++) 
                  {
                      for(j=0;j<cols;j++)
                          {
                             cin>>b[i][j];
                          }
                  }
                cout<<"\nEntered matrix:\n";
                for(i=0;i<rows;i++) 
                  {
                    
                     cout<<endl;
                      for(j=0;j<cols;j++)
                          {
                              cout<<b[i][j]<<"\t";
                          }
                  }
                  
                  s2[0][0]=rows;
               s2[0][1]=cols;
             //  s[0][2]=count;
                k=1;
                 for(i=0;i<rows;i++)
                   {
                       for(j=0;j<cols;j++)
                          {
                             if(b[i][j]!=0)
                               {
                                  s2[k][0]=i;
                                  s2[k][1]=j;
                                  s2[k][2]=b[i][j];
                                  k++;
                               }
                          }
                   }
                   s2[0][2]=k-1;
                 cout<<"\nRow\tCol\tElement\n";
                 cout<<s2[0][0]<<"\t";
                 cout<<s2[0][1]<<"\t";
                 cout<<s2[0][2]<<endl;
                for(i=1;i<=s2[0][2];i++)
                  {
                        cout<<s2[i][0]<<"\t";
                        cout<<s2[i][1]<<"\t";
                        cout<<s2[i][2]<<endl;    
                  }
                 
            if(s[0][0]!=s2[0][0]||s[0][1]!=s2[0][1])
                cout<<"\nAddition is not possible";
            else
             {
                 i=j=k=1;
                   while(i<=s[0][2]&&j<=s2[0][2])
                     {
                         if(s[i][0]==s2[j][0])
                          {
                             if(s[i][1]==s2[j][1])
                              {
                                     s3[k][0]=s[i][0];
                            	     s3[k][1]=s[i][1];
                                     s3[k][2]=s[i][2]+s2[j][2];
                                     i++;
                                     j++;
                                     k++;
                              }
                             else if(s[i][1]<s2[j][1])
                              {
                                   s3[k][0]=s[i][0];
                                   s3[k][1]=s[i][1];
                                   s3[k][2]=s[i][2];
                                   i++;
                                   k++;
                              }
                             else
                              {
                                   s3[k][0]=s[j][0];
                                   s3[k][1]=s[j][1];
                                   s3[k][2]=s[j][2];
                                   j++;
                                   k++;
                              }
                        }
                         else
                          {
                              if(s[i][0]<s2[j][0])
                                {
                                   s3[k][0]=s[i][0];
                                   s3[k][1]=s[i][1];
                                   s3[k][2]=s[i][2];
                                   i++;
                                   k++;
                                }
                               else
                                {
                                   s3[k][0]=s[j][0];
                                   s3[k][1]=s[j][1];
                                   s3[k][2]=s[j][2];
                                   j++;
                                   k++;
                                }
                                 
                          }
                     }
                    while(i<=s[0][2])
                      {
                          s3[k][0]=s[i][0];
                          s3[k][1]=s[i][1];
                          s3[k][2]=s[i][2];
                          i++;
                          k++;
                      }
                    while(j<=s2[0][2])
                      {
                          s3[k][0]=s[j][0];
                          s3[k][1]=s[j][1];
                          s3[k][2]=s[j][2];
                          j++;
                          k++;
                      }    
             
           cout<<"\nAddition is\n";
           cout<<"\nRow  Coloumn  Element\n";
           s3[0][0]=s[0][0];
           s3[0][1]=s[0][1];
           s3[0][2]=k-1;
           cout<<s3[0][0]<<"\t";
           cout<<s3[0][1]<<"\t";
           cout<<s3[0][2]<<"\n";
              for(i=1;i<k;i++)
                 {
                    cout<<s3[i][0]<<"\t";
                    cout<<s3[i][1]<<"\t";
                    cout<<s3[i][2]<<"\n";
                 }
                 }
          }
};
int main()
{
   sparse obj1,obj2;
   int op;
   obj1.accept();
   obj1.sparse_mat();
   obj1.strans();
   obj1.ftrans();
   obj1.add_sparse();
   
 /* do
   {
     cout<<"\nEnter\n1 :Accept data\n2 :Display sparse matrix\n3 :Display Simple transpose\n4 :Display fast transpose\n5 :Addition of matrices\n6 :Exit\nChoice: ";
     cin>>op;
        switch(op)
          {
          }
   }while(op!=6);*/
 return 0;
}
