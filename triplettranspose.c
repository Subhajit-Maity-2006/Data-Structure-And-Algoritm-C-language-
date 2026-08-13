#include<stdio.h>
void readmatrix(int triplet[][3],int nonzero);
void transmat(int triplet[][3],int trans[][3]);
void displaymatrix(int trans[][3]);
int main(){
    int row,col,nonzero;
    printf("Put the value of row:");
    scanf("%d",&row);
    printf("Put the value of col:");
    scanf("%d",&col);
    printf("Enter the number of nonzero element:");
    scanf("%d",&nonzero);
    int triplet[nonzero+1][3];
    int trans[nonzero+1][3];
    triplet[0][0]=row;
    triplet[0][1]=col;
    triplet[0][2]=nonzero;
    readmatrix(triplet,nonzero);
    transmat(triplet,trans);
    displaymatrix(trans);
    return 0;
}
void readmatrix(int triplet[][3],int nonzero){
    printf("Enter row,col and value:\n");
    for(int i=0;i<=nonzero;i++){
        scanf("%d %d %d",
        &triplet[i][0],
        &triplet[i][1],
        &triplet[i][2]
        );
    }
}
void transmat(int triplet[][3],int trans[][3]){
    int row=triplet[0][0];
    int col=triplet[0][1];
    int nonzero=triplet[0][2];

    trans[0][0]=col;
    trans[0][1]=row;
    trans[0][2]=nonzero;
    int k=1;
    for(int j=0;j<col;j++){
        for(int i=1;i<=nonzero;i++){
            if(triplet[i][j]==j){
                trans[k][0]=triplet[i][1];
                trans[k][1]=triplet[i][0];
                trans[k][2]=triplet[i][2];
                k++;
            }
        }
    }
}
void displaymatrix(int trans[][3]){
    int nonzero=trans[0][2];
    printf("\n transpose in 3 tuple form:\n");
    printf("row\t column\tvalue\n");
    for(int i=0;i<=nonzero;i++){
        printf("%d\t %d\t %d\n",
        trans[i][0],
        trans[i][1],
        trans[i][2]
        );
    }
}