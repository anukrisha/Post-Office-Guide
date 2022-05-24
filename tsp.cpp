#include<iostream>
 
using namespace std;
 
int completed[10],n,cost=0;
 int ary[10][10] = { {0,11,21,20,9,26,34,6,22,14},
                        {11,0,10,19,20,15,37,5,21,25},
                        {21,10,0,29,30,25,47,15,31,35},
                        {20,19,29,0,24,20,18,14,2,19},
                        {9,20,30,24,0,35,25,15,26,5},
                        {26,15,25,20,35,0,34,20,18,39},
                        {34,37,47,18,25,34,0,32,16,20},
                        {6,5,15,14,15,20,32,0,16,20},
                        {22,21,31,2,26,18,16,16,0,21},
                        {14,25,35,19,5,39,20,20,21,0} };
 
void takeInput()
{
            int i,j;

            //cout<<"Enter the number of villages: ";
            n=10;

            //cout<<"\nEnter the Cost Matrix\n";

            for(i=0;i < n;i++)
            {
            // cout<<"\nEnter Elements of Row: "<<i+1<<"\n";

            // for( j=0;j < n;j++)
            // cin>>ary[i][j];

            completed[i]=0;
            }

            cout<<"\n\nThe cost list is:";

            for( i=0;i < n;i++)
            {
            cout<<"\n";

            for(j=0;j < n;j++)
               cout<<"\t"<<ary[i][j];
            
            }
}
 
int least(int c)
{
int i,nc=999;
int min=999,kmin;
 
for(i=0;i < n;i++)
{
if((ary[c][i]!=0)&&(completed[i]==0))
if(ary[c][i]+ary[i][c] < min)
{
min=ary[i][0]+ary[c][i];
kmin=ary[c][i];
nc=i;
}
}
 
if(min!=999)
cost+=kmin;
 
return nc;
}
 
void mincost(int city)
{
int i,ncity;
 
completed[city]=1;
 
cout<<" "<<city+1;
ncity=least(city);
 
if(ncity==999)
{
ncity=0;
cout<<ncity+1;
cost+=ary[city][ncity];
 
return;
}
 
mincost(ncity);
}
 
int main()
{
takeInput();
 
cout<<"\n\nThe Path is:\n";
mincost(4); //passing 0 because starting vertex
 
cout<<"\n\nMinimum cost is "<<cost;
 
return 0;
}