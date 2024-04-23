//
// Created by Ivan Potyomin on 23.04.24.
//

#include "../hfiles/simpson.h"
#include "../hfiles/func.h"

double simpson(double a, double b, int n) {
    double h = (b-a)/n, sum = 0;

    for (double x = a; x <= b; x+=h) {
        sum += (func(x) + 4 * func(x + h / 2) + func(x + h));
    }

    return sum*h/6;
}
