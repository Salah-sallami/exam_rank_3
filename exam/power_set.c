#include <stdio.h>
#include <stdlib.h>

void print_subset(int *subset, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i > 0)
            printf(" ");
        printf("%d", subset[i]);
    }
    printf("$\n");
}
void backtrack(int *arr,int index, int n, int target,  int *subset, int subset_size, int current_sum)
{
    if (index == n)
    {
        if (current_sum == target)
            print_subset(subset, subset_size);
        return;
    }

    // index + 1
    backtrack(arr,index + 1, n, target,  subset, subset_size, current_sum);

    subset[subset_size] = arr[index];
    backtrack(arr,index + 1, n, target,  subset, subset_size + 1, current_sum + arr[index]);
}

int main(int ac, char **av)
{
    if (ac < 2)
        return 1;
    int target = atoi(av[1]);
    int n = ac - 2;
    int *arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        arr[i] = atoi(av[i + 2]);

    int *subset = malloc(sizeof(int) * n);
    backtrack(arr,0, n, target,  subset, 0, 0);

    free(arr);
    free(subset);
    return 0;
}
