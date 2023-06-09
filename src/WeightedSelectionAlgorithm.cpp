#include "WeightedSelectionAlgorithm.h"
#include <vector>
#include <cstdio>

int WeightedSelectionAlgorithm::weightedSelectionAlgorithm(std::vector<Element> &elements, double q) {

    //input values are
    printf("\n");
    printf("q: %f\n", q);
    printf("elements: ");
    for (auto &element: elements) {
        printf("Weight: %d, Value: %d; ", element.getWeight(), element.getValue());
    }
    printf("\n");

    double sum = 0;
    for (auto &element: elements) {
        sum += element.getWeight();
    }
    sum *= q;

    double left_sum = 0;

    printf("sum: %f\n", sum);

    for (auto &element: elements) {
        left_sum += element.getWeight();
        if (left_sum >= sum) {
            printf("returning %d\n", element.getValue());
            return element.getValue();
        }
    }
    return elements.end()->getValue();
}
