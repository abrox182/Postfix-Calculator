#include <iostream>
#include <stdexcept>
#include "stack_b.h"
using namespace std;


     // Constructor
Stack_B:: Stack_B()
{
    capacity = 1024;
    size = 0;
    try
    {
        stk = new int[capacity];
    }
    catch(...)
    {
        throw runtime_error("Out of Memory");
    }
    
}
    // Destructor
Stack_B:: ~Stack_B()
{
    delete[] stk;
}

void Stack_B:: push(int data)
{
    if (capacity > size)
    {
        stk[size] = data;
        size++;

    }
    else if (size == capacity)
    {
        capacity = capacity*2;
        int *stkk = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            stkk[i] = stk[i];
        }
        delete stk;
        stk = stkk;
        stkk[size] = data;
        size++;
    }
}

int Stack_B:: pop()
{
    if (size > 0)  
    {
        size--;
        return stk[size];    
    }
    else if (size == capacity/2)
    {
        capacity = capacity/2;
        int *stkk = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            stkk[i] = stk[i];
        }
        delete stk;
        stk = stkk;
        size--;
        return stk[size];
    }
    else
    {
        throw std::runtime_error("Empty Stack");
    }
}

int Stack_B:: get_element_from_top(int idx)
{
    if (idx >= 0 && idx < size)
    {
        return stk[size-idx-1];
    }
    else
    {
        throw std::runtime_error("Empty Stack");
    }
}

int Stack_B:: get_element_from_bottom(int idx)
{
    if(idx >= 0 && idx <= size)
    {
        return stk[idx];
    }
    else
    {
        throw std::runtime_error("Index out of range");
    }
}

void Stack_B:: print_stack(bool top_or_bottom)
{
    if(top_or_bottom == true)
    {
        for (int i = 0; i < size; i++)
        {
            cout<<stk[size-i-1]<<endl;;
        }
    }
    else if(top_or_bottom == false)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<stk[j]<<endl;
        }
    }
}

int Stack_B:: add()
{
    if (size > 1)
    {
        stk[size-2] = stk[size-2] + stk[size-1];
        size--;
        return stk[size-1];
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}
int Stack_B:: subtract()
{
    if (size > 1)
    {
        stk[size-2] = stk[size-2] - stk[size-1];
        size--;
        return stk[size-1];
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_B:: multiply()
{
    if (size > 1)
    {
        stk[size-2] = (stk[size-2])*(stk[size-1]);
        size--;
        return stk[size-1];
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}
    
int Stack_B:: divide()
{
    if (size > 1 || size != 0)
    {
        if (stk[size-1] != 0)
        {
            int numero;
            numero = stk[size-2]/stk[size-1];
            if (numero == 0)
            {
                if ((stk[size-2]>=0 && stk[size-1]<0)||(stk[size-1] <= 0 && stk[size-1] > 0))
                {
                    stk[size-2] = numero - 1;
                    size--;
                    return stk[size-1];
                }
                else if((stk[size-2] >= 0 && stk[size-1] > 0)||(stk[size-2] < 0 && stk[size-1] < 0))
                {
                    stk[size-2] = numero;
                    size--;
                    return stk[size-1];
                }
            }
            else if (numero > 0)
            {
                stk[size-2] = numero;
                size--;
                return stk[size-1];
            }
            else
            {
                stk[size-2] = numero-1;
                size--;
                return stk[size-1];
            }
        }

        else if(stk[size-1] == 0)
        {
            throw std::runtime_error("Divide by Zero Error");
        }
    }
    else
    {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int* Stack_B:: get_stack() 
{
    int *ptr;
    ptr = &stk[0];
    return ptr;
}

int Stack_B:: get_size() 
{
    return size ;
}
