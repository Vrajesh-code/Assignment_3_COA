from audioop import mul
import random
import time


def mul_mat(N):
    rslt = [[0] * N] * N
    mat1 = [[0] * N] * N
    mat2 = [[0] * N] * N
    serial = 0

    for i in range(0, N):
        for j in range(0, N):
            mat1[i][j] = random.randint(0, 50)

    for i in range(0, N):
        for j in range(0, N):
            mat2[i][j] = random.randint(0, 50)

    start = time.time()
    for k in range(0, N):
        for j in range(0, N):
            rslt[i][j] = 0

            for i in range(0, N):
                rslt[i][j] += mat1[i][k] * mat2[k][j]
    end = time.time()
    program_time = end - start
    return program_time


N = 128
print(mul_mat(N))
