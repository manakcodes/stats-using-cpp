#include "utility.hpp"
#include "compute.hpp"
#include "io.hpp"

#pragma once

// ========================================================================== //
// master method to run the project
// ========================================================================== //
void master()
{
    PrintWelcomeMessage();
    DataPair datapair = InputDataSet();

    PrintDataSet(datapair);

    PrintDataSetParameters(datapair);

    cout << FG_RED << STYLE_BOLD;
    cout << STYLE_BOLD << "dataset x  size : " << datapair.size << endl;
    cout << STYLE_BOLD << "dataset y  size : " << datapair.size << endl;
    cout << STYLE_BOLD << "dataset xy size : " << 2 * datapair.size << endl;

    cout << endl;

    cout << "memory used by dataset  x (in bytes) : " << datapair.size * sizeof(double) << " bytes" << endl;
    cout << "memory used by dataset  y (in bytes) : " << datapair.size * sizeof(double) << " bytes" << endl;
    cout << "memory used by dataset xy (in bytes) : " << 2 * datapair.size * sizeof(double) << " bytes" << endl;

    cout << endl;

    cout << STYLE_RESET;
}