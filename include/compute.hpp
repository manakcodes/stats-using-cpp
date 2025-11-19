#include "utility.hpp"
#pragma once

// ========================================================================== //
// FUNCTION -> returns `TRUE` if `dataset X[1..n]` is sorted otherwise `FALSE`
// ========================================================================== //
bool DataSetIsSorted(const vector<double> &dataset)
{
    int size = dataset.size();
    for (int i = 0; i < size - 1; i++)
    {
        if (IS_GREATER(dataset[i], dataset[i + 1]))
        {
            return false;
        }
    }
    return true;
}

// ========================================================================== //
// FUNCTION -> returns the `sum` of the `dataset X[1..n]`
// ========================================================================== //
double GetSum(const vector<double> &dataset)
{
    int size = dataset.size();
    double sum = 0.0000;

    for (int i = 0; i < size; i++)
    {
        sum += dataset[i];
    }

    return sum;
}

// ========================================================================== //
// FUNCTION -> returns the `mean` of the `dataset X[1..n]`
// ========================================================================== //

double GetMean(const vector<double> &dataset)
{
    return (GetSum(dataset) / dataset.size());
}

// ========================================================================== //
// FUNCTION -> returns the `mode` of the `dataset X[1..n]`
// ========================================================================== //
double GetMode(const vector<double> &dataset)
{
    map<double, int> freq;
    int size = dataset.size();

    for (int i = 0; i < size; i++)
    {
        freq[dataset[i]]++;
    }

    int MaxCount = 0;
    double mode = dataset[0];

    for (auto &p : freq)
    {
        if (p.second > MaxCount)
        {
            MaxCount = p.second;
            mode = p.first;
        }
    }

    return mode;
}

// ========================================================================== //
// FUNCTION -> returns the `median` of the `dataset X[1..n]`
// ========================================================================== //
double GetMedian(vector<double> dataset)
{
    int size = dataset.size();

    vector<double> temp = dataset;
    sort(temp.begin(), temp.end());

    if (size % 2 != 0)
    {
        return temp[size / 2];
    }
    else
    {
        double term1 = temp[(size / 2) - 1];
        double term2 = temp[size / 2];
        return (term1 + term2) / 2.0;
    }
}

// ========================================================================== //
// FUNCTION -> returns the `max` of the `dataset X[1..n]`
// ========================================================================== //
double GetMax(const vector<double> &dataset)
{
    double max = dataset[0];

    for (const auto i : dataset)
    {
        if (IS_GREATER(i, max))
        {
            max = i;
        }
    }

    return max;
}

// ========================================================================== //
// FUNCTION -> returns the `min` of the `dataset X[1..n]`
// ========================================================================== //
double GetMin(const vector<double> &dataset)
{
    double min = dataset[0];

    for (const auto i : dataset)
    {
        if (IS_GREATER(min, i))
        {
            min = i;
        }
    }

    return min;
}

// ========================================================================== //
// FUNCTION -> returns the `range` of the `dataset X[1..n]`
// ========================================================================== //
double GetRange(const vector<double> &dataset)
{
    return (GetMax(dataset) - GetMin(dataset));
}

// ========================================================================== //
// FUNCTION -> returns the `population variance` of the `dataset X[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetPopulationVariance(const vector<double> &dataset)
{
    double mean = GetMean(dataset);

    int size = dataset.size();

    double MeanSquaredDifferenceSum = 0.0000;

    for (int i = 0; i < size; i++)
    {
        MeanSquaredDifferenceSum += ((dataset[i] - mean) * (dataset[i] - mean));
    }

    if (size == 0)
    {
        return NAN;
    }

    return (MeanSquaredDifferenceSum / size);
}

// ========================================================================== //
// FUNCTION -> returns the `sample variance` of the `dataset X[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetSampleVariance(const vector<double> &dataset)
{
    double mean = GetMean(dataset);

    int size = dataset.size();

    double MeanSquaredDifferenceSum = 0.0000;

    for (int i = 0; i < size; i++)
    {
        MeanSquaredDifferenceSum += ((dataset[i] - mean) * (dataset[i] - mean));
    }

    if (size - 1 == 0)
    {
        return NAN;
    }

    return (MeanSquaredDifferenceSum / (size - 1));
}

