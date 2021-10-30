#include <iostream>

using namespace std;

int rows=5,columns=5;
int mat[5][5]={1,1,0,0,0,0,1,0,0,1,1,0,0,1,1,0,0,0,0,0,1,0,1,0,1};
int rank_ele[25];//rank of elements
int parent_mat[25];// respective parents of all elements

int i,j,k;


void create_list()
{
    for( k=0;k<25;k++)
    {
        parent_mat[k]=k;// assigning parents itself  to all elements
        rank_ele[k]=0;// assigning rank 0 to all
    }
   
}

void print_mat()
{
    cout<<"\n Printing entered matrix::\n";
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++)
        {
           cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

// printing parent_of_element
int find(int ele)
{
  if(parent_mat[ele]==ele)
  {
      
    return parent_mat[ele]; 
  }

  else 
  {
  parent_mat[ele]=find(ele); //  compression
  return parent_mat[ele];
  }
  
}

// to check whether island are adjacents or not and return true or false
int check_adj(int i,int j)
{

        if(i==(j+5)||i==(j-5)||i==(j+1)||i==(j-1)||i==(j+6)||i==(j-6)||i==(j+4)||i==(j-4))
        {
            cout<<i<<"and "<< j <<"are adjacent islands";
            return 1;
        }
        else 
        return 0;
            
}
int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else if(x==y){
        return x;
        rank_ele[x]++;
    }
    else
    return y;
}

void Union(int p,int q)
{
    if(check_adj(p,q) )
    {
        if(find(p)!=find(q))
        { 
          int max_rank_parent=max(rank_ele[p],rank_ele[q]);// find parent having max rank
          
          parent_mat[q]=max_rank_parent;
          
        }
    }
}



int main()
{
    create_list();
    print_mat();
    
    
    for(i=0;i<25;i++){
        for(j=0;j<25;j++)
        {
            if((i!=j) &&(mat[i]==mat[j]==1)){
               Union(i,j);
            }
            
        }
    }

cout<<"\n displaying parents of all elemetns";
for(i=0;i<25;i++)
    {
        cout<<"\t"<<parent_mat[i];
    }
    
cout<<"\n\n displaying ranks of all elemetns";    
for(i=0;i<25;i++)
    {
        cout<<"\t"<<rank_ele[i];
    }
     /*   
for(i=0;i<25;i++){
int parent= print_parent_of_list(i);
cout<<endl<<parent;
    
 }
 */

return 0;
}
