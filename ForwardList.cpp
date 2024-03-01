#include <iostream>
#include "headers/ForwardList.h"

// construtor
ForwardList::ForwardList(){
    this->head = new NodeForwardList(0, "", "", "", nullptr);
    this->size = 0;
}

/// retorna se a lista esta vazia ou não
bool ForwardList::empty(){
    if(head->next == nullptr){
        return true;
    }else{
        return false;
    }
}

// imprime a lista
void ForwardList::print(){
    std::cout << "Lista de onibus: " << std::endl;
    if(head->next == nullptr){
        std::cout << "Lista vazia" << std::endl;
    }else{
        NodeForwardList *aux = head->next;
        while(aux != nullptr){
            std::cout << "------------------------------------------" << std::endl;
            std::cout << "Linha: " << aux->numberLine << " - " << aux->company << std::endl;
            std::cout << "( " << aux->origin << " / " << aux->destination << " )" << std::endl;
            
            // imprime a paradas
            std::cout << "Paradas: " << std::endl;
            aux->line->print();
            std::cout << "------------------------------------------" << std::endl;
            
            aux = aux->next;
        }
    }
}

//insere o elemento na lista de acordo com o numero da linha
void ForwardList::insert(int numberLine, std::string company, std::string destination, std::string origin){
    // cria o novo no
    NodeForwardList *newNode = new NodeForwardList(numberLine, company, destination, origin, nullptr);
    // se a lista estiver vazia, insere o novo no na frente
    if(head->next == nullptr){
        head->next =  newNode;

    }else if(head->next->numberLine > numberLine){
        // se não, se o numero da linha do primeiro no for maior que o numero da linha do novo no
        // insere o novo no na frente
        newNode->next = head->next;
        head->next = newNode;
    }else{
        // se não, percorre a lista até encontrar o numero da linha maior que o numero da linha do novo no
        NodeForwardList *aux = head->next;
        NodeForwardList *aux2 = head->next;

        while(aux != nullptr && aux->numberLine < numberLine){
            aux2 = aux;
            aux = aux->next;
        }
        // insere o novo no no final
        aux2->next = newNode;
        newNode->next = aux;

    }

    this->size++;
}



// insere o elemento na lista de acordo com o numero da linha
void ForwardList::insertP(int numberLine, std::string stopName, std::string arrivalTime, std::string departureTime, char type){
    // se a lista estiver vazia, insere o novo no na frente
    if(head->next == nullptr){
        std:: cout << "Lista vazia" << std::endl;

    }else{
        // se não, percorre a lista até encontrar o numero da linha maior que o numero da linha do novo no
        NodeForwardList *aux = head->next;

        while(aux != nullptr && aux->numberLine != numberLine){
            aux = aux->next;
        }
        if(aux == nullptr){
            std::cout << "Elemento não encontrado" << std::endl;
        }else{
            if(type == '1'){
                aux->line->insert(stopName, arrivalTime, departureTime);
            }else{
                aux->line->insertFile(stopName, arrivalTime, departureTime);
            }
        }
    }
}


// remove o elemento da lista de acordo com o numero da linha
void ForwardList::remove(int numberLine){
    if(head->next == nullptr){
        std::cout << "Lista vazia" << std::endl;
    }else{
        // cria dois ponteiros auxiliares
        NodeForwardList *aux = head->next;
        NodeForwardList *aux2 = head->next;

        if (aux->numberLine == numberLine){
            head->next = aux->next;
            delete aux;
            this->size--;
            return;
        }

        // percorre a lista até o final
        while(aux != nullptr && aux->numberLine != numberLine){
            // guarda o penultimo no
            aux2 = aux;
            // guarda o ultimo no
            aux = aux->next;
        }
        if(aux == nullptr){
            std::cout << "Elemento não encontrado" << std::endl;
        }else{
            aux2->next = aux->next;
            // deleta o ultimo no
            delete aux;
            this->size--;
        }
    }
}


void ForwardList::removeP(int numberLine, int position){
    if(head->next == nullptr){
        std::cout << "Lista vazia" << std::endl;
    }else{
        // cria dois ponteiros auxiliares
        NodeForwardList *aux = head->next;

        // percorre a lista até o final
        while(aux != nullptr && aux->numberLine != numberLine){
            // guarda o ultimo no
            aux = aux->next;
        }
        if(aux == nullptr){
            std::cout << "Elemento não encontrado" << std::endl;
            
        }else{
            aux->line->remove(position);
        }
    }
}

void ForwardList::search(std::string destination, std::string arrivalTime){
    if(head->next == nullptr){
        std::cout << "Lista vazia" << std::endl;
    }else{
        // cria dois ponteiros auxiliares
        NodeForwardList *aux = head->next;

        int i = 0;

        // percorre a lista até o final
        while(aux != nullptr){
            std::string retorno = aux->line->search(arrivalTime, destination);

            if(retorno != ""){
                std::cout << "------------------------------------------" << std::endl;
                std::cout << aux->numberLine << " - " << aux->company << " - " << aux->destination << " - "
                << aux->origin << std::endl;
                std::cout << retorno << std::endl;

                i--;
            
            }

            i++;

            aux = aux->next;
        }

        if(i == this->size){
            std::cout << "Nenhum onibus encontrado\n\n\n" << std::endl;
        }

    }
}


void ForwardList::edit(int numberLine){
    if(head->next == nullptr){
        std::cout << "Lista vazia" << std::endl;
    }else{
        NodeForwardList *aux = head->next;

        // percorre a lista até o final
        while(aux != nullptr && aux->numberLine != numberLine){
            // guarda o ultimo no
            aux = aux->next;
        }
        if(aux == nullptr){
            std::cout << "Elemento não encontrado" << std::endl;
            
        }else{
            aux->line->edit();
        }
    }
}
