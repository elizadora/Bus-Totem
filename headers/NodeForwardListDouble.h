#ifndef NODEFORWARDLISTDOUBLE_H
#define NODEFORWARDLISTDOUBLE_H

#include <iostream>

// lista duplamente encadeada circular
class NodeForwardDouble {
    friend class ForwardListDouble;
private:
    // nome da parada
    std::string stopName;

    // horario de chegada
    std::string arrivalTime;

    // horario de saida
    std::string departureTime;

    // no anterior
    NodeForwardDouble *previous;

    // proximo no
    NodeForwardDouble *next;

public:
    NodeForwardDouble(std::string stopName, std::string arrivalTime, std::string departureTime, NodeForwardDouble *previous, NodeForwardDouble *next){
        this->stopName = stopName;
        this->arrivalTime = arrivalTime;
        this->departureTime = departureTime;
        this->previous = previous;
        this->next = next;
    }

};

#endif