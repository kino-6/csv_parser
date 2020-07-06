// csv_parser.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "csv_parser.h"

int main()
{
    CsvParser<double> cp;
    cp.ReadCsv("test.csv", ',', 0, 0, "#");

    double test  = cp.GetData(1, 4);
    double test2 = cp.GetData(1, 3);

}