#include <iostream>
#include <stdexcept>
#include "list.h"
#include "node.h"
using namespace std;
/* PART B */
/* Stacks using Linked Lists */

/* 
Linked Lists with Sentinels 
[X]<->[7]<->[3]<->[2]<->[X]
The head and tails are dummy elements ([X]) that do not have valid values.
These are called sentinel elements.
*/


// public: 
List:: List()
{
    sentinel_head = new Node(true);
    sentinel_tail = new Node(true);
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
    size = 0;
}

List:: ~List()
{
    Node *cur = sentinel_head -> next;
    while (cur != sentinel_tail)
    {
        Node *temp = cur;
        cur = cur -> next;
        delete temp;
    }
    delete sentinel_head;
    delete sentinel_tail;
}

    // Insert an element at the tail of the linked list 
void  List:: insert(int v)
{
    Node* temp = new Node(v, sentinel_tail, sentinel_tail->prev);
    temp->next->prev = temp;
    temp->prev->next = temp;  
    size++;
        // newNode -> next = sentinel_tail;
        // newNode -> previous = sentinel_head;
}

    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
    int List:: delete_tail()
{
    Node *temp = sentinel_tail -> prev;
    int ans = temp->get_value();
    temp -> prev -> next = temp->next;
    sentinel_tail -> prev = temp -> prev;
    delete temp;
    size --;
    return ans;        
}
    // Return the size of the linked list 
    // Do not count the sentinel elements
int List:: get_size()
{
    return size;
} 

    // Return a pointer to the sentinel head of the linked list 
Node* List:: get_head()
{
    return sentinel_head;
}
