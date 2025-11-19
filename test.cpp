#include "include/statscpp.hpp"

void TestCaseOne();
void TestCaseTwo();
void TestCaseThree();

int main()
{
    TestCaseOne();
    TestCaseTwo();
    TestCaseThree();
    return 0;
}

void TestCaseOne()
{
    cout << "TEST CASE -> 1" << endl
         << endl;
    vector<double> dataset_x = {1, 2, 3, 4, 5};
    vector<double> dataset_y = {10, 20, 30, 40, 50};

    DataPair datapair(dataset_x, dataset_y);

    PrintDataSet(datapair);
    PrintDataSetParameters(datapair);

    cout << endl
         << endl;
}

void TestCaseTwo()
{
    cout << "TEST CASE -> 2" << endl
         << endl;
    vector<double> dataset_x = {1, 2, 3, 4, 5};
    vector<double> dataset_y = {50, 40, 30, 20, 10};

    DataPair datapair(dataset_x, dataset_y);

    PrintDataSet(datapair);
    PrintDataSetParameters(datapair);

    cout << endl
         << endl;
}

void TestCaseThree()
{
    cout << "TEST CASE -> 3" << endl
         << endl;
    vector<double> dataset_x = {1, 2, 3, 4, 5};
    vector<double> dataset_y = {10, 20, 25, 25, 88};

    DataPair datapair(dataset_x, dataset_y);

    PrintDataSet(datapair);
    PrintDataSetParameters(datapair);

    cout << endl
         << endl;
}
