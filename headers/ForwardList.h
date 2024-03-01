#ifndef FORWARLIST_H
#define FORWARLIST_H
#include "NodeFowardList.h"

class ForwardList{
private:
    NodeForwardList *head;
    unsigned size;

public:
    ForwardList();

    // funções auxiliares
    void remove(int numberLine);
    void insert(int numberLine, std::string company, std::string destination, std::string origin);
    void insertP(int numberLine, std::string stopName, std::string arrivalTime, std::string departureTime, char type);
    void removeP(int numberLine, int position);
    void search(std::string destination, std::string arrivalTime);
    void edit(int numberLine);
    void print();
    bool empty();
};

#endif