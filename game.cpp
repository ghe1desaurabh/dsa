#include<iostream>
using namespace std;
class game
{
  private:int total,rn[30],i;
           string name[30];
           int count=0;
  public: 
         void accept()
           {
              cout<<"\nEnter total students: ";
              cin>>total;
              for(int i=0;i<total;i++)
                  {
		      cout<<"\nEnter the roll no of student: ";
		      cin>>rn[i];
		      cout<<"\nEnter the name of student: ";
		      cin>>name[i];
                  }
          }
          
         void display()
           {
              cout<<"\n{";
              for(i=0;i<total;i++)
                {
                   cout<<rn[i]<<"-"<<name[i];  
                     if(i!=total-1)
                        cout<<",";     
                }
              cout<<"}"<<endl;
           }
        
        void either_game(game a,game b)
           {
               for(int k=0;k<a.total;k++)
                  {
                     rn[k]=a.rn[k];
                     name[k]=a.name[k];
                     count++;
                  }
               
               for(i=0;i<b.total;i++)
                 {
                    int flag=0;
                        for(int j=0;j<a.total;j++)
                            {
                               if(b.rn[i]==a.rn[j])
                                   {
                                      flag=1;
                                      break;
                                   }
                              }
                                if(flag==0)
                                   {
                                      rn[count]=b.rn[i];
                                      name[count]=b.name[i];
                                      count++;
                                   }
                 }
              total=count;
           }
           
           
        void both_game(game x,game y)
           {
              int flag=0;
              int count=0;
               for(int i=0;i<y.total;i++)
                  {
                      flag=0;
                         for(int j=0;j<x.total;j++)
                            {
                                if(y.rn[i]==x.rn[j])
                                   {
                                      flag=1;break;
                                   }
                            }
                          if(flag==1)
                             {
                                rn[count]=y.rn[i];
                                name[count]=y.name[i];
                                count++;
                             }
                  }
                total=count;
           }
           
        void single_game(game c,game d)
          {
              int flag;
             int count=0;
                for(int i=0;i<c.total;i++)
                  {
                     flag=0;
                        for(int j=0;j<d.total;j++)
                           {
                               if(c.rn[i]==d.rn[j])
                                  {
                                     flag=1;
                                     break;
                                  }
                           }
                         if(flag==0)
                           {
                              rn[count]=c.rn[i];
                              name[count]=c.name[i];
                              count++;
                           }
                  }
                total=count;
          }
};
int main()
{
  game cricket,badminton,total_std,either,both,singlec,singleb;
      int op;
      do
       {
         cout<<"\nEnter \n1 :Accept data\n2 :Display data\n3 :Students play either game\n4 :Students play only cricket\n5 :Students play only badminton\n6 :Students play both game\n7 :Students playing no game\n8 :Exit\nChoice: ";
         cin>>op;
            switch(op)
              {
                case 1:total_std.accept();
                       cout<<"\nEnter data for students playing cricket\n";
                       cricket.accept();
                       cout<<"\nEnter data for students playing badminton\n";
                       badminton.accept();
                       break;
                       
               case 2:cout<<"\nTotal students in the class\n";
                      total_std.display();
                      cout<<"\nStudents play cricket";
                      cricket.display();
                      cout<<"\nStudents play badminton\n";
                      badminton.display();
                      break;
                
              case 3:cout<<"\nStudents playing either game\n";
                     either.either_game(cricket,badminton);
                     either.display();
                     break;
              
              case 4:cout<<"\nStudents play only cricket\n";
                      singlec.single_game(cricket,badminton);
                      singlec.display();
                      break;
                      
             case 5:cout<<"\nStudents playing only badminton\n";
                     singlec.single_game(badminton,cricket);
                     singlec.display();
                     break;                                        
             case 6: cout<<"\nStudents playing both game\n";
                      both.both_game(cricket,badminton);
                      both.display(); 
                      break;
                      
             case 7:cout<<"\nStudents playing no game\n";
                    singlec.single_game(total_std,either);
                    singlec.display();
                    break;
             
            case 8:break;             
              }
       }while(op!=8);
     return 0;
}
