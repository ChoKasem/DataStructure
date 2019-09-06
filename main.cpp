#include <iostream>
#include "BinarySearchTree.h"
#include "Vector.h"
#include "List.h"

using namespace std;


int main()
{
    Vector<int> vect;
    vect.push_back(3);
    cout << vect.capacity() << endl;
    vect.push_back(5);
    cout << vect.capacity() << endl;
    vect.push_back(4);
    cout << vect.capacity() << endl;

    return 0;
}
