#include <iostream>
#include "hfiles/main.h"

using namespace std;

int main() {

    int chs = 1, a = -2, b = 3;

    while (chs == 1 || chs == 2 || chs == 3 || chs == 4) {
        cout << "\n1 - simpson\n"
                "2 - simpson with step\n"
                "3 - gauss\n"
                "4 - gauss with step\n\n";

        cin >> chs;

        switch (chs) {
            case 1:
                cout << "\033[1;31m" << "\nintegral simpson: " << simpson(a, b) << "\033[1;37m" << endl;
                break;
            case 2:
                cout << "\033[1;32m" << "\nintegral simpson with step: " << simpson_with_step(a, b) << "\033[1;37m" << endl;
                break;
            case 3:
                cout << "\033[1;33m";
                gauss(a, b);
                cout << "\033[1;37m" << endl;
                break;
            case 4:
                cout << "\033[1;34m" << "\nintegral gauss with step: " << gauss_with_step(a, b) << "\033[1;37m" << endl;
                break;
        }
    }

    return 0;
}
