#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

void inp_val(double&, double&, double&, double&, int&);
double* mas_A(double, double, double, double, int, int&);
void out_mas(double*, int);

int main(int argc, char* argv[]) {
    system("chcp 1251>nul");
    double x, y, zn, s;
    int num;
    if (argc != 6) {
        printf("В командной строке исходных данных недостаточно!\n");
        inp_val(x, y, zn, s, num);
    }
    else if (atof(argv[1]) && atof(argv[2]) && atof(argv[3]) && atof(argv[4]) && atoi(argv[5])) {
        x = atof(argv[1]);
        y = atof(argv[2]);
        zn = atof(argv[3]);
        s = atof(argv[4]);
        num = atoi(argv[5]);
    }
    else {
        printf("Исходные данные некорректны!\n");
        inp_val(x, y, zn, s, num);
    }
    printf("исходные данные: x = %6.3f, y = %6.3f, zn = %6.3f, s = %6.3f, num = %i\n", x, y, zn, s, num);
    system("pause");
    char c;
    do {
        system("cls");
        printf("Главное меню\n");
        printf("Ввод исходных данных (нажмите 0)\n");
        printf("Расчет A             (нажмите 1)\n");
        printf("Расчет B             (нажмите 2)\n");
        printf("Расчет C             (нажмите 3)\n");
        printf("Выход                (нажмите 4)\n");

        c = getchar();
        switch (c) {
        case '0': {
            system("cls");
            printf("Ввод исходных данных\n");
            inp_val(x, y, zn, s, num);
        } break;
        case '1': {
            system("cls");
            printf("Расчет A\n");
            int size_a;
            double* mas_a = mas_A(x, y, zn, s, num, size_a);
            out_mas(mas_a, size_a);
            system("pause");
        } break;
        case '2': {
            system("cls");
            printf("Расчет B\n");
            while ((c = getchar()) != '\n' && c != EOF) continue;  // очиска входного буфера после предыдущего ввода
            system("pause");
        } break;
        case '3': {
            system("cls");
            printf("Расчет C\n");
            while ((c = getchar()) != '\n' && c != EOF) continue;  // очиска входного буфера после предыдущего ввода
            system("pause");
        } break;
        case '4': {
            system("cls");
            printf("Выйти? y/n");
            while ((c = getchar()) != '\n' && c != EOF) continue;  // очиска входного буфера после предыдущего ввода
            c = getchar();
        }
        }
    } while (c != 'y');
    return 0;
}

void inp_val(double& x, double& y, double& z, double& s, int& num) {
    printf("Введите значение переменной x\n");
    scanf_s("%lf", &x);
    printf("Введите значение переменной y\n");
    scanf_s("%lf", &y);
    printf("Введите значение переменной zn\n");
    scanf_s("%lf", &z);
    printf("Введите значение переменной s\n");
    scanf_s("%lf", &s);
    printf("Введите значение переменной num\n");
    scanf_s("%i", &num);
}

void out_mas(double* p_mas, int size) {
    printf("Массив результатов расчета\n");
    for (int i{}; i < size; i++) {
        printf("mas[%i] = %6.3f\n", i, p_mas[i]);
    }
}

double* mas_A(double x, double y, double zn, double s, int num, int& size) {
    size = 0;
    double z = zn;
    for (int i{}; i < num; i++, z += s) // подсчет количества возможных итераций
        if (z >= 0)
            size++;
    double* m_A = new double[size];
    z = zn;
    for (int i{}; i < num; i++, z += s) {
        if (z >= 0) {
            m_A[i] = (x + y) * sqrt(z);
        }
        else
            continue;
    }
    return m_A;
}