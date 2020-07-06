# csv_parser
csv parser @ c++

## Description

csv_parser <- test.csv

test.csv
```csv
# test comment
time, label1, label2, label3, lable4
# test comment2
0,1,2,3, 0xFF
1,2,4,9, 0x09
2,3,8,27,0x3
```
<pre>
csv_parser.GetData(x,y) =
  time, label1, label2, label3, lable4
  0,1,2,3, 0xFF
  1,2,4,9, 0x09
  2,3,8,27,0x3
<pre>
