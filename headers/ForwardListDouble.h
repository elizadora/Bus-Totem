#ifndef FORWARLISTDOUBLE_H
#define FORWARLISTDOUBLE_H

#include <iostream>
#include "NodeForwardListDouble.h"
#include <ctime>

// lista duplamente encadeada circular
class ForwardListDouble {
private:
    // cabeca da lista
    NodeForwardDouble *head;

    // tamanho da lista
    int size;

public:

    ForwardListDouble();
    // funções auxiliares
    void insert(std::string stopName, std::string arrivalTime, std::string departureTime);
    void insertFile(std::string stopName, std::string arrivalTime, std::string departureTime);
    void remove(int position);
    std::string search(std::string arrivalTime, std::string destination);
    void edit();
    void print();
};

#endif