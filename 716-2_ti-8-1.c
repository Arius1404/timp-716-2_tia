#include <stdio.h>
int first, last;
void Hoarsort(int *mas, int first, int last)
{
    int mid, count;
    int f=first, l=last;
    mid=mas[(f+l) / 2];
    do
    {
        while (mas[f]<mid)
            f++;
        while (mas[l]>mid)
            l--;
        if (f<=l)
        {
            count=mas[f];
            mas[f]=mas[l];
            mas[l]=count;
            f++;
            l--;
        }
    } while (f<l);
    if (first<l) Hoarsort(mas, first, l);
    if (f<last) Hoarsort(mas, f, last);
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int *a = &arr[0];
    for (int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    first=0; last=n-1;
    Hoarsort(a, first, last);
    for (int i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
