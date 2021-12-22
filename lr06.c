#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include "my-func.h"

int main() {
    int what;
    char byk, x;
    for(;;) {
        size_t n = 10, m = 10;
        printf("--------------------------------------------------------------------------------");
        puts("\nВЫБЕРИТЕ ЗАДАНИЕ (1 - 4). ESC - для выхода.\n");
        puts("[1] - Найти минимальный элемент в каждой строке матрицы. Затем каждую строку матрицы умножить на минимальный элемент строки\n");
        puts("[2] - Среднее арифметическое положительных элементов, верхней треугольной матрицы, расположенной выше главной диагонали\n");
        puts("[3] - Упорядочить по убыванию последнюю строку матрицы\n");
        puts("[4] - Упорядочить по возрастанию параллель побочной диагонали, расположенной над диагональю\n");
        if (1 != scanf("%c", &byk) && byk <= 31) {
            puts("ERROR\n");
            return 1;
            exit(1);
        }
        x = getchar();
        if (byk == 10) {
            swap(&byk, &x);
        }
        if (byk == 27 || x == 27) {
            break;
            return 0;
        }
        if (byk == 10 && x == 10) {
            break;
            return 0;
        }
        puts("\nВЫБЕРИТЕ ВАРИАНТ ВВОДА ДАННЫХ (1-4)\n");
        puts("[1] - в теле прогарммы\n");
        puts("[2] - из консоли\n");
        puts("[3] - из файла\n");
        puts("[4] - random\n");
        if (1 != scanf("%d", &what)) {
            puts("Error");
            return 1;
            exit(1);
        }
        if (what == 1) {
        sleep(0);
        }
        else {
	        puts("\nВВЕДИТЕ 2 ЧИСЛА (Количество строк - n и количество столбцов - m) (n,m <= 10)\n");
            if (2 != scanf("%zu %zu", &n, &m)) {
                puts("ERROR\n");
                return 1;
                exit(1);
            }
        }
        if (n < 0 || m < 0 || n > 10 || m > 10) {
            puts("Неверный размер матрицы\n");
            continue;
        }
        zad(byk, what, n, m);
    }
}
