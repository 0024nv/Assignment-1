#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int x=0;
void display(int arr[],int i,int j)
{
    printf("%d\n",x);
    printf("A[%d,%d] == A[%d][%d] = %d \n",i,j,i,j,arr[x*i + j]);
}
int main(){
    int n=0;
    printf("Enter size of 1D matrix: ");
    scanf("%d",&n);
    x = ceil(sqrt(n));
    int *A = (int *)calloc(x*x,sizeof(int));
    for(int q=0;q<n;q++){
        scanf("%d",A+q);
        printf("%d\n",A[q]);
    }
    display(A,3,0);
    return 0;
}