#include <iostream>
#include <stdexcept>
#include "node.h"
using namespace std;
/* PART B */
/* Stacks using Linked Lists */

    // Use to construct a sentinel node (see list.h)
Node:: Node(bool sentinel)   
{
    next = NULL;
    prev = NULL;
    is_sentinel = sentinel;
}
// Use to construct a regular node
Node:: Node(int v, Node* nxt, Node* prv)
{
    value = v;
    next = nxt;
    prev = prv;
    is_sentinel=false;
}
    // Return whether a node is a sentinel node 
    // Use it to check if we are at the ends of a list
bool Node:: is_sentinel_node()
{
    return is_sentinel;
}
    // Return the value of a node
int Node:: get_value()
{
    return value;
}
