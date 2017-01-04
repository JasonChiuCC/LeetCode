6. ZigZag Conversion
=========
```
Total Accepted      : 128738
Total Submissions   : 497747
Difficulty          : Easy
Contributors        : Admin

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

注意:
主要想法其實就是傳入參數為幾列就先建立幾個陣列
例如傳入 3 就建立 3 個陣列,每一個陣列儲存字串陣列

Array[0][]
Array[1][]
Array[2][]

然後就依序將字串放入陣列中,使用 append 插入字元到陣列最後面
例如傳入 ABCDEFG 3
(1)
Array[0][A]
Array[1][]
Array[2][]

(2)
Array[0][A]
Array[1][B]
Array[2][]

(3)
Array[0][A]
Array[1][B]
Array[2][C]

(4)
Array[0][A]
Array[1][B,D]
Array[2][C]
....

(n)
Array[0][A,E]
Array[1][B,D,F,G]
Array[2][C,G]

順序可以用公式表達出來
如果傳入 "ABCDEFGH",3 就會計算如下[ L - abs(L - idx % (2*L)) ] = 填入哪一個陣列的意思
2 - abs(2 - 0%4 ) = 0   // 填入第 1 個陣列
2 - abs(2 - 1%4 ) = 1   // 填入第 2 個陣列
2 - abs(2 - 2%4 ) = 2   // 填入第 3 個陣列
2 - abs(2 - 3%4 ) = 1   // 填入第 2 個陣列
2 - abs(2 - 4%4 ) = 0   .......
2 - abs(2 - 5%4 ) = 1
2 - abs(2 - 6%4 ) = 2
2 - abs(2 - 7%4 ) = 1
```
