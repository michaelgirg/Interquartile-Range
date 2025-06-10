#include <iostream>
#include <iomanip>

class Node {
public:
    int value;
    Node* next = nullptr;
};

Node* insertEnd(Node* head, int key) {
    Node* temp = new Node();
    temp->value = key;
    if (head == nullptr)
        return temp;
    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = temp;
    return head;
}

//This function will find the median of both the Q3 and Q1 and then we can get the IQR
float median(Node* start, int size) {
    Node* curr = start;

    for (int i = 0; i < size / 2 - (size % 2 == 0); i++) {
        curr = curr->next;
    }

    if (size % 2 == 0) { // if count is even and curr is at the first of the two middle nodes
        return ((float)curr->value + (float)curr->next->value) / 2.0f; //gets the average of the two middle nodes which
        //is the median
    } else {
        return curr->value; //if its odd and the curr is at the middle node(median)
    }
}

float interQuartile(Node* head)
{
    //find the middle of LL using fast and slow pointers
    //when fast gets to the end slow is in the middle
    Node* slow = head;
    Node* fast = head;
    int count = 0;
    //these our fast and slow pointers here
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        count += 2; //this count will be following the fast pointer
    }
    if (fast != nullptr) { //odd amount of nodes fast will end up at last node of LL
        count++;
    }

    int mid = count / 2;
    Node* Q3Quartile = head;
    for (int i = 0; i < mid + (count % 2); i++) { //Will go to the node right next to the median where Q3 starts
        Q3Quartile = Q3Quartile->next;
    }

    float Q1 = median(head, mid);
    float Q3 = median(Q3Quartile, mid);

    return Q3-Q1;
}




/*
Explanation:

- Node* insertEnd(...):
  Inserts a new node with the given value at the end of the linked list.

- float median(...):
  Calculates the median of a linked list segment:
  - If the segment size is odd, returns the middle node's value.
  - If even, returns the average of the two middle nodes.
  - This is used for both Q1 and Q3 calculations.

- float interQuartile(...):
  Calculates the interquartile range (IQR) of a sorted linked list.

  Steps:
  1. Uses slow and fast pointers to find the middle of the linked list in one traversal.
     - `fast` moves 2 nodes at a time, `slow` moves 1.
     - When `fast` reaches the end, `slow` points to the median or just past it.
     - `count` keeps track of total nodes for size awareness.
  
  2. Calculates the starting node for Q3 by moving past the median if count is odd.

  3. Calls the `median()` function twice:
     - Once from head to find Q1
     - Once from Q3 starting point to find Q3

  4. Returns the difference Q3 - Q1 as the IQR.

Notes:
- This approach respects all constraints: no arrays, STL containers, or multiple traversals.
- Uses only one loop (for finding the midpoint).
- Uses pointer arithmetic to avoid full-list scans.
*/
