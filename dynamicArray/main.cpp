#include "array.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

int main() {
    DynamicArray<int>* testArray = new DynamicArray<int>();

    const int order = 7;
    const int n = static_cast<int>(pow(10, order));

    clock_t t1Total = clock();
    double maxTimePerElement = 0.0;

    for (int i = 0; i < n; i++) {
        int element = (rand() % 20);

        clock_t t1Element = clock();
        testArray->add(element);
        clock_t t2Element = clock();

        double timePerElement = static_cast<double>(t2Element - t1Element) / CLOCKS_PER_SEC;
        if (timePerElement > maxTimePerElement) {
            maxTimePerElement = timePerElement;
            std::cout << "New worst time on index: " << i
                << ": " << maxTimePerElement << " second\n";
        }
    }

    clock_t t2Total = clock();
    double totalTime = static_cast<double>(t2Total - t1Total) / CLOCKS_PER_SEC;

    std::cout << "Total time: " << totalTime << " second\n";
    std::cout << "Worst time for single addition: "
        << maxTimePerElement << " sekund\n";
    std::cout << "Array content: " << testArray->toString() << "\n";

    testArray->clear();
    delete testArray;

    return 0;
}