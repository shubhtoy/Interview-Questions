#include <stdio.h>
int n;

void merge(int St[], int Ft[], int low, int mid, int hi)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = hi - mid;

    int L1[n1], R1[n2];
    int L2[n1], R2[n2];

    for (i = 0; i < n1; i++)
        L1[i] = St[low + i];
    for (j = 0; j < n2; j++)
        R1[j] = St[mid + 1 + j];

    for (i = 0; i < n1; i++)
        L2[i] = Ft[low + i];
    for (j = 0; j < n2; j++)
        R2[j] = Ft[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (L2[i] <= R2[j])
        {
            St[k] = L1[i];
            Ft[k] = L2[i];
            i++;
        }
        else
        {
            St[k] = R1[j];
            Ft[k] = R2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        St[k] = L1[i];
        Ft[k] = L2[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        St[k] = R1[j];
        Ft[k] = R2[j];
        j++;
        k++;
    }
}

void merge_sort(int St[], int Ft[], int low, int hi)
{
    if (low < hi)
    {
        int mid = (low + hi) / 2;
        int mid1 = (low + mid) / 2;
        int mid2 = (mid + hi) / 2;
        merge_sort(St, Ft, low, mid1);
        merge_sort(St, Ft, mid1 + 1, mid);
        merge_sort(St, Ft, mid + 1, mid2);
        merge_sort(St, Ft, mid2 + 1, hi);
        merge(St, Ft, low, mid1, mid);
        merge(St, Ft, mid1, mid, mid2);
        merge(St, Ft, mid, mid2, hi);
    }
}

int main()
{
    printf("enter the total number of jobs : ");
    scanf("%d", &n);
    int St[n];
    int Ft[n];
    int ques[n][2];
    for (int i = 0; i < n; i++)
    {
        printf("Enter start time of job %d: ", i + 1);
        scanf("%d", &St[i]);
        ques[i][0] = St[i];
        printf("Enter Finishing time of job %d: ", i + 1);
        scanf("%d", &Ft[i]);
        ques[i][1] = Ft[i];
    }
    merge_sort(St, Ft, 0, n - 1);
    int ans[n][2];

    ans[0][0] = St[0];
    ans[0][1] = Ft[0];
    int j = 1;
    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (St[i] < Ft[i - j])
        {
            ans[i][0] = -1;
            ans[i][1] = -1;
            j++;
        }
        else
        {
            ans[i][0] = St[i];
            ans[i][1] = Ft[i];
            j = 1;
        }
    }

    printf("\nall jobs are: ");
    for (int i = 0; i < n; i++)
    {
        printf(" (%d,%d)", ques[i][0], ques[i][1]);
    }
    printf("\n");

    printf("\nmaximum of jobs can be scheduled: ");
    for (int i = 0; i < n; i++)
    {
        if (ans[i][0] != -1)
        {
            printf("(%d,%d) ", ans[i][0], ans[i][1]);
            c++;
        }
    }
    int conflicts[n];
    for (int i = 0; i < n; i++)
    {
        int c2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if ((ques[i][0] <ques[j][1] && ques[i][0] >= ques[j][0]) || (ques[i][1] <= ques[j][1] && ques[i][1] > ques[j][0]  || ques[i][0]<=ques[j][0] && ques[i][1]>=ques[j][1]  || ques[i][0]>=ques[j][0] && ques[i][1]<=ques[j][1]))
                {
                    c2++;
                }
            }
        }
        conflicts[i] = c2;
    }



    int max_c = 0;
    int min_c = n;
    printf("\nnumber of conflicts of jobs are : \n");
    for (int i = 0; i < n; i++)
    {
        if (conflicts[i]>max_c)
        {
            max_c = conflicts[i];
        }
        if (conflicts[i]<min_c)
        {
            min_c = conflicts[i];
        }
        printf("(%d,%d)=%d\n", ques[i][0], ques[i][1], conflicts[i]);
    }
    printf("\n");

    printf("jobs with maximum conflicts are : ");
    for (int i = 0; i < n; i++)
    {
        if (conflicts[i] == max_c)
        {
            printf("(%d,%d)  ", ques[i][0], ques[i][1]);
        }
    }
    printf("\n");

    printf("jobs with minimum conflicts are : ");
    for (int i = 0; i < n; i++)
    {
        if (conflicts[i] == min_c)
        {
            printf("(%d,%d) ", ques[i][0], ques[i][1]);
        }
    }
    printf("\n\n");
}