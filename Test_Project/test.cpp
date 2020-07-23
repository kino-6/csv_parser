#include "pch.h"
#include "csv_parser.h"
#include <iostream>
#include <Windows.h>

namespace csv_parser_test {
    class MyLibraryTest : public ::testing::Test {
    protected:
        std::string filepath = "test.csv";
        CsvParser<long double> ld_cp;
        CsvParser<double> d_cp;
        CsvParser<long long int> li_cp;
        CsvParser<int> i_cp;
        CsvParser<unsigned int> ui_cp;
        CsvParser<unsigned long long int> uli_cp;

        virtual void SetUp() {
            //std::string currentDir;
            //currentDir.resize(256);
            //LPWSTR lpwstr = new wchar_t[currentDir.size() + 1];
            //(void)GetCurrentDirectory(sizeof(currentDir), lpwstr);

            ld_cp.ReadCsv(filepath, ',', 0, 0, "#");
            d_cp.ReadCsv(filepath, ',', 0, 0, "#");
            li_cp.ReadCsv(filepath, ',', 0, 0, "#");
            i_cp.ReadCsv(filepath, ',', 0, 0, "#");
            ui_cp.ReadCsv(filepath, ',', 0, 0, "#");
            uli_cp.ReadCsv(filepath, ',', 0, 0, "#");

        }
    };

    TEST_F(MyLibraryTest, ReadZero_LongDouble) {
        EXPECT_EQ(ld_cp.GetData(4, 0), 0);
        EXPECT_EQ(ld_cp.GetData(4, 1), 0);
        EXPECT_EQ(ld_cp.GetData(4, 2), 0);
    }

    TEST_F(MyLibraryTest, ReadZero_Double) {
        EXPECT_EQ(d_cp.GetData(4, 0), 0);
        EXPECT_EQ(d_cp.GetData(4, 1), 0);
        EXPECT_EQ(d_cp.GetData(4, 2), 0);
    }

    TEST_F(MyLibraryTest, ReadZero_LongInt) {
        EXPECT_EQ(li_cp.GetData(4, 0), 0);
        EXPECT_EQ(li_cp.GetData(4, 1), 0);
        EXPECT_EQ(li_cp.GetData(4, 2), 0);
    }

    TEST_F(MyLibraryTest, ReadZero_Int) {
        EXPECT_EQ(i_cp.GetData(4, 0), 0);
        EXPECT_EQ(i_cp.GetData(4, 1), 0);
        EXPECT_EQ(i_cp.GetData(4, 2), 0);
    }

    TEST_F(MyLibraryTest, ReadValue_u32_to_double) {

        //double ld = ld_cp.GetData(5, 3);
        //double ud = (double)0x80000001;

        EXPECT_NEAR(ld_cp.GetData(5, 1), (double)0xFFFFFFFF, 2705);
        EXPECT_NEAR(ld_cp.GetData(5, 2), (double)0x7FFFFFFF, 3647);
        EXPECT_NEAR(ld_cp.GetData(5, 3), (double)0x80000000, 3648);
        EXPECT_NEAR(ld_cp.GetData(5, 4), (double)0x80000001, 3649);
    }

    TEST_F(MyLibraryTest, ReadValue_u32_to_i32) {
        EXPECT_EQ(i_cp.GetData(5, 1), INT_MAX);
        EXPECT_EQ(i_cp.GetData(5, 2), INT_MAX);
        EXPECT_EQ(i_cp.GetData(5, 3), INT_MAX);
        EXPECT_EQ(i_cp.GetData(5, 4), INT_MAX);
    }

    TEST_F(MyLibraryTest, ReadValue_u32) {
        EXPECT_EQ(ui_cp.GetData(5, 1), 0xFFFFFFFF);
        EXPECT_EQ(ui_cp.GetData(5, 2), 0x7FFFFFFF);
        EXPECT_EQ(ui_cp.GetData(5, 3), 0x80000000);
        EXPECT_EQ(ui_cp.GetData(5, 4), 0x80000001);
    }

    TEST_F(MyLibraryTest, ReadValue_i64) {
        EXPECT_EQ(li_cp.GetData(6, 1), LLONG_MAX);
        EXPECT_EQ(li_cp.GetData(6, 2), LLONG_MAX);
        EXPECT_EQ(li_cp.GetData(6, 3), LLONG_MAX);
        EXPECT_EQ(li_cp.GetData(6, 4), LLONG_MAX);
    }

    TEST_F(MyLibraryTest, ReadValue_u64) {
        EXPECT_EQ(uli_cp.GetData(6, 1), 0xFFFFFFFFFFFFFFFF);
        EXPECT_EQ(uli_cp.GetData(6, 2), 0x7FFFFFFFFFFFFFFF);
        EXPECT_EQ(uli_cp.GetData(6, 3), 0x8000000000000000);
        EXPECT_EQ(uli_cp.GetData(6, 4), 0x8000000000000001);
    }


    TEST_F(MyLibraryTest, ReadOutOfRange) {
        EXPECT_EQ(ld_cp.GetData(4, 5, 1234), 1234);
    }

}