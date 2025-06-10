Interquartile Range (Linked List)
Author: Amanpreet Kapoor
Difficulty: Hard

Problem Statement
Quartiles divide a sorted dataset into four equal parts. The interquartile range (IQR) is the difference between the third and first quartiles:

IQR = Q3 - Q1

This problem requires calculating the IQR from a sorted singly linked list using a single traversal (no multiple passes or use of STL containers).

Definitions
Q1 (lower quartile): median of the lower half of the data (excluding the overall median if list size is odd)

Q2 (median): middle element (if odd) or average of two middle elements (if even)

Q3 (upper quartile): median of the upper half of the data (excluding the overall median if list size is odd)

IQR: Q3 - Q1, rounded to 2 decimal places

Sample Input
2 4 4 5 6 7 8

Sample Output
3.00

Explanation
Input: a sorted linked list with values 2 → 4 → 4 → 5 → 6 → 7 → 8

Median (Q2): 5

Lower half (before median): 2, 4, 4 → Q1 = 4

Upper half (after median): 6, 7, 8 → Q3 = 7

IQR = 7 - 4 = 3.00

Constraints
The linked list is sorted

The list has at least 4 elements

You must not use STL containers like vector, list, or arrays

You must not iterate over the list more than once

Only one loop is allowed (violating this incurs a 20% penalty)

Technical Details
You are provided with the following class:

class Node {
  public:
    int value;
    Node* next = nullptr;
};

You are expected to implement a function:

double interQuartile(Node* head);

Return a floating-point value

Round the result to two decimal places using setprecision() in main()

Notes
Use the slow and fast pointer technique to identify the median and split points in a single pass

Do not use temporary storage or backtracking

You can use this calculator to verify results:
https://www.calculatorsoup.com/calculators/statistics/quartile-calculator.php

License
This project is open source under the MIT License.

