#include<iostream>
#include <stdlib.h>
//#include<math.h>


using namespace std;
int board[20],count;

int main()
{
 int n,i,j;
 void queen(int row,int n);

 cout<<("****N Queens Problem Using Backtracking****")<<endl;
 cout<<("Enter number of Queens:");
 cin>>n;
 queen(1,n);
 //return 0;
}

//function for printing the solution
void print(int n)
{
 int i,j;
 cout<<endl<<endl;
 cout<<"Solution: "<<++count<<endl;

 for(i=1;i<=n;++i)
  cout<<"       "<<i;

 for(i=1;i<=n;++i)
 {
  cout<<endl;
  cout<<"  "<<i<<"  ";
  for(j=1;j<=n;++j)
  {
   if(board[i]==j)
    cout<<"  Q     ";
   else
    cout<<"  .     ";
  }
 }
}

/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  //checking column and digonal conflicts
  if(board[i]==column)
   return 0;
  else
   if(labs(board[i]-column)==labs(i-row))
    return 0;
 }

 return 1; //no conflicts
}

//function to check for proper positioning of queen
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column; //no conflicts so place queen
   if(row==n) //dead end
    print(n); //printing the board configuration
   else //try queen with next position
    queen(row+1,n);
  }
 }
}
