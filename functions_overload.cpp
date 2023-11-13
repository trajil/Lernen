#include<iostream>

//overloading functions: re-using function names but with different type parameters;


void trennen(int stellen_h,int stellen_v)
{
    for (int i=0;i<stellen_v;i++)
    {
        for (int i=0;i<stellen_h;i++)
        {
        std::cout << "+";
        }
    std::cout << std::endl;
    }
    //std::cout << std::endl;
    
}

void trennen(std::string f)
{
    std::cout << "Schöner Kasten drumherum..." << f << std::endl;
    
}

int main()
{
    int breite = 20, höhe = 2;
    
    trennen(breite,höhe);
    trennen("nicht wahr?");
    trennen(breite,höhe);
    //std::cout << "Hier könnte Ihre Werbung stehen!\n";
    //trennen(breite,höhe);




    return 0;
}