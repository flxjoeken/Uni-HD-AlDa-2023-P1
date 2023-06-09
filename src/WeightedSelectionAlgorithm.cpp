//#define DEBUG 1

#include "WeightedSelectionAlgorithm.h"
#include <vector>
#include <cstdio>

int WeightedSelectionAlgorithm::weightedSelectionAlgorithm(
        std::vector<Element> &elements, double q) {
    double sum = 0;
    for (auto &element: elements) {
        sum += element.getWeight();
    }
    sum *= q;

#ifdef DEBUG
    printf("q: %f\n", q);
    printf("Elements: \n");
    //weight and value of the elements
    //for (auto element: elements) {
    //    printf("value: %d, weight: %d\n", element.getValue(), element.getWeight());
    //}
    printf("weighted_sum_over_all: %f\n", sum);
    printf("\n");
#endif

    int result = sum_of_weights(elements, 0, elements.size() - 1, sum);
#ifdef DEBUG
    printf("result: %d\n", result);
    printf("\n------------------------------------------\n\n");
#endif
    return elements[result].getValue();
}

int WeightedSelectionAlgorithm::sum_of_weights(std::vector<Element> &elements, int left, int right,
                                               double weighted_sum_over_all) {
    //some debug printing
#ifdef DEBUG
    //printf("left: %d, right: %d\n", left, right);
#endif

    int pivot = left;
    Element pivot_element = elements[pivot];
    std::vector<Element> left_elements;
    std::vector<Element> right_elements;

    for (auto element: elements) {
        if (element.getValue() < elements[pivot].getValue()) {
            left_elements.push_back(element);
        } else if (element.getValue() > elements[pivot].getValue()) {
            right_elements.push_back(element);
        }
    }
    elements = left_elements;
    elements.push_back(pivot_element);
    elements.insert(elements.end(), right_elements.begin(), right_elements.end());

    //calc sum
    long sum_without_piv = 0;
    for (auto element: left_elements) {
        sum_without_piv += element.getWeight();
    }
    long sum_with_piv = sum_without_piv + elements[left_elements.size()].getWeight();

    if (sum_with_piv >= weighted_sum_over_all && sum_without_piv < weighted_sum_over_all) {
        return left_elements.size();
    } else if (left == right) {
        return left;
    } else if (sum_with_piv < weighted_sum_over_all) {
        return sum_of_weights(elements, left_elements.size() + 1, right, weighted_sum_over_all);
    } else {
        return sum_of_weights(elements, left, left_elements.size() - 1, weighted_sum_over_all);
    }
}