// ========================================================================== //
// FUNCTION -> returns the `standard deviation` of the `dataset X[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetStandardDeviation(const vector<double> &dataset)
{
    double variance = GetSampleVariance(dataset);

    if (IS_INVALID(variance))
    {
        return NAN;
    }
    return sqrt(variance);
}

// ========================================================================== //
// FUNCTION -> returns the `energy` of the `dataset X[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetEnergy(const vector<double> &dataset)
{
    int size = dataset.size();
    double SquaredSum = 0.0000;

    for (int i = 0; i < size; i++)
    {
        SquaredSum += (dataset[i] * dataset[i]);
    }

    return SquaredSum;
}

// ========================================================================== //
// FUNCTION -> returns the `power` of the `dataset X[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetPower(const vector<double> &dataset)
{
    return (GetEnergy(dataset) / dataset.size());
}

// ========================================================================== //
// FUNCTION -> returns the `k-th central moment` of the `dataset X[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetKthCentralMoment(const vector<double> &dataset, int k)
{
    int size = dataset.size();
    double mean = GetMean(dataset);
    double DifferencedKSquare = 0.0000;

    for (int i = 0; i < size; i++)
    {
        DifferencedKSquare += (pow(dataset[i] - mean, k));
    }

    if (size == 0)
    {
        return NAN;
    }

    return (DifferencedKSquare / size);
}

// ========================================================================== //
// FUNCTION -> returns the `skewness` of the `dataset X[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetSkewness(const vector<double> &dataset)
{
    double ThirdMoment = GetKthCentralMoment(dataset, 3);
    double StandardDeviation = GetStandardDeviation(dataset);
    double StandardDeviationCube = pow(StandardDeviation, 3);

    if (IS_INVALID(ThirdMoment) ||
        IS_INVALID(StandardDeviation) ||
        IS_INVALID(StandardDeviationCube))
    {
        return NAN;
    }

    return (ThirdMoment / StandardDeviationCube);
}

// ========================================================================== //
// FUNCTION -> returns the `kurtosis` of the `dataset X[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetKurtosis(const vector<double> &dataset)
{
    double FourthMoment = GetKthCentralMoment(dataset, 4);
    double StandardDeviation = GetStandardDeviation(dataset);
    double StandardDeviationPower4 = pow(StandardDeviation, 4);

    if (IS_INVALID(FourthMoment) ||
        IS_INVALID(StandardDeviation) ||
        IS_INVALID(StandardDeviationPower4))
    {
        return NAN;
    }

    return (FourthMoment / StandardDeviationPower4);
}

// ========================================================================== //
// FUNCTION -> returns the `population covariance` of the `dataset X[1..n]` and
// `dataset Y[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetPopulationCovariance(const vector<double> &dataset_x, const vector<double> &dataset_y)
{
    double mean_x = GetMean(dataset_x);
    double mean_y = GetMean(dataset_y);

    int size = dataset_x.size();

    double DifferencedMeanSumXY = 0.0000;

    for (int i = 0; i < size; i++)
    {
        DifferencedMeanSumXY += ((dataset_x[i] - mean_x) * (dataset_y[i] - mean_y));
    }

    if (size == 0)
    {
        return NAN;
    }

    return (DifferencedMeanSumXY / size);
}

// ========================================================================== //
// FUNCTION -> returns the `sample covariance` of the `dataset X[1..n]` and
// `dataset Y[1..n]`
// in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetSampleCovariance(const vector<double> &dataset_x, const vector<double> &dataset_y)
{
    double mean_x = GetMean(dataset_x);
    double mean_y = GetMean(dataset_y);

    int size = dataset_x.size();

    double DifferencedMeanSumXY = 0.0000;

    for (int i = 0; i < size; i++)
    {
        DifferencedMeanSumXY += ((dataset_x[i] - mean_x) * (dataset_y[i] - mean_y));
    }

    if (size - 1 == 0)
    {
        return NAN;
    }

    return (DifferencedMeanSumXY / (size - 1));
}

