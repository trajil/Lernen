#include <iostream>
#include <cstdlib>

/*
    - write an array with 10 elements, initialize the values;
    - declare a pointer to the array;
    - write the function reverseArray:
        > taking 2 arguments: pointer to array and size of the array
        > function needs to reverse the elements of the array in place WITHOUT creating a new array
    - main() function calls the reverseArray function, but actually prints the array before and after reversing it;

          hint:
          Using Pointer Arithmetic:

          -In your reverseArray function, use pointer arithmetic to access and swap elements.
          -You can use two pointers: one starting at the beginning of the array and the other at the end. Swap the elements these pointers refer to, and then increment and decrement these pointers, respectively, until they meet or cross.

*/
int const size = 14;
int array[size];

int *pArray = &array[0];

int reverseArray(int size)
{
    int *pUp = &array[0];
    int *pDown = &array[size - 1];

    std::cout << "\nResorting... \n\n";

    for (int i = 0; i < size/2; i++)
    {
        int help = *pUp;
        *pUp = *pDown;
        *pDown = help;
        pDown--;
        pUp++;
    }

    return 0;
}

int main()
{
    // filling the array
    for (int i = 0; i < size; i++)
    {
        array[i] = std::rand() % 99;
    }

    // printing out the Array before function
    std::cout << "Array in input order: \n";
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". : ";
        std::cout << pArray << " : ";
        std::cout << *pArray << "\n";
        pArray++;
    }
    pArray = array;

    reverseArray(size);

    pArray = array;
    // printing out the Array after function
    std::cout << "Array in output order: \n";
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << ". : ";
        std::cout << pArray << " : ";
        std::cout << *pArray << "\n";
        pArray++;
    }
    pArray = array;

    return 0;
}