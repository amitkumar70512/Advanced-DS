#include <iostream.h>  
#include <conio.h>  
 int size=16;
 int parent[16];

void create_list() // function to create list & assign parents
{
 for(int i=0;i<size;i++)
 {
    parent[i]=i; 
 }
 cout << " \n printing parents :> \n ";
 for(int k=0;k<size;k++)
 {
     cout << "parent of  "<< k << "is : " << parent[k] << "\n " ;
 }
 
}



// find function  to fnd parent 

int  find(int x)
{
   return parent[x]; 
}

// to find adjacent
int check_adj(int i, int j)// i=0   j=1
{
    
        if((i==j+4)||(i+1==j)||(i-1==j)||(i==j-4)) // if adjacent
        {
            cout << i << " and " << j << " are adjacent...\n ";
            return 1;
        }
        else 
        return 0;

    
}



// function to perform union 
void union(int p, int q){
    if(check_adj(p,q))
    {
        if(find(p)==find(q)) // parents are same
        {
            return;
        }
        else
        {
           parent[q]=p;// parent of 'q' is changed to parent of p ...
        }
    }
}



void main() {  
   clrscr(); 
   create_list();
   
   int i,j;
   
   for(i=0;i<size;i++){
       for(j=0;j<size;j++){
          
                if(i!=j){
                    union(i,j);
                   
                }
           
       }
   }
   
   getch();  
}  
