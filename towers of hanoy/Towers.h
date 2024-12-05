#ifndef TOWERS_H
#define TOWERS_H

#include "Stackt.h"

class Towers {
private:
    Stackt<int> Source;  // Stack for the source tower
    Stackt<int> Target;  // Stack for the target tower
    Stackt<int> Aux;     // Stack for the auxiliary tower
    int N;              // Number of disks

    void moveDisk(Stackt<int>& source, Stackt<int>& target, const char* sourceName, const char* targetName);
    void solve(int N, Stackt<int>& source, Stackt<int>& target, Stackt<int>& aux, const char* sourceName, const char* targetName, const char* auxName);

public:
    Towers(int n);    // Constructor to initialize the towers with N disks
    void solve();     // Public function to initiate the solution
};

#endif
