# csv_parser
csv parser @ c++

## Description

This is csv parser @ c++


test.csv
```csv
# test comment
time, label1, label2, label3, lable4
# comment2
0,1,2,3, 0x123456789ABCDEF0
1.1,2.,4,9, 0xFF
2.2,3,8,27,0x10
```

(1) csv_parser << test.csv
```cpp
// generate instance
CsvParser<long double> cp;

// filepath , delimiter, start_row, start_col, comment
cp.ReadCsv("test.csv", ',', 0, 0, "#");
```

(2) call GetData(x, y)
<pre>
csv_parser.GetData(x,y) =
	time	label1	label2	label3	lable4
	0	1	2	3	1.31177e+18
	1.1     2	4	9	255
	2.2     3	8	27	16
<pre>
