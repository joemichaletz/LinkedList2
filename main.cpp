#include "LinkedList.hpp"
#include <iostream>
#include <ctime>

int main()
{
    //std::srand(std::time(nullptr)); // use current time as seed for random generator
    LinkedList* ll = new LinkedList();
    
    //for(int i = 0; i < 20; i++)
    //{
    //    ll->addEnd(std::rand() % 1000);
    //}
    ll->addFront(1);
    ll->addFront(2);
    ll->addFront(3);
    ll->addFront(4);
    ll->addFront(5);
    ll->display();
    ll->sort();
    std::cout << "*******************************************\n";
    ll->display(); //it should now be sorted
}

