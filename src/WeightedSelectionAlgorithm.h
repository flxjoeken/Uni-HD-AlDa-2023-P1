#include "Element.h"
#include <vector>

/**
 * In dieser Klasse muessen Sie Ihre Implementierung Ihres Algorithmus einfügen.
 */
class WeightedSelectionAlgorithm {

    // TODO: implement algorithm
public:
    WeightedSelectionAlgorithm() {};

    virtual ~WeightedSelectionAlgorithm() {};

    int weightedSelectionAlgorithm(std::vector<Element> &elements, double q);

    int sum_of_weights(std::vector<Element> &elements, int left, int right, double weighted_sum_over_all);
};
