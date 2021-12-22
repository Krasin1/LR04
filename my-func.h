#include<float.h>
float read_float();

int qqfloat(const void *pa, const void *pb) {
    float a = *(float *)pa, b = *(float *)pb;
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}
int qfloat(const void *pa, const void *pb) {
    float a = *(float *)pa, b = *(float *)pb;
    if (a > b)
        return -1;
    if (a < b)
        return 1;
    return 0;
}

void array_scan(float **array, size_t n, size_t m) {
    if (array) {
        for (size_t i = 0; i < n; i += 1) {
            printf(
                "Введите строку №%zu (количество элементов должно быть - %zu) \n", i
                + 1, m);
            for (size_t j = 0; j < m; j += 1) {
                array[i][j] = read_float();
            }
        }
    }
}

void file_matr(float **array, size_t *n, size_t *m) {
    int flag = 0;
    FILE *myfile = fopen("data.txt", "r");
    if (myfile != NULL) {
        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *m; j++) {
                if (0 == fscanf(myfile, "%f", &array[i][j])) {
                    puts("Нехватка данных\n");
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        fclose(myfile);
    } else {
        puts("Не могу открыть файл, друг\n");
    }
}

void print_matr(float **array, size_t n, size_t m) {
    puts("");
    printf("       j =");
    for (size_t j = 0; j < m; j += 1) {
        printf("%11zu", j + 1);
    }
    puts("");
    for (size_t i = 0; i < n; i += 1) {
        printf("a[%2zu][j] = ", i + 1);
        for (size_t j = 0; j < m; j += 1) {
            printf("%11.3f", array[i][j]);
        }
        puts("");
    }
}

void vvod(int what, float **array, size_t *n, size_t *m) {
    if (what == 1) {
        *n = 4;
        *m = 4;
        puts("\n\nЭтот способ с фиксированым массивом\n");
        for (size_t i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4; j++) {
                array[i][j] = (float)(i + j) + powf((float)(1 + i + j), -1);
            }
        }
        printf("\nДанная матрица\n");
        print_matr(array, *n, *m);
    } else if (what == 2) {
        array_scan(array, *n, *m);
        printf("\nДанная матрица\n");
        print_matr(array, *n, *m);
    } else if (what == 3) {
        file_matr(array, n, m);
        printf("\nДанная матрица\n");
        print_matr(array, *n, *m);
    } else if (what == 4) {
        srand(time(NULL));
        for (size_t i = 0; i < *n; i++) {
            for (size_t j = 0; j < *m; j++) {
                array[i][j] = (float)(rand()) / RAND_MAX * 200 - 100;
            }
        }
        printf("\nДанная матрица\n");
        print_matr(array, *n, *m);

    } else {
        puts("Такого варианта нет\n");
    }
}

