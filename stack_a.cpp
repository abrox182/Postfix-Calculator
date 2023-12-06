#include <iostream>
#include <stdexcept>
#include "stack_a.h"
using namespace std;
Stack_A::Stack_A()
{
    size = 0;
}
void Stack_A::push(int data)
{
    if (size < 1024)
    {
        stk[size] = data;
        size++;
    }
    else
    {
        throw std::runtime_error("Stack Full");
    }

}

int Stack_A::pop()
{
    if (size > 0)
    {
        size--;
        return stk[size]; 
    }
    else
    {
        throw std::runtime_error("Empty Stack");
    }
}

int Stack_A::get_element_from_top(int idx)
{
    if(idx >= 0 && idx <= size)
    {
        return stk[size-idx-1];
    }
    else
    {
        throw std::runtime_error("Index out of range");
    }
}

int Stack_A::get_element_from_bottom(int idx)
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

void Stack_A:: print_stack(bool top_or_bottom)
{
    if (top_or_bottom == true)
    {
        for (int i = 0; i < size; i++)
        {
            cout<<stk[size-i-1]<<endl;
        }
    }
    else
    {
        for (int j = 0; j < size; j++)
        {
            cout<<stk[j]<<endl;
        }
    }
}

int Stack_A:: add()
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
int Stack_A:: subtract()
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

int Stack_A:: multiply()
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
int Stack_A:: divide()
{
    if (size > 1)
    {
        if (stk[size-1] != 0)
        {
            int numero;
            numero = stk[size-2]/stk[size-1];
            if (numero == 0)
            {
                if ((stk[size-2]>=0 && stk[size-1]<0)||(stk[size-2] <= 0 && stk[size-1] > 0))
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

int* Stack_A:: get_stack() 
{
    int *ptr;
    ptr = &stk[0];
    return ptr;
}
int Stack_A:: get_size() 
{
    return size;
}
