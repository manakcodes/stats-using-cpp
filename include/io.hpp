#include "utility.hpp"
#pragma once

// ========================================================================== //
// FUNCTION -> to print a welcome message and a project guide for the user
// ========================================================================== //
void PrintWelcomeMessage()
{
    cout << FG_YELLOW << STYLE_BOLD;
    cout << "+----------------------------------------------------------+\n";
    cout << "|                   WELCOME TO DATA ANALYZER               |\n";
    cout << "+----------------------------------------------------------+\n";
    cout << STYLE_RESET;

    cout << FG_CYAN;
    cout << "This program allows you to:\n";
    cout << "  - Enter two datasets X[i..n] and Y[i..n]\n";
    cout << "  - Compute statistical parameters on individual datasets\n";
    cout << "  - Compute statistical parameters on combined datasets\n";
    cout << "  - Display datasets and results in a nicely formatted table\n";
    cout << STYLE_RESET;

    cout << FG_GREEN;
    cout << "Instructions:\n";
    cout << "  - Enter the size of your dataset\n";
    cout << "  - Enter values for dataset X[i..n] and Y[i..n]\n";
    cout << "  - View the dataset tables\n";
    cout << "  - View the analysis tables\n";
    cout << STYLE_RESET;

    cout << FG_YELLOW << STYLE_BOLD;
    cout << "+----------------------------------------------------------+\n\n";
    cout << STYLE_RESET;

    cout << FG_RED << STYLE_BOLD << "this project computes parameters till 4 decimal places (1E-4)" << STYLE_RESET << endl;

    cout << endl
         << endl;
}

// ========================================================================== //
// FUNCTION -> inputs the sizeof the dataset from the user and asks the user to
// enter the dataset
// ========================================================================== //
struct DataPair InputDataSet()
{
    size_t size = 0;

    cout << STYLE_BOLD << FG_GREEN << "enter the size of the dataset : " << STYLE_RESET;
    cin >> size;

    vector<double> dataset_x(size);
    vector<double> dataset_y(size);

    cout << endl;

    cout << STYLE_BOLD << FG_GREEN << "enter dataset x below : " << STYLE_RESET << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << STYLE_BOLD << FG_RED << "enter x[" << i + 1 << "] : " << STYLE_RESET;
        cin >> dataset_x[i];
    }

    cout << endl;

    cout << STYLE_BOLD << FG_GREEN << "enter dataset y below : " << STYLE_RESET << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << STYLE_BOLD << FG_RED << "enter y[" << i + 1 << "] : " << STYLE_RESET;
        cin >> dataset_y[i];
    }

    DataPair datapair(dataset_x, dataset_y);

    cout << endl;

    return datapair;
}

// ========================================================================== //
// FUNCTION -> print the dataset X[i..n] and Y[i..n] in a tabular manner with
// fixed character width
// ========================================================================== //
void PrintDataSet(const struct DataPair &datapair)
{
    const auto &x = datapair.dataset_x;
    const auto &y = datapair.dataset_y;
    size_t n = x.size();

    // Table header with red bold
    cout << FG_RED << STYLE_BOLD;
    cout << "+-------+-----------------+-----------------+\n";
    cout << "| S.No  | X[i]            | Y[i]            |\n";
    cout << "+-------+-----------------+-----------------+\n";
    cout << STYLE_RESET;

    for (size_t i = 0; i < n; ++i)
    {
        cout << STYLE_BOLD;
        cout << FG_RED << STYLE_BOLD << "| " << setw(5) << left << i + 1 << " |" << STYLE_RESET;
        cout << FG_BLUE << STYLE_BOLD << " " << setw(15) << left << fixed << setprecision(4) << x[i] << STYLE_RESET;
        cout << FG_RED << STYLE_BOLD << " |" << STYLE_RESET;
        cout << FG_BLUE << STYLE_BOLD << " " << setw(15) << left << fixed << setprecision(4) << y[i] << STYLE_RESET;
        cout << FG_RED << STYLE_BOLD << " |\n"
             << STYLE_RESET;
    }

    cout << FG_RED << STYLE_BOLD << "+-------+-----------------+-----------------+\n"
         << STYLE_RESET;

    cout << endl
         << endl;
}

// ========================================================================== //
// FUNCTION -> print the statistical parameters of dataset X[1..n], Y[1..n] and
// XY[1..n]
// ========================================================================== //
void PrintDataSetParameters(const struct DataPair &datapair)
{
    // Get parameters as vector<pair> to preserve insertion order
    vector<vector<pair<string, double>>> parameters = GetDataParameters(datapair);

    auto PrintTable = [](const vector<pair<string, double>> &param, const string &title)
    {
        cout << FG_CYAN;
        cout << "+-----------------------------------------------+------------------------------+\n";
        cout << "| " << setw(45) << left << title
             << " | " << setw(28) << right << "Value" << " |\n";
        cout << "+-----------------------------------------------+------------------------------+\n";

        for (const auto &pair : param)
        {
            cout << "| " << setw(45) << left << pair.first << " | ";

            if (pair.first == "IS_SORTED")
            {
                cout << setw(28) << right << (pair.second != 0.0 ? "true" : "false") << " |\n";
            }
            else
            {
                cout << setw(28) << right << fixed << setprecision(4) << pair.second << " |\n";
            }
        }

        cout << "+-----------------------------------------------+------------------------------+\n";
        cout << STYLE_RESET;
    };

    PrintTable(parameters[0], "PARAMETERS OF DATASET X");

    cout << endl
         << endl;

    PrintTable(parameters[1], "PARAMETERS OF DATASET Y");

    cout << endl
         << endl;

    PrintTable(parameters[2], "PARAMETERS OF DATASET XY");

    cout << endl
         << endl;
}
