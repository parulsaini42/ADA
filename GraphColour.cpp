#include<iostream>
using namespace std;
#define V 4
bool graph[V][V] = {{0, 1, 1, 1},
                    {1, 0, 1, 0},
                    {1, 1, 0, 1},
                    {1, 0, 1, 0},
    };
    int m = 3; 
int colour[V];
void Nextcolor(int);

void GC(int k)
{ //Assign colour
  Nextcolor(k);
  if(colour[k]==0)
  { cout<<"colour cannot be alloted\n";
    return;
  }
  //All vertices alloted
  if(k==V)
  return; 
  else
  //call with next vertex
  GC(k+1);
}

void Nextcolor(int k)
{ int j;
  do
   { 
   colour[k]=(colour[k]+1)%(m+1);
    //number of colours greater than m
     if(colour[k]==0)
     return;   
   
 for(j=0;j<V;j++)
   {//if edge exists and colour of end vertices is same 
     if(graph[k][j]!=0 && (colour[k]==colour[j]))
     break;
   }
    //repeat while all colours checked 
}while(j!=V);
}

int main()
{ int i,k=0;
for(i=0;i<V;i++)
  { colour[i]=0;
    }
  
GC(k);

  for(i=0;i<V;i++)
  cout<<i<<"\t";
  cout<<"\n";
  cout<<"colour alloted\n";
  for(i=0;i<V;i++)
      cout<<colour[i]<<"\t";
return 0;
}
