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
    int cMatrix[N][N];

    printf("\nPlease fill in the matrix A(3x3)\n");
    fill_matrix((int*)aMatrix);

    printf("\nThe matrix A(3x3):\n");
    print_matrix((int*)aMatrix);

    printf("\nPlease fill in the matrix B(3x3)\n");
    fill_matrix((int*)bMatrix);

    printf("\nThe matrix B(3x3):\n");
    print_matrix((int*)bMatrix);

    printf("\nmatrix A(3x3) * matrix B(3x3):\n");

    short i = 0, j = 0, k = 0;

    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {

            cMatrix[i][j] = 0;

            for (int k = 0; k < N; k++)
                cMatrix[i][j] += aMatrix[i][k] * bMatrix[k][j];
        }
    }
    print_matrix((int*)cMatrix);

    return 0;
}