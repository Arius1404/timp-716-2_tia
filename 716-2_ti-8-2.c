#include <stdio.h>

int pyramid_sort(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return 0;
}
int main()
{
    int n, i, step = 0, b = 0;
    scanf ("%i", &n);
    int a[n];
    for (i = 0; i < n; ++i)
        scanf ("%i", &a[i]);
    while (1)
    {
        b = 0;
        for (i = 0; i < n; ++i)
        {
            if (i*2 + 2 + step < n)
            {
                if (a[i+step] > a[i*2 + 1 + step] || a[i + step] > a[i*2 + 2 + step])
                {
                    if (a[i*2+1+step] < a[i*2+2+step])
                    {
                        pyramid_sort(&a[i+step], &a[i*2+1+step]);
                        b = 1;
                    }
                    else if (a[i*2+2+step] < a[i*2+1+step])
                    {
                        pyramid_sort(&a[i+step],&a[i*2+2+step]);
                        b = 1;
                    }
                }
            }
            else if (i * 2 + 1 + step < n)
            {
                if (a[i+step] > a[i*2+1+step])
                {
                    pyramid_sort(&a[i+step], &a[i*2+1+step]);
                    b=1;
                }
            }
        }
        if (!b)
            step++;
        if (step+2==n)
            break;
    }
    for (i = 0; i < n; ++i)
        printf ("%d\t", a[i]);
    printf ("\n");
    return 0;
}

