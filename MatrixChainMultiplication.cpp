#include<iostream>
using namespace std;
# define n 5 //no of matrices
int m[n][n];
int S[n][n];

void print_p(int S[][5],int i,int j)
{  if (i == j)
    {
        cout<<"A"<<i;
        return;
    }
    cout<<"(";

    print_p(S,i, S[i][j]);

    print_p(S,S[i][j]+1, j);

    cout<<")";
}

int main()
{ int i,j,k,L,v;
int p[6]={5,10,4,3,5,10};
for (i=1; i<=n; i++)
    {
        for(j=1;j<=n;j++)
        { if(i==j||j<i)
		m[i][i] = 0;
        }
    }

for (i=1; i<=n; i++)
    {
        for(j=1;j<=n;j++)
        {
		S[i][i] = 0;
        }
    }
    //filling upper diagonal matrix    
    for (L=2; L<=n; L++)
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<j; k++)
            {
                v= m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (v< m[i][j])
                {
                    m[i][j] = v;
                    S[i][j] = k;//break point
                }
            }
        }
    }

for(i=1;i<=n;i++)
   {
	  for(j=1;j<=n;j++)
	     {
	     	cout<<m[i][j]<<"\t";
		 }
		 cout<<"\n";
    }

cout<<"min number of multiplications is"<<"\t"<<m[1][n]<<"\n";

for(i=1;i<=n;i++)
   {
	  for(j=1;j<=n;j++)
	     {
	     	cout<<S[i][j]<<"\t";
	     	
		 }
		 cout<<"\n";

    }
    
print_p(S,1,n);
return 0;
}
