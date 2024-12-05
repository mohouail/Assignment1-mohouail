#include <iostream>
#include "Towers.h"


int main() {
    int N = 3;  // Number of disks
    Towers hanoi(N);  // Create a Towers object with N disks
    hanoi.solve();    // Solve the Towers of Hanoi problem

    return 0;
}
