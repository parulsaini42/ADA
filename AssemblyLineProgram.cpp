#include<iostream>
using namespace std;
#define n 4

int l[2][n];   //final path matrix with values 0 or 1
bool s[2][n];    // stage of a given line 

void path_find(int k,int m)
{
 if(m>0)
 {	
	if(k==0)
	 { k=l[0][m];
	   s[0][m]=true;
	   m--;
	   path_find(k,m);
	 }
	 else
	  { k=l[1][m];
	   s[1][m]=true;
	   m--;
	    path_find(k,m);
	 }
  }
return;
}

int main()
{ int final,k,i,j;
  int f[2][n-1];  //time taken to complete a stage
  int t[2][n]={{0, 7, 4, 5},
                {0, 9, 2, 8}};  //transition time
  int a[2][n]={{4, 5, 3, 2},
                {2, 10, 1, 4}};    //completion time of a stage
  
  
  int e[2]= {10, 12}; //entry time
  int x[2]={18, 7};  //exit time  
  
  //program with 0 and 1 analogous to line 1 and 2
  for(i=0;i<2;i++)
   { for(j=0;j<n;j++)
        { s[i][j]=false;
		}
   }

  f[0][0]=e[0]+a[0][0];
  f[1][0]=e[1]+a[1][0];
  
  if ( f[0][0]<=f[1][0])
     s[0][0]=true;
	else
	  s[1][0]=true;
  
  for(j=1;j<n;j++)
     {
	  //line0
	  if( (f[0][j-1]+a[0][j])<=(f[1][j-1]+t[1][j]+a[0][j]))
            { f[0][j]=f[0][j-1]+a[0][j];
               l[0][j]=0;
			}
		else 
		    { f[0][j]=f[1][j-1]+t[1][j]+a[1][j];
               l[0][j]=1;
			}
			
		//line1	
	   if( (f[1][j-1]+a[1][j])<=(f[0][j-1]+t[0][j]+a[1][j]))
            { f[1][j]=f[1][j-1]+a[1][j];
               l[1][j]=1;
			}
		else 
		    { f[1][j]=f[0][j-1]+t[0][j]+a[1][j];
               l[1][j]=0;
			}
			
		
	 }
	 if((f[0][n-1]+x[0])<=(f[1][n-1]+x[1]))
	     {final=f[0][n-1]+x[0];
	     k=0;}
	 else
	      {final=f[1][n-1]+x[1];
	      k=1;}
	 cout<<"min time"<<final<<"\n";

path_find(k,n-1);
 //print path
 cout<<"line \t station\n";
 
 for(j=0;j<n;j++)
        { if (s[0][j]==true)
           cout<<1<<"\t"<<j+1;
          
          if (s[1][j]==true)
           cout<<2<<"\t"<<j+1;
          cout<<"\n";
		}
   
	      
return 0;
}
