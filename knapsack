#include<iostream>
using namespace std;
struct element
{ float x; 
float profit;
float weight;
float ratio;
}n[10];
class knapsack
{
 
public:
	void insert();
    void sortp(float);
    void sortw(float);
     void sortpw(float);
};

void knapsack::insert()
{ int i;
for (i=1;i<=4;i++)
   {cout<<"enter profit and weight for elemnt "<<i<<"\t"; 
   cin>>n[i].profit;
   cin>>n[i].weight;
   }
}
//sorting profit in decreasing order
void knapsack::sortp(float m)   
{int hold,j,i;
float p=0;
float w=0;
int t=4;     //no of elements
for(i=1;i<t;i++)
     { for(j=1;j<=t-i;j++)
          { if (n[j].profit<n[j+1].profit)
             {
		         n[10]=n[j];
		         n[j]=n[j+1];
		         n[j+1]=n[10];
				     }
		       }
		}
cout<<"sorted profit in decreasing order \n";
for(i=1;i<=4;i++)
{ cout<<n[i].profit<<"\t";
  cout<<n[i].weight<<"\n";
}

for(i=1;i<=t;i++)
{    if(n[i].weight>m)
          break;
     else
       { n[i].x=1;          //complete inclusion of the item into the knapsack
	       w=w+n[i].weight;
         m=m-n[i].weight;    //total capacity reduced
         p=p+n[i].profit*n[i].x;
        }
}
  if(i<=t)
   { n[i].x= m/n[i].weight; //incorporating fractional item to achieve max capacity
     p=p+n[i].profit*n[i].x;
   }

  
cout<<"max profit when profit sorted"<<p;
  }

//sorting weight in increasing order
void knapsack::sortw(float m)   
{  int hold,j,i;
   float p=0;
   float w=0;
   int t=4;     //no of elements
   for(i=1;i<t;i++)
     { for(j=1;j<=t-i;j++)
          { if (n[j].weight>n[j+1].weight)
                {
		         n[10]=n[j];
		         n[j]=n[j+1];
		         n[j+1]=n[10];
				 }
		  }
		  }
cout<<"\nsorted weight in increasing order\n";
for(i=1;i<=4;i++)
{ cout<<n[i].profit<<"\t";
  cout<<n[i].weight<<"\n";
}

for(i=1;i<=t;i++)
{    if(n[i].weight>m)
          break;
     else
       { n[i].x=1;          //complete inclusion of the item into the knapsack
	       w=w+n[i].weight;
         m=m-n[i].weight;    //total capacity reduced
         p=p+n[i].profit*n[i].x;
        }
}
  if(i<=t)
   { n[i].x= m/n[i].weight; //incorporating fractional item to achieve max capacity
     p=p+n[i].profit*n[i].x;
   }

  
cout<<"max profit when weights sorted"<<p;
  }
 
 //sorting profit-weight ratio in decreasing order
void knapsack::sortpw(float m)   
{
 int hold,j,i;
 float p=0;
 float w=0;
 int t=4;     //no of elements
 for(i=1;i<=4;i++)
{   
   n[i].ratio=n[i].profit/n[i].weight;
}
for(i=1;i<t;i++)
     { for(j=1;j<=t-i;j++)
          { if (n[j].ratio<n[j+1].ratio)
                {
		         n[10]=n[j];
		         n[j]=n[j+1];
		         n[j+1]=n[10];
				 }
		  }
		  }
cout<<"\nsorted p-w ratio in decreasing order \n";
for(i=1;i<=4;i++)
{ cout<<n[i].profit<<"\t";
  cout<<n[i].weight<<"\t";
  cout<<n[i].ratio<<"\n";
}

for(i=1;i<=t;i++)
{    if(n[i].weight>m)
          break;
     else
       { n[i].x=1;          //complete inclusion of the item into the knapsack
	       w=w+n[i].weight;
         m=m-n[i].weight;    //total capacity reduced
         p=p+n[i].profit*n[i].x;
        }
}
  if(i<=t)
   { n[i].x= m/n[i].weight; //incorporating fractional item to achieve max capacity
     p=p+n[i].profit*n[i].x;
   }

  
cout<<"max profit when p-w ratio sorted"<<p;
  } 



int main()
{
knapsack k;
float m;
k.insert();
cout<<"insert max weight \n";
cin>>m;
k.sortp(m);
k.sortw(m);
k.sortpw(m);
return 0;
}
