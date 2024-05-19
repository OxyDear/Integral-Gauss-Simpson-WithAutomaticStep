//
// Created by Ivan Potyomin on 23.04.24.
//

#include <iostream>
#include "../hfiles/config.h"
#include "../hfiles/main.h"

double gauss_with_step(double a, double b) {
    double h = (b - a);
    double integral = 0.0;
    double previous_integral = 0.0;
    int max_iterations = 7;

    for (int i = 1; i <= max_iterations; ++i) {

        // Метод Гаусса
        double sum = 0.0;
        int amountNodes = i;

        switch (amountNodes) {
            case 1:
                sum += (b - a) * (weights1[0] * func(a + (b - a) * nodes1[0]));
                break;
            case 2:
                for (int j = 0; j < amountNodes; j++) {
                    sum += (b - a) * (weights2[j] * func(a + (b - a) * nodes2[j]));
                }
                break;
            case 3:
                for (int j = 0; j < amountNodes; j++) {
                    sum += (b - a) * (weights3[j] * func(a + (b - a) * nodes3[j]));
                }
                break;
            case 4:
                for (int j = 0; j < amountNodes; j++) {
                    sum += (b - a) * (weights4[j] * func(a + (b - a) * nodes4[j]));
                }
                break;
            case 5:
                for (int j = 0; j < amountNodes; j++) {
                    sum += (b - a) * (weights5[j] * func(a + (b - a) * nodes5[j]));
                }
                break;
            case 6:
                for (int j = 0; j < amountNodes; j++) {
                    sum += (b - a) * (weights6[j] * func(a + (b - a) * nodes6[j]));
                }
                break;
            case 7:
                for (int j = 0; j < amountNodes; j++) {
                    sum += (b - a) * (weights7[j] * func(a + (b - a) * nodes7[j]));
                }
                break;
        }

        integral = sum;

        // Адаптивный выбор нового шага интегрирования
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

        // Оценка погрешности с использованием средних
        double error = std::abs(integral - previous_integral);

        // Проверка погрешности
        if (error < std::abs(sumSred - sumTrap)) {
            return integral;
        }

        h /= 2.0;
        previous_integral = integral;
    }

    std::cout << "Максимальное число итераций достигнуто." << std::endl;
    return integral;
}
