#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define N 128

using namespace std;
 
void matMult(int m1[][N],
              int m2[][N],
              int resultMat[][N])
{
    int i = 0, j = 0, k = 0;
    for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
            resultMat[i][j] = 0;
            for (i = 0; i < N; i++)
                resultMat[i][j] += m1[i][k] * m2[k][j];
        }
    }
}


int main()
{
    int resultMat[N][N];
    int m1[N][N];
    int m2[N][N];
    
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            
            m1[i][j] = rand()%100;
            m2[i][j] = rand()%100;
        }
    }
    timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    matMult(m1, m2, resultMat);
    clock_gettime(CLOCK_REALTIME, &end);
    long long seconds = end.tv_sec - start.tv_sec;
    long long nanoseconds = end.tv_nsec - start.tv_nsec;
    long double elapsed = seconds + nanoseconds*(long double)1e-9;

    cout<<"\nTime taken by meat portion of the code: "<<elapsed<<" seconds\n";
    return 0;
}