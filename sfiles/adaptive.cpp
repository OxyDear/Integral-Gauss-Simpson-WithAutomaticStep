//
// Created by Ivan Potyomin on 2.06.24.
//

#include "../hfiles/main.h"

double adaptive(double a, double b) {
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

    return sumSred - sumTrap;
}
