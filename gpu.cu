#ifndef GPU_C
#define GPU_C

#include <stdio.h>

// CUDA Kernel function to add two numbers
__global__ void add(int a, int b, int *c)
{
    *c = a + b;
}

int calculate()
{
    int a, b, c; // Host copies of a, b, c
    int *d_c;    // Device copy of c
    int size = sizeof(int);

    // Setup input values
    a = 2;
    b = 7;

    // Allocate space for device copy of c
    cudaMalloc((void **)&d_c, size);

    // Launch add() kernel on GPU with one thread
    add<<<1, 1>>>(a, b, d_c);

    // Copy result back to host
    cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);

    // Cleanup
    cudaFree(d_c);

    printf("Result: %d + %d = %d\n", a, b, c);
    return 0;
}

#endif