#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    List<int> list1;
    list1.push_back(3);
    list1.push_back(5);
    list1.push_back(9);
    cout << list1.size() << endl;

    return 0;
}
