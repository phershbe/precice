#include "MinIterationConvergenceMeasure.hpp"
#include "cplscheme/impl/ConvergenceMeasure.hpp"

namespace precice::cplscheme::impl {

MinIterationConvergenceMeasure::MinIterationConvergenceMeasure(
    int minimumIterationCount)
    : ConvergenceMeasure(),
      _minimumIterationCount(minimumIterationCount)
{
}

void MinIterationConvergenceMeasure::newMeasurementSeries()
{
  _currentIteration = 0;
  _isConvergence    = false;
}
} // namespace precice::cplscheme::impl
