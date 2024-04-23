//
// Created by Ivan Potyomin on 23.04.24.
//

#include <iostream>
#include "../hfiles/simpson_with_step.h"
#include "../hfiles/func.h"

double simpson_for_step(double a, double b, double h) {
    int n = (b - a) / h;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4.0 * func(x);
    }

    for (int i = 2; i < n - 1; i += 2) {
        double x = a + i * h;
        sum += 2.0 * func(x);
    }

    return (h / 3.0) * sum;
}

double simpson_with_step(double a, double b) {
    double h = (b - a);  // Начальный шаг интегрирования
    double integral = 0.0;
    double previous_integral = 0.0;
    int max_iterations = 1000;  // Максимальное число итераций

    for (int i = 0; i < max_iterations; ++i) {

        // Метод Симпсона
        integral = simpson_for_step(a, b, h);

        int n = 1000;
        double step = (b-a)/n;
        double sumTrap = 0.0;
        double x;

        // Метод трапеций
        sumTrap += (func(a) + func(b)) / 2.0;

        for (int k = 1; k < n; ++k) {
            x = a + k * step;  // Точка на интервале
            sumTrap += func(x);
        }

        sumTrap = step * sumTrap;

        // Метод средних
        double sumSred = 0.0;

        for (int k = 0; k < n; ++k) {
            x = a + (k + 0.5) * step;  // Точка внутри прямоугольника
            sumSred += func(x);
        }

        sumSred = step * sumSred;

        // Оценка погрешности
        double error = std::abs(integral - previous_integral);

        // Проверка погрешности
        if (error < std::abs(sumSred - sumTrap)) {
            return integral;
        }

        // Адаптивный выбор нового шага интегрирования
        h /= 2.0;
        previous_integral = integral;
    }

    std::cout << "Максимальное число итераций достигнуто." << std::endl;
    return integral;
}
