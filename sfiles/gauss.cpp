//
// Created by Ivan Potyomin on 23.04.24.
//

#include <iostream>
#include "../hfiles/config.h"
#include "../hfiles/func.h"

double gauss(double a, double b) {
    int amountNodes = 7;
    double sum = 0;

    switch (amountNodes) {
        case 1:
            sum += (b-a)*(weights1[0] * func(a + (b - a) * nodes1[0]));
            break;
        case 2:
            for (int i = 0; i < amountNodes; i++) {
                sum += (b-a)*(weights2[i] * func(a + (b - a) * nodes2[i]));
            }
            break;
        case 3:
            for (int i = 0; i < amountNodes; i++) {
                sum += (b-a)*(weights3[i] * func(a + (b - a) * nodes3[i]));
            }
            break;
        case 4:
            for (int i = 0; i < amountNodes; i++) {
                sum += (b-a)*(weights4[i] * func(a + (b - a) * nodes4[i]));
            }
            break;
        case 5:
            for (int i = 0; i < amountNodes; i++) {
                sum += (b-a)*(weights5[i] * func(a + (b - a) * nodes5[i]));
            }
            break;
        case 6:
            for (int i = 0; i < amountNodes; i++) {
                sum += (b - a) * (weights6[i] * func(a + (b - a) * nodes6[i]));
            }
            break;
        case 7:
            for (int i = 0; i < amountNodes; i++) {
                sum += (b - a) * (weights7[i] * func(a + (b - a) * nodes7[i]));
            }
            break;
    }

    std::cout << sum;

    return 0;
}