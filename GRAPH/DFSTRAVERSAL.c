#include<stdio.h>
#define MAX 100
void DFS(int adj[MAX][MAX],int n,int start );
int main(){
    int n;
    int adj[MAX][MAX];
    int start;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter stert vertex:");
    scanf("%d",&start);

    DFS(adj,n,start);
    return 0;
}

//Function defination 
void DFS(int adj[MAX][MAX],int n,int start ){
    int flag[MAX];
    int stack[MAX];
    int top=-1;
    //1.Flag 1 for all node
    for(int i =0;i<n;i++){
        flag[i]=1;
    }
    //2.Push first node
    stack[++top]=start;
    //3.set flag=2 means waiting
    flag[start]=2;
    printf("Depth First Search: ");
    //4.repeat until stack is empty
    while(top!=-1){
        //pop
        int x= stack[top--];
        //process x
        printf("%d",x);
        //set flag 3 means process
        flag[x]=3;
        //Check all neighbour
        //From n-1 to 0 to get the require dfs order
        for(int y=n-1;y>=0;y--){
            if(adj[x][y]==1 && flag[y]==1){ //x is the vertex that we just popped from the stack.
                //y represents the possible neighbour of x.
                //Push neighbour
               stack[++top]=y;
               flag[y]=2;
            }
        }
    }
    printf("\n");
}
