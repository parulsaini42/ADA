
#include<iostream>
using namespace std;
#define n 6
#define m 6
int mat[n+1][m+1];
char S[n+1][m+1];//print lcs
char a[n]={'A','B','A','Z','D','C'};
char b[m]={'B','A','C','B','A','D'};


void find_lcs(char S[][m+1],int i,int j)
{ if(i>0 && j>0)
 { if(S[i][j]=='d')
     { find_lcs(S,i-1,j-1);
       cout<<a[i-1];
	 }
      
   else if (S[i][j]=='l')
      find_lcs(S,i,j-1);
    else
      find_lcs(S,i-1,j);
   }
   return;
 }
  


int main()
{ 

for(int i=0;i<=n;i++)
 { for(int j=0;j<=m;j++)
     { if(i==0||j==0)
        {mat[i][j]=0;
           if(i==0 && j!=0)
             S[i][j]='l'; //move left
           if(j==0 && i!=0)
              S[i][j]='u';//move up
              if(j==0 && i==0)
              S[i][j]='u';//any
		}
		else if(a[i-1]==b[j-1])
            { mat[i][j]=(1 + mat[i-1][j-1]);
              S[i][j]='d'; //move diagonal
					}		
		else 
		   { if(mat[i-1][j]<mat[i][j-1])
		       { mat[i][j]=mat[i][j-1];
		        S[i][j]='l';}
		     else
		       { mat[i][j]=mat[i-1][j];
		        S[i][j]='u';}
	       }
      }
 }
 cout<<"\t";
 for(int j=0;j<=m;j++)
 cout<<b[j]<<"\t";
 cout<<"\n";
 for(int i=0;i<=n;i++)
 { for(int j=0;j<=m;j++)
   { cout<<mat[i][j]<<"\t";
   }
   cout<<"\n";
 }
 cout<<"S matrix\n";
 for(int i=0;i<=n;i++)
 { for(int j=0;j<=m;j++)
   { cout<<S[i][j]<<"\t";
   }
   cout<<"\n";
 }
 
 cout<<"longest common subsequence is of the length\t"<<mat[n][m]<<"\n";
 cout<<"longest common subsequence is \t";
 find_lcs(S,n,m);
 
return 0;
}
