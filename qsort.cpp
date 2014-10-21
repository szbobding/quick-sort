/************************************************
 *
 * file  : qsort.cpp
 * author: bobding
 * date  : 2014-10-21
 * detail: create
 *
************************************************/

#include <stdio.h>
#include <algorithm>

void qsort(int* array, int s, int e)
{
    if (s >= e) return;

    int i = s, j = s;
    while (++j < e)
    {
        if (array[j] < array[s]) std::swap(array[++i], array[j]);
    }
    std::swap(array[s], array[i]);

    qsort(array, s, i);
    qsort(array, i + 1, e);
}

int main()
{
    int a[] = { 8, 9, 2, 6, 5, 4 ,5, 3, 0, 1, 7 };
    
    int count = sizeof(a) / sizeof(a[0]);
    qsort(a, 0, count);

    for (int i=0; i<count; ++i)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}