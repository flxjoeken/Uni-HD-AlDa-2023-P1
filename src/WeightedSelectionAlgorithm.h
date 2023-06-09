#include "Element.h"
#include <vector>

/**
 * In dieser Klasse muessen Sie Ihre Implementierung Ihres Algorithmus einfügen.
 */
class WeightedSelectionAlgorithm {

public:
  WeightedSelectionAlgorithm()= default;
  virtual ~WeightedSelectionAlgorithm()= default;

  int weightedSelectionAlgorithm(std::vector<Element> &elements, double q); 
};
