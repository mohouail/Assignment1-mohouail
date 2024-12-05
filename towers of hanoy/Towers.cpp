#include "Towers.h"
#include <iostream>

// Constructor to initialize the towers and populate the Source stack with N disks
Towers::Towers(int n) : N(n), Source(n), Target(n), Aux(n) {
    // Initialize the Source tower with disks in descending order
    for (int i = N; i >= 1; i--) {
        Source.push(i);
    }
}

// Function to simulate moving a disk from source to target
void Towers::moveDisk(Stackt<int>& source, Stackt<int>& target, const char* sourceName, const char* targetName) {
    if (!source.isEmpty()) {
        int disk = source.pop();  // Pop the top disk from the source stack
        target.push(disk);        // Push the disk to the target stack
        std::cout << "Move disk " << disk << " from " << sourceName << " to " << targetName << std::endl;
    }
}

// Recursive function to solve Towers of Hanoi
void Towers::solve(int N, Stackt<int>& source, Stackt<int>& target, Stackt<int>& aux, const char* sourceName, const char* targetName, const char* auxName) {
    if (N == 1) {
        moveDisk(source, target, sourceName, targetName);  // Base case: move disk 1 directly
    } else {
        solve(N - 1, source, aux, target, sourceName, auxName, targetName);  // Move N-1 disks from Source to Aux via Target
        moveDisk(source, target, sourceName, targetName);                    // Move the Nth disk from Source to Target
        solve(N - 1, aux, target, source, auxName, targetName, sourceName);  // Move N-1 disks from Aux to Target via Source
    }
}

// Public function to initiate the Towers of Hanoi solution
void Towers::solve() {
    std::cout << "Solving Towers of Hanoi for " << N << " disks:" << std::endl;
    solve(N, Source, Target, Aux, "Source", "Target", "Aux");
}
