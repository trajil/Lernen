#include<iostream>

/*
    - write an array with 10 elements, initialize the values;
    - declare a pointer to the array;
    - write the function reverseArray:
        > taking 2 arguments: pointer to array and size of the array
        > function needs to reverse the elemts of the array in place WITHOUT creating a new array
    - main() function calls the reverseArray function, but actually prints the array before and after reversing it;

*/
int size = 10;
int vector() = { 22, 100, 30, 17, 99, 12, 1, 14, 50, 710};
int array[10] = { 22, 100, 30, 17, 99, 12, 1, 14, 50, 710};
int *pArray = &array[0];

int reverseArray()
{
    return 0;
}

int main()
{
    // printing out the array in right order
    std::cout << "Array in right order: \n";
    for (int element : array )
    {
        std::cout << element << "\n";
    }



    return 0;
}