// ========================================================================== //
// FUNCTION -> returns the `covariance coefficient` of the `dataset X[1..n]` and
// `dataset Y[1..n]` in case of INVALID VALUE returns `NAN`
// ========================================================================== //
double GetCorrelationCoefficient(const vector<double> &dataset_x, const vector<double> &dataset_y)
{
    double covariance = GetPopulationCovariance(dataset_x, dataset_y);
    double StandardDeviationX = sqrt(GetPopulationVariance(dataset_x));
    double GetStandardDeviationY = sqrt(GetPopulationVariance(dataset_y));

    if (IS_INVALID(covariance) ||
        IS_INVALID(StandardDeviationX) ||
        IS_INVALID(GetStandardDeviationY))
    {
        return NAN;
    }

    return (covariance / (StandardDeviationX * GetStandardDeviationY));
}

// ========================================================================== //
// FUNCTION ->
// creates and returns a collection of statistical parameters for a given
// dataset pair (X[1..n] and Y[1..n])
//
// RETURNS:
//   vector<vector<pair<string, double>>>
//     ├── index 0 → parameters of dataset X
//     ├── index 1 → parameters of dataset Y
//     └── index 2 → parameters involving both X and Y (XY)
//
// Each inner vector contains pairs of:
//     { "PARAMETER_NAME", value }
//
// PARAMETERS INCLUDED:
//   For X and Y individually:
//     - IS_SORTED
//     - SUM
//     - MEAN
//     - MODE
//     - MEDIAN
//     - MAX, MIN, RANGE
//     - POPULATION_VARIANCE
//     - SAMPLE_VARIANCE
//     - STANDARD_DEVIATION
//     - ENERGY, POWER
//
//   For combined XY:
//     - POPULATION_COVARIANCE
//     - SAMPLE_COVARIANCE
//     - CORRELATION_COEFFICIENT
//
// NOTES:
//   - the returned structure always has size = 3
//   - order of insertion is preserved for consistent table printing
// ========================================================================== //
vector<vector<pair<string, double>>> GetDataParameters(DataPair datapair)
{
    vector<pair<string, double>> parameters_x;
    vector<pair<string, double>> parameters_y;
    vector<pair<string, double>> parameters_xy;

    parameters_x.push_back({"IS_SORTED", DataSetIsSorted(datapair.dataset_x)});
    parameters_x.push_back({"SUM", GetSum(datapair.dataset_x)});
    parameters_x.push_back({"MEAN", GetMean(datapair.dataset_x)});
    parameters_x.push_back({"MODE", GetMode(datapair.dataset_x)});
    parameters_x.push_back({"MEDIAN", GetMedian(datapair.dataset_x)});
    parameters_x.push_back({"MAX", GetMax(datapair.dataset_x)});
    parameters_x.push_back({"MIN", GetMin(datapair.dataset_x)});
    parameters_x.push_back({"RANGE", GetRange(datapair.dataset_x)});
    parameters_x.push_back({"POPULATION_VARIANCE", GetPopulationVariance(datapair.dataset_x)});
    parameters_x.push_back({"SAMPLE_VARIANCE", GetSampleVariance(datapair.dataset_x)});
    parameters_x.push_back({"K_TH_CENTRAL_MOMENT_(k=0)", GetKthCentralMoment(datapair.dataset_y, 0)});
    parameters_x.push_back({"K_TH_CENTRAL_MOMENT_(k=1)", GetKthCentralMoment(datapair.dataset_x, 1)});
    parameters_x.push_back({"K_TH_CENTRAL_MOMENT_(k=2)", GetKthCentralMoment(datapair.dataset_x, 2)});
    parameters_x.push_back({"K_TH_CENTRAL_MOMENT_(k=3)", GetKthCentralMoment(datapair.dataset_x, 3)});
    parameters_x.push_back({"K_TH_CENTRAL_MOMENT_(k=4)", GetKthCentralMoment(datapair.dataset_x, 4)});
    parameters_x.push_back({"K_TH_CENTRAL_MOMENT_(k=5)", GetKthCentralMoment(datapair.dataset_x, 5)});
    parameters_x.push_back({"SKEWNESS", GetSkewness(datapair.dataset_x)});
    parameters_x.push_back({"KURTOSIS", GetKurtosis(datapair.dataset_x)});
    parameters_x.push_back({"STANDARD_DEVIATION", GetStandardDeviation(datapair.dataset_x)});
    parameters_x.push_back({"ENERGY", GetEnergy(datapair.dataset_x)});
    parameters_x.push_back({"POWER", GetPower(datapair.dataset_x)});

    parameters_y.push_back({"IS_SORTED", DataSetIsSorted(datapair.dataset_y)});
    parameters_y.push_back({"SUM", GetSum(datapair.dataset_y)});
    parameters_y.push_back({"MEAN", GetMean(datapair.dataset_y)});
    parameters_y.push_back({"MODE", GetMode(datapair.dataset_y)});
    parameters_y.push_back({"MEDIAN", GetMedian(datapair.dataset_y)});
    parameters_y.push_back({"MAX", GetMax(datapair.dataset_y)});
    parameters_y.push_back({"MIN", GetMin(datapair.dataset_y)});
    parameters_y.push_back({"RANGE", GetRange(datapair.dataset_y)});
    parameters_y.push_back({"POPULATION_VARIANCE", GetPopulationVariance(datapair.dataset_y)});
    parameters_y.push_back({"SAMPLE_VARIANCE", GetSampleVariance(datapair.dataset_y)});
    parameters_y.push_back({"STANDARD_DEVIATION", GetStandardDeviation(datapair.dataset_y)});
    parameters_y.push_back({"K_TH_CENTRAL_MOMENT_(k=0)", GetKthCentralMoment(datapair.dataset_y, 0)});
    parameters_y.push_back({"K_TH_CENTRAL_MOMENT_(k=1)", GetKthCentralMoment(datapair.dataset_y, 1)});
    parameters_y.push_back({"K_TH_CENTRAL_MOMENT_(k=2)", GetKthCentralMoment(datapair.dataset_y, 2)});
    parameters_y.push_back({"K_TH_CENTRAL_MOMENT_(k=3)", GetKthCentralMoment(datapair.dataset_y, 3)});
    parameters_y.push_back({"K_TH_CENTRAL_MOMENT_(k=4)", GetKthCentralMoment(datapair.dataset_y, 4)});
    parameters_y.push_back({"K_TH_CENTRAL_MOMENT_(k=5)", GetKthCentralMoment(datapair.dataset_y, 5)});
    parameters_y.push_back({"SKEWNESS", GetSkewness(datapair.dataset_y)});
    parameters_y.push_back({"KURTOSIS", GetKurtosis(datapair.dataset_y)});
    parameters_y.push_back({"ENERGY", GetEnergy(datapair.dataset_y)});
    parameters_y.push_back({"POWER", GetPower(datapair.dataset_y)});

    parameters_xy.push_back({"POPULATION_COVARIANCE", GetPopulationCovariance(datapair.dataset_x, datapair.dataset_y)});

    parameters_xy.push_back({"SAMPLE_COVARIANCE", GetSampleCovariance(datapair.dataset_x, datapair.dataset_y)});

    parameters_xy.push_back({"CORRELATION_COEFFICIENT", GetCorrelationCoefficient(datapair.dataset_x, datapair.dataset_y)});

    vector<vector<pair<string, double>>> parameters;
    parameters.push_back(parameters_x);
    parameters.push_back(parameters_y);
    parameters.push_back(parameters_xy);

    return parameters;
}
