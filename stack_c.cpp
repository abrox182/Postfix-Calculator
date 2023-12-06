#include <iostream>
#include <stdexcept>
#include "stack_c.h"
using namespace std;

Stack_C::Stack_C()
{
    try
    {
        stk = new List();
    }
    catch(...)
    {
        throw runtime_error("Out of Memory");
    }
    
    stk = new List();
}

Stack_C::~Stack_C()
{
    delete stk;
}

void Stack_C::push(int data)
{
    stk->insert(data);
}

int Stack_C::pop()
{
    int size = stk->get_size();
    if (size > 0)
    {
        return stk->delete_tail();
    }
    else
    {
        throw std::runtime_error("Empty Stack");
    }
}

int Stack_C:: get_element_from_top(int idx)
{
    int size;
    size = Stack_C:: stk->get_size();
    Node *temp;
    temp = stk->get_head();
    if (idx >= size)
    {
        throw std::runtime_error("Index out of range");
    }
    else
    {
        for( int count = 1; count <= size-idx; count++)
        {
            temp = temp->next;
        }
        return temp -> get_value();
    }
}

int Stack_C:: get_element_from_bottom(int idx)
{
    //int counter = 1;
    int size;
    size = Stack_C:: stk->get_size();
    Node *temp;
    temp = stk->get_head();
    if(idx >= size)
    {
        throw std::runtime_error("Index out of range");
    }
    else
    {
        while (idx != 0)
        {
            temp = temp->next;
            idx--;
        }
        return (temp->next)->get_value();
    }
}

void Stack_C::print_stack(bool top_or_bottom)
{
    int counter;
    counter = 0;
    int size;
    size = stk->get_size();
    Node *temp;
    temp = stk->get_head();
    if (top_or_bottom == true)
    {
        while (counter < size)
        {
            temp = temp->next;
            counter++;
        }
        while (counter > 0)
        {
            cout << temp->get_value() << endl;
            temp = temp->prev;
            counter--;
        }
    }
    else if (top_or_bottom == false)
    {
        while (counter < size)
        {
            cout << temp->get_value() << endl;
            temp = temp->next;
            counter++;
        }
    }
}
int Stack_C::add()
{
    int size = stk->get_size();
    if (size > 1)
    {
        int data1 = stk->delete_tail();
        int data2 = stk->delete_tail();
        stk->insert(data1 + data2);
        return data1 + data2;
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_C::subtract()
{
    int size = stk->get_size();
    if (size > 1)
    {
        int data1 = stk->delete_tail();
        int data2 = stk->delete_tail();
        stk->insert(data2 - data1);
        return data2 - data1;
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_C::multiply()
{
    int size = stk->get_size();
    if (size > 1)
    {
        int data1 = stk->delete_tail();
        int data2 = stk->delete_tail();
        stk->insert(data1 * data2);
        return data1 * data2;
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_C::divide()
{
    int size = stk->get_size();
    int data1 = stk->delete_tail();
    int data2 = stk->delete_tail();
    if (size > 1)
    {
        if (data1 != 0)
        {
            int numero;
            numero = data2 / data1;
            if (numero == 0)
            {
                if ((data2 >= 0 && data1 < 0) || (data2 <= 0 && data1 > 0))
                {
                    numero = numero - 1;
                    stk->insert(numero);
                    return numero;
                }
                else if ((data2 >= 0 && data1 > 0) || (data2 < 0 && data1 < 0))
                {
                    stk->insert(numero);
                    return numero;
                }
            }
            else if (numero > 0)
            {
                stk->insert(numero);
                return numero;
            }
            else
            {
                numero = numero - 1;
                stk->insert(numero);
                return numero;
            }
        }

        else if (data1 == 0)
        {
            throw std::runtime_error("Divide by Zero Error");
        }
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}


List *Stack_C::get_stack() 
{
    return stk;
}

int Stack_C::get_size() 
{
    return stk->get_size();
}