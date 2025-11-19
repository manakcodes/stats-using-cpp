// ========================================================================== //
// INCLUDE HEADER FILES
// ========================================================================== //

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#pragma once
using namespace std;

// ========================================================================== //
// MACROS to compare double values
// ========================================================================== //

#define EPSILON 1E-4
#define IS_EQUAL(a, b) (fabs((a) - (b)) <= EPSILON)
#define IS_NOT_EQUAL(a, b) (fabs((a) - (b)) > EPSILON)
#define IS_GREATER(a, b) ((a) - (b) > EPSILON)
#define IS_LESS(a, b) ((b) - (a) > EPSILON)
#define IS_GREATER_EQUAL(a, b) ((a) > (b) - EPSILON)
#define IS_LESS_EQUAL(a, b) ((a) < (b) + EPSILON)
#define IS_ZERO(a) (fabs(a) <= EPSILON)
#define IS_ONE(a) (fabs((a) - 1.0) <= EPSILON)
#define IS_POSITIVE(a) ((a) > EPSILON)
#define IS_NEGATIVE(a) ((a) < -EPSILON)
#define IS_INVALID(a) (isnan(a) || IS_ZERO(a))

// ========================================================================== //
// MACROS to print colored output in terminal
// ========================================================================== //

#define FG_BLACK "\033[30m"
#define FG_RED "\033[31m"
#define FG_GREEN "\033[32m"
#define FG_YELLOW "\033[33m"
#define FG_BLUE "\033[34m"
#define FG_MAGENTA "\033[35m"
#define FG_CYAN "\033[36m"
#define FG_WHITE "\033[37m"
#define FG_BRIGHT_BLACK "\033[90m"
#define FG_BRIGHT_RED "\033[91m"
#define FG_BRIGHT_GREEN "\033[92m"
#define FG_BRIGHT_YELLOW "\033[93m"
#define FG_BRIGHT_BLUE "\033[94m"
#define FG_BRIGHT_MAGENTA "\033[95m"
#define FG_BRIGHT_CYAN "\033[96m"
#define FG_BRIGHT_WHITE "\033[97m"

#define STYLE_RESET "\033[0m"
#define STYLE_BOLD "\033[1m"
#define STYLE_UNDERLINE "\033[4m"

// ========================================================================== //
// struct definition for a DataPair
// ========================================================================== //

struct DataPair
{
    size_t size;
    vector<double> dataset_x;
    vector<double> dataset_y;

    DataPair() {}
    DataPair(size_t);
    DataPair(vector<double>, vector<double>);
};

// ========================================================================== //
// CONSTRUCTOR BODIES
// ========================================================================== //

DataPair::DataPair(size_t size)
{
    this->size = size;
}

DataPair::DataPair(vector<double> dataset_x, vector<double> dataset_y)
{
    if (dataset_x.size() != dataset_y.size())
    {
        exit(-1);
    }

    this->size = dataset_x.size();
    this->dataset_x = dataset_x;
    this->dataset_y = dataset_y;
}

// ========================================================================== //
// FUNCTION PROTOTYPES
// ========================================================================== //

// ========================================================================== //
// file : stats-using-cpp/include/compute.hpp
// ========================================================================== //

bool DataSetIsSorted(const vector<double> &);

double GetSum(const vector<double> &);

double GetMean(const vector<double> &);
double GetMode(const vector<double> &);
double GetMedian(vector<double>);

double GetMax(const vector<double> &);
double GetMin(const vector<double> &);
double GetRange(const vector<double> &);

double GetPopulationVariance(const vector<double> &);
double GetSampleVariance(const vector<double> &);

double GetStandardDeviation(const vector<double> &);

double GetEnergy(const vector<double> &);
double GetPower(const vector<double> &);

double GetKthCentralMoment(vector<double>);
double GetSkewness(const vector<double> &);
double GetKurtosis(const vector<double> &);

double GetPopulationCovariance(const vector<double> &, const vector<double> &);
double GetSampleCovariance(const vector<double> &, const vector<double> &);

double GetCorrelationCoefficient(const vector<double> &, const vector<double> &);
vector<vector<pair<string, double>>> GetDataParameters(const struct DataPair);

// ========================================================================== //
// file : stats-using-cpp/include/io.hpp
// ========================================================================== //

void PrintWelcomeMessage();
struct DataPair InputDataSet();
void PrintDataSet(const struct DataPair &);
void PrintDataSetParameters(const struct DataPair &);
void master();
