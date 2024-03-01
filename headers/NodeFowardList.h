#ifndef NODEFORWARDLIST_H
#define NODEFORWARDLIST_H

#include <iostream>
#include "ForwardListDouble.h"

class NodeForwardList{
    friend class ForwardList;

private:
    // atributos
    int numberLine; // numero da linha
    std::string company; // nome da empresa
    std::string destination; // destino
    std::string origin; // origem
    NodeForwardList *next; // proximo no
    ForwardListDouble *line; // linha seguida pelo onibus

public:
    NodeForwardList(int numberLine, std::string company, std::string destination, std::string origin, NodeForwardList *next){
        this->numberLine = numberLine;
        this->company = company;
        this->destination = destination;
        this->origin = origin;
        this->next = next;
        this->line = new ForwardListDouble();
    }
    
};

#endif