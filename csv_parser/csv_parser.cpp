#include <iostream>
#include "csv_parser.h"

int main()
{
    CsvParser<long double> cp;
    cp.ReadCsv("test.csv", ',', 0, 0, "#");

    for(auto i=0; i<cp.GetSize(0,0); i++){
        for(auto j=0; j<cp.GetSize(0); j++){
            if (i == 0) {
                std::cout << cp.GetLabels(i, j) << "\t" << std::ends;
            }
            else {
                std::cout << cp.GetData(i, j) << "\t" << std::ends;
            }
        }
        std::cout << std::endl;
    }
}