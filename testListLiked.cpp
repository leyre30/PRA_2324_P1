#include <iostream>
#include "ListLinked.h"

int main() {
    std::cout << std::boolalpha;

    ListLinked<int> list;

    std::cout << "size(): " << list.size() << std::endl;
    std::cout << "empty(): " << list.empty() << std::endl;
    std::cout << std::endl;

    list.insert(0, 0);
    list.insert(1, 10);
    list.insert(0, -5);
    list.insert(2, 5);

    std::cout << "Contenido de la lista: ";
    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << std::endl;

    std::cout << "size(): " << list.size() << std::endl;
    std::cout << "empty(): " << list.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "l.get(0) => " << list.get(0) << std::endl;
    std::cout << "l.get(3) => " << list.get(3) << std::endl;
    std::cout << std::endl;

    int r;
    r = list.remove(3);
    std::cout << "l.remove(3) => " << r << std::endl;
    r = list.remove(1);
    std::cout << "l.remove(1) => " << r << std::endl;
    r = list.remove(0);
    std::cout << "l.remove(0) => " << r << std::endl;
    std::cout << std::endl;

    std::cout << "Contenido de la lista: ";
    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << std::endl;

    list.append(14);
    list.prepend(33);

    std::cout << "Contenido de la lista: ";
    for (int i = 0; i < list.size(); i++)
        std::cout << list.get(i) << " ";
    std::cout << std::endl;

    std::cout << "l.search(14) => " << list.search(14) << std::endl;
    std::cout << "l.search(55) => " << list.search(55) << std::endl;

    return 0;
}