void file_float(float *array, size_t *n, size_t *m) {
    int flag = 0;
    FILE *myfile = fopen("data.txt", "r");
    if (myfile != NULL) {
        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *m; j++) {
                if (0 == fscanf(myfile, "%f", (array + (i * *m) + j))) {
                    puts("Нехватка данных\n");
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        fclose(myfile);
    } else {
        puts("Не могу открыть файл, друг\n");
    }
}

float read_float() {
    float a = 0;
    if (1 == scanf("%f", &a)) {
        return a;
    }
    puts("ERROR!!!\n");
    return 0;
}

void array_float_fill(float *array, size_t n, size_t m) {
    if (array) {
        for (size_t i = 0; i < n; i += 1) {
            printf(
                "Введите строку №%zu (количество элементов должно быть - %zu) \n", i
                + 1, m);
            for (size_t j = 0; j < m; j += 1) {
                *(array + (i * m) + j) = read_float();
            }
        }
    }
}

void vivod(float *array, const size_t n, const size_t m) {
    puts("");
    printf("       j =");
    for (size_t j = 0; j < m; j += 1) {
        printf("%11zu", j + 1);
    }
    puts("");
    for (size_t i = 0; i < n; i += 1) {
        printf("a[%2zu][j] = ", i + 1);
        for (size_t j = 0; j < m; j += 1) {
            printf("%11.3f", *(array + (i * m) + j));
        }
        puts("");
    }
}

void fill(float *array, int what, size_t *n, size_t *m) {
    if (what == 1) {
        puts("Этот способ с фиксированным массивом\n");
        for (size_t i = 0; i < 16; i++) {
            *(array + i) = (float)i + powf((float)(1 + i), -1);
        }
        printf("\nДанная матрица\n");
        vivod(array, 4, 4);
    } else if (what == 2) {
        array_float_fill(array, *n, *m);
        printf("\nДанная матрица\n");
        vivod(array, *n, *m);
    } else if (what == 3) {
        file_float(array, n, m);
        printf("\nДанная матрица\n");
        vivod(array, *n, *m);
    } else if (what == 4) {
        srand(time(NULL));
        for (size_t i = 0; i < (*n * *m); i++) {
            *(array + i) = (float)(rand()) / RAND_MAX * 200 - 100;
        }
        printf("\nДанная матрица\n");
        vivod(array, *n, *m);
    } else {
        puts("Такого способа нет\n");
    }
}

void zad(char byk, int what, size_t n, size_t m) {
    if (byk == 49) {
        float *array = malloc(sizeof(float) * n * m);
        fill(array, what, &n, &m);
        if (what == 1) {
            n = 4;
            m = 4;
        }
        float min = FLT_MAX;
        for (size_t i = 0; i < n; i += 1) {
            for (size_t j = 0; j < m; j += 1) {
                if ((*(array + (i * m) + j) - min) < -0.0001) {
                    min = *(array + (i * m) + j);
                }
            }
            for (size_t j = 0; j < m; j += 1) {
                *(array + (i * m) + j) *= min;
            }
            puts("");
            printf("Миниальный элемент в строке №%zu = %.3f\n", i + 1, min);
            min = FLT_MAX;
        }
        if (what > 0 && what < 5) {
            puts("\nРезультат:\n");
            if (what != 1) {
                vivod(array, n, m);
            } else {
                vivod(array, 4, 4);
            }
        }
        free(array);
        n = 10;
        m = 10;
    } else if (byk == 50) {
        if (n != m) {
            puts("Данная матрица не является квадратом\n");
            n = 10;
            m = 10;
            return;
        }
        float **array;
        array = (float **)malloc(n * sizeof(float *));
        for (size_t i = 0; i < n; i++) {
            array[i] = (float *)malloc(m * sizeof(float));
        }
        vvod(what, array, &n, &m);
        float sum_e = 0.0;
        int sum_i = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i; j < m; j++) {
                if (i != j && array[i][j] > 0) {
                    sum_e += array[i][j];
                    sum_i += 1;
                }
            }
        }
        puts("Результат:\n");
        printf("Среднее арифметическое положительных элементов\n"
               "\nтреугольной матрицы, расположенной выше главной диагонали"
               " == %f\n",
               sum_e / sum_i);
        for (size_t i = 0; i < n; i++) {
            free(array[i]);
        }
        free(array);
        n = 10;
        m = 10;
    } else if (byk == 51) {
        float **array;
        array = (float **)malloc(n * sizeof(float *));
        for (size_t i = 0; i < n; i++) {
            array[i] = (float *)malloc(m * sizeof(float));
        }
        vvod(what, array, &n, &m);
        qsort(array[n - 1], m, sizeof(float), qfloat);
        puts("\nРезультат:\n");
        puts("\nПоследнаяя строка по убыванию\n");
        print_matr(array, n, m);
        for (size_t i = 0; i < n; i++) {
            free(array[i]);
        }
        free(array);
        n = 10;
        m = 10;
    } else if (byk == 52) {
        if (n != m) {
            puts("Данная матрица не является квадратом\n");
            n = 10;
            m = 10;
            return;
        }
        float **array;
        array = (float **)malloc(n * sizeof(float *));
        for (size_t i = 0; i < n; i++) {
            array[i] = (float *)malloc(m * sizeof(float));
        }
        vvod(what, array, &n, &m);
        float *a;
        a = malloc((m - 1) * sizeof(float));
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j += 1) {
                if (i + j == n - 2) {
                    a[j] = array[i][j];
                }
            }
        }
        qsort(a, m - 1, sizeof(float), qqfloat);
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j += 1) {
                if (i + j == n - 2) {
                    array[i][j] = a[j];
                }
            }
        }

        puts("\nРезультат:\n");
        print_matr(array, n, m);
        for (size_t i = 0; i < n; i++) {
            free(array[i]);
        }
        free(array);
        n = 10;
        m = 10;
    } else {
        puts("Такого задания нет\n");
    }
}

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
