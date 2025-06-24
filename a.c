#include <stdlib.h>
#include <stdio.h>


void print_sol(int *sub,int size)
{
    int i = 0 ;
    while (i < size)
    {
    if (i > 0)
            printf(" ");
        printf("%d",sub[i]);
        i++;
    }
    printf("$\n");
    
}

void   pwr(int *arr,int n,int target,int index,int *subset,int subset_size ,int current_sum)
{
    if(index == n)
    {
        if(current_sum == target)
            print_sol(subset, subset_size);
        return;
    }

    pwr(arr,n,target,index + 1,subset,subset_size,current_sum);

    subset[subset_size] = arr[index];
    pwr(arr,n,target,index + 1,subset,subset_size + 1,current_sum + arr[index]);

}


int main(int ac ,char **av)
{
    int n = ac - 2;
    int target = atoi(av[1]);
    int *subset = malloc(sizeof(int) * (n ));
    int *arr = malloc(sizeof(int) * (n ));

    int i = 0 ;
    while (i < n)
    {
        arr[i] = atoi(av[i + 2]);
        i++;
    }
    

    //antissc
    pwr(arr,n,target,0,subset,0,0);

}