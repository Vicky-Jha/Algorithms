//quicksort
#include<stdio.h>
int number[25];
void quicksort(int first,int last){
    int i, j, pivot, temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(number[i]<=number[pivot])
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(first,j-1);
        quicksort(j+1,last);
    }
}
int main(){
    int i, count;
    printf("Enter size (Max. - 25): \n");
    scanf("%d",&count);
    printf("Enter %d elements:\n",count);
    for(i=0;i<count;i++)
        scanf("%d",&number[i]);
    quicksort(0,count-1);
    printf("The Sorted Order is:\n");
    for(i=0;i<count;i++)
        printf(" %d",number[i]);
    printf("\n");
    return 0;
}
