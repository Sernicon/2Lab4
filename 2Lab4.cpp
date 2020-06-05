#include "Heap.h"
int main()
{
    Heap<int> A(1);
    A.print();
    A.insert(1);
    A.insert(7);
    A.insert(10);
    A.insert(3);
    A.insert(2);
    A.insert(4);
    A.insert(6);
    A.print();
    if (A.isContains(2))
        cout << "A contains 2\n" << endl;;
    if (!A.isContains(5))
        cout << "A not contains 5\n" << endl;
    Heap<int> B = A;
    B.del(1);
    B.print();
    A.clear();
    if (A.isEmpty())
        cout << "A is empty\n" << endl;
    Heap<float> C(1);
    C.insert(2.6);
    C.print();
}
