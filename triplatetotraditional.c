#include<stdio.h>
void traditionalform(int triplate[][3],int nonzero);
int main(){
    int row,col,nonzero;
    printf("Enter number of rows: ");
    scanf("%d", &row);

    printf("Enter number of columns: ");
    scanf("%d", &col);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &nonzero);
    // Triplet has nonzero+1 rows because first row stores row, column and nonzero count
    int triplate[nonzero+1][3];
    triplate[0][0]=row;
    triplate[0][1] =col;
    triplate[0][2]=nonzero;
    printf("Enter row col and value:");
    for(int i=1;i<=nonzero;i++){
        scanf("%d %d %d",
            &triplate[i][0],
            &triplate[i][1],
            &triplate[i][2]);
    
    }
    traditionalform(triplate,nonzero);
    return 0;
}
void traditionalform(int triplate[][3],int nonzero){
    int row = triplate[0][0];
    int col=triplate[0][1];
    int a[row][col];

    //Initially make all element zero
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            a[i][j]=0;
        }
    }

    //put the nonzero element in thier position
    for(int k=1;k<=nonzero;k++){
        int i = triplate[k][0];
        int j=triplate[k][1];
        a[i][j]=triplate[k][2];
    }
    printf("\n traditional matris is :\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }


}