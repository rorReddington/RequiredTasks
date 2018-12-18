#define N 3

void fill_matrix(int* matrix)
{
    short i = 0;
    short j = 0;

    for (i = 0; i < N; i++)
    {

        printf("Elements of %lu row: ", i + 1);
        for (j = 0; j < N; j++)
            scanf("%i", &matrix[i * N + j]);
    }
}

void print_matrix(int* matrix)
{
    short i = 0;
    short j = 0;

    for (i = 0; i < N; i++)
    {

        for (j = 0; j < N; j++)
            printf("%5i", matrix[i * N + j]);

        printf("\n");
    }
}

int main()
{
    int aMatrix[N][N];
    int bMatrix[N][N];

    printf("\nPlease fill in the matrix(3x3)\n");
    fill_matrix((int*)aMatrix);

    printf("\nThe matrix(3x3):\n");
    print_matrix((int*)aMatrix);

    printf("\nThe rotated matrix(3x3):\n");

    short i = 0, j = 0;

    for (; i < N; i++)
    {

        short k = 0;

        for (j = N - 1; j >= 0; j--)
        {

            bMatrix[i][k] = aMatrix[j][i];
            k++;
        }
    }

    print_matrix((int*)bMatrix);

    return 0;
}