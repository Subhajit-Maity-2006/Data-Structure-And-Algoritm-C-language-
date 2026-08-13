//convert the sparce matrix into traditional matrix


#include<stdio.h>
void triplateform(int row,int col,int a[row][col]);
int main(){
    int row,col;
    printf("put the row of the matrix:");
    scanf("%d",&row);
    printf("Put the coloum of the matrix:");
    scanf("%d",&col);
    int a[row][col];
    printf("Print the matri element:");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&a[i][j]);
        }
    }
    triplateform(row,col,a);
    return 0;
}
void triplateform(int row,int col,int a[row][col]){
    //in triplate form we have to count the non zero element so we have to take a count variable
    int count =0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]!=0){
                count ++;
            }
        }
    }
    //create the sparce matrix
    int sparcemat[count+1][3];//count+1 bcz in row first row alaways define the three parameter.
    //Assign 3 value of 1 st row 
    sparcemat[0][0]=row;
    sparcemat[0][1]=col;
    sparcemat[0][2]=count;
    //Enter tyhe value in sparce matrix
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]!=0){
                sparcemat[k][0]=i;
                sparcemat[k][1]=j;
                sparcemat[k][2]=a[i][j];
                k++;
            }
        }
    }
    //disp;ay the psarce matrix 
    printf("Sparce matrix is :\n");
    printf("Row\tcolumn\tvalue\n");
    for(int i=0;i<=count;i++){
        printf("%d\t %d\t %d\n",
            sparcemat[i][0],
            sparcemat[i][1],
            sparcemat[i][2]
        );
    }

}