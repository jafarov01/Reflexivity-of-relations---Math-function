#include <stdio.h>


int main()
{
    int n, check = 0, count = 0, checkReflection = 0, checkSym = 0;
    printf("Enter the number of elements in set A: "); scanf_s("%d", &n);
    int a[2]; //1 2 3 4 5
    int x[1000], y[1000];
    int tempx, tempy;

    for (int i = 0; i < n; i++) //n = 2
    {
        scanf_s("%d", &check); //
        if (check > 0) 
        {
            if (i == 0)
                a[i] = check; //1
            if (i >= 1) { //1
                for (int j = 0; j < i; j++)
                {
                    if (check == a[j])
                    {
                        do {
                            printf("This value already exists! Enter different number: ");
                            scanf_s("%d", &check);
                        } while (check == a[j]);
                        a[i] = check;
                    }
                    else
                        a[i] = check;
                }
            }
        }
        else if (check <= 0)
        {
            do {
                printf("Enter only positive number!: ");
                scanf_s("%d", &check);
                //i--;
            } while (check <= 0);
            a[i] = check;
        }
    }

    printf("---------------------------------------------------------\n");
    printf("A = {");
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
        {
            printf("%d, ", a[i]);
        }
        else if (i == n - 1)
        {
            printf("%d", a[i]);
        }
    }
    printf("}\n");

    for (int i = 0; i < n; i++) //0 1 2 3 4
    {
        for (int j = 0; j < n; j++) //01234
        {
            if ((2 - a[j]) % a[i] == 0)
            {
                tempx = a[i];
                tempy = a[j];
                x[count] = tempx;
                y[count] = tempy;
                count++;
            }
        }
    }
    printf("X = {");
    for (int i = 0; i < count; i++)
    {
        if (i != count - 1)
        {
            printf("%d, ", x[i]);
        }
        else if (i == count - 1)
        {
            printf("%d", x[i]);
        }
    }

    printf("}\nY = {");

    for (int i = 0; i < count; i++)
    {
        if (i != count - 1)
        {
            printf("%d, ", y[i]);
        }
        else if (i == count - 1)
        {
            printf("%d", y[i]);
        }
    }

    printf("}\n");


    for (int i = 0; i < count; i++) //(4,2), (2,4), (2,2) //(4,4), (2,4), (2,2)  //(1,1), (1,2) (2,2)  //(1,1) (2,2) //3
    {
        if (x[i] == y[i])
        {
            checkReflection++;
        }
        if (checkReflection == n) {
              i = i + count;
        }
    }

    checkSym = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (x[i] == y[j])
            {
                if (x[j] == y[i])
                {
                    checkSym++;
                }
            }
        }
    }
    printf("---------------------------------------------------------\nResults:\n");
    if (count != 0)
    {
        if (checkSym == count)
            printf("\tThis relation is symmetric.\n");
        else if (checkSym != count)
            printf("\tThis relation is NOT symmetric.\n");

        if (checkReflection == n)
            printf("\tThis relation is reflexive.\n");
        else if (checkReflection != n)
            printf("\tThis relation is NOT reflexive.\n");
    }
    else
        printf("\tThe relation set is empty.\n");
    return 0;
}