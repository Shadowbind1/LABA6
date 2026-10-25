#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


int is_leap(int year);
double F(double x);
void print_age(int birth_year, int current_year);

int main(void)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF-8");

    int choice;

    printf("=== Работа 6. Разветвляющиеся алгоритмы ===\n");
    printf("1 - Проверка високосного года\n");
    printf("2 - Вычисление F(x) (вариант 4)\n");
    printf("3 - Возраст по году рождения (вариант 4)\n");
    printf("Выберите задание: ");
    scanf("%d", &choice);


    if (choice == 1)
    {
        int year;
        printf("Введите год: ");
        scanf("%d", &year);

        if (is_leap(year))
            printf("Год %d високосный\n", year);
        else
            printf("Год %d не високосный\n", year);
    }

    
    else if (choice == 2)
    {
        double x, result;
        printf("Введите x: ");
        scanf("%lf", &x);

        result = F(x);
        printf("F(%.2f) = %.6f\n", x, result);
    }

    /* Задание 3 (вариант 4) */
    else if (choice == 3)
    {
        int birth, current = 2026;   /* текущий год */
        printf("Введите год рождения: ");
        scanf("%d", &birth);

        print_age(birth, current);
    }

    else
    {
        printf("Неверный номер задания!\n");
    }

    return 0;
}


/* Задача 1: високосный год */
int is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* Задача 2: F(x) вариант 4 */
double F(double x)
{
    if (x <= 1.0)
        return 0.0;
    else
        return 1.0 / (x + 6.0);
}

/* Задание 3: возраст с правильным склонением */
void print_age(int birth_year, int current_year)
{
    int age = current_year - birth_year;
    int last = age % 10;
    int last2 = age % 100;

    printf("%d ", age);

    if (last2 >= 11 && last2 <= 14)
        printf("лет\n");
    else if (last == 1)
        printf("год\n");
    else if (last >= 2 && last <= 4)
        printf("года\n");
    else
        printf("лет\n");
}