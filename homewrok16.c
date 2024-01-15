#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <Windows.h>

double* generate_array(int* size);
double* create_array_d(double* a, double* b, double* c, int size_a, int size_b, int size_c, int* size_d);
void print_array(double* array, int size);

int main() {

    setlocale(LC_CTYPE, "RUS");

    srand(time(NULL));

    int size_a, size_b, size_c, size_d;
    double *a, *b, *c, *d;

    a = generate_array(&size_a);
    b = generate_array(&size_b);
    c = generate_array(&size_c);

    d = create_array_d(a, b, c, size_a, size_b, size_c, &size_d);
    printf("Массив A\n");
    print_array(a, size_a);
    printf("\nМассив B\n");
    print_array(b, size_b);
    printf("\nМассив C\n");
    print_array(c, size_c);
    printf("\nИзменённый массив D:\n");
    print_array(d, size_d);
    system("pause");

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}

double* generate_array(int* size) {
    *size = rand() % 41 + 10;
    double* array = (double*)malloc(*size * sizeof(double));

    for (int i = 0; i < *size; ++i) {
        array[i] = ((double)rand() / RAND_MAX) * 20 - 10;
    }

    return array;
}

double* create_array_d(double* a, double* b, double* c, int size_a, int size_b, int size_c, int* size_d) {
    *size_d = (size_a < size_b && size_a < size_c) ? size_a : (size_b < size_c ? size_b : size_c);

    double* d = (double*)malloc(*size_d * sizeof(double));

    for (int i = 0; i < *size_d; i++) {
        d[i] = (a[i] < b[i] && a[i] < c[i]) ? a[i] : ((b[i] < c[i]) ? b[i] : c[i]);
    }

    return d;
}

void print_array(double* array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("| %.2lf |", array[i]);
    }
    printf("\n\n");
}
