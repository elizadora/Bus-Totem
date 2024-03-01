#include "headers/ForwardListDouble.h"

// construtor
ForwardListDouble::ForwardListDouble() {
    // cria o no cabeca
    this->head = new NodeForwardDouble("", "", "", nullptr, nullptr);
    
    // faz o no cabeca apontar para ele mesmo
    this->head->next = head;
    this->head->previous = head;

    // inicializa o tamanho da lista
    this->size = 0;
}

// insere o elemento na lista
void ForwardListDouble::insertFile(std::string stopName, std::string arrivalTime, std::string departureTime){
    // cria o novo no
    NodeForwardDouble *newNode = new NodeForwardDouble(stopName, arrivalTime, departureTime, head->previous, head);

    this->head->previous->next = newNode;
    this->head->previous = newNode;
    this->size++;
}

// insere o elemento na lista
void ForwardListDouble::insert(std::string stopName, std::string arrivalTime, std::string departureTime){
    // exibir paradas
    NodeForwardDouble *aux = head->next;
    int i = 1;
    while(aux != head){
        std::cout << i << " - " << aux->stopName << std::endl;
        aux = aux->next;
        i++;
    }

    int position;
    std::cout << "Digite a posicao da parada em que deseja inserir apos: ";
    std::cin >> position;
    std::cin.ignore();

    // percorre a lista até a posicao
    aux = head->next;
    for(int i = 0; i < position; i++){
        aux = aux->next;
    }

    // atualiza os ponteiros
    NodeForwardDouble *newNode = new NodeForwardDouble(stopName, arrivalTime, departureTime, aux->previous, aux);
    aux->previous->next = newNode;
    aux->previous = newNode;
    this->size++;
    
}


// remove o elemento da lista de acordo com a posicao
void ForwardListDouble::remove(int position){
    if(this->size == 0){
        std::cout << "Lista vazia" << std::endl;
    }else{
        // cria um no auxiliar
        NodeForwardDouble *aux = head->next;

        position = position - 1;

        // percorre a lista até a posicao
        for(int i = 0; i < position; i++){
            aux = aux->next;
        }

        // atualiza os ponteiros
        aux->previous->next = aux->next;
        aux->next->previous = aux->previous;

        // deleta o no
        delete aux;

        // atualiza o tamanho da lista
        this->size--;
    }
}

void ForwardListDouble::print(){

    std::cout << "Lista de paradas: " << std::endl;

    if(this->size == 0){
        std::cout << "Lista vazia" << std::endl;
    
    }else{
        // cria um no auxiliar
        NodeForwardDouble *aux = head->next;

        // enquanto o no auxiliar nao for o no cabeca
        while(aux != head){
            // imprime o nome da parada
            if(aux->previous == head){
                std::cout << aux->stopName;
            }else{
                std::cout << " -> " << aux->stopName;
            }

            // atualiza o no auxiliar
            aux = aux->next;
        }

        // pula uma linha
        std::cout << std::endl;
    }  
}

std::string ForwardListDouble::search(std::string arrivalTime, std::string destination){
    if(this->size == 0){
        std::cout << "Lista vazia" << std::endl;
        return "";
    
    }else{
        // cria a string de retorno
        std::string retorno = "";

        // cria um no auxiliar
        NodeForwardDouble *aux = head->next;

        // enquanto o no auxiliar nao for o no cabeca
        while(aux != head){
            // imprime o nome da parada
            int tm1_hour, tm1_min, tm2_hour, tm2_min;
            
            // converte para int
            tm1_hour = std::stoi(arrivalTime.substr(0, 2));
            tm1_min = std::stoi(arrivalTime.substr(3, 2));

            tm2_hour = std::stoi(aux->arrivalTime.substr(0, 2));
            tm2_min = std::stoi(aux->arrivalTime.substr(3, 2));


            
            // converte para segundos
            int horaDigitada = tm1_hour * 3600 + tm1_min * 60;
            int horaParada = tm2_hour * 3600 + tm2_min * 60;


            if(horaParada >= horaDigitada && aux->stopName == destination){
                retorno += "Chegada: " + aux->stopName  + " -> "  + aux->arrivalTime + "\n";

                NodeForwardDouble *aux2 = aux->previous;

                // percorrer a lista de tras pra frente
                while(aux2 != head->next){
                    aux2 = aux2->previous;
                }

                retorno += "Saida: " + aux2->stopName  + " -> "  + aux2->departureTime + "\n";

                return retorno;
            }
            // atualiza o no auxiliar
            aux = aux->next;
        }

        return retorno;
    }  
}


void ForwardListDouble::edit(){
    if(this->size == 0){
        std::cout << "Lista vazia" << std::endl;
    
    }else{
        NodeForwardDouble *aux = head->next;
        int i = 1;
        while(aux != head){
            std::cout << i << " - " << aux->stopName << std::endl;
            aux = aux->next;
            i++;
        }

        int position;
        std::cout << "Digite a posicao da parada em que deseja editar" << std::endl;
        std::cin >> position;
        std::cin.ignore();

        // percorre a lista até a posicao
        aux = head->next;
        for(int i = 1; i < position; i++){
            aux = aux->next;
        }

        std::string stopName;
        std::cout << "Digite o nome da parada: " << std::endl;
        getline(std::cin, stopName);

        std::string arrivalTime;
        std::cout << "Digite o horario de chegada: " << std::endl;
        getline(std::cin, arrivalTime);

        std::string departureTime;
        std::cout << "Digite o horario de saida: " << std::endl;

        getline(std::cin, departureTime);

        aux->stopName = stopName;
        aux->arrivalTime = arrivalTime;
        aux->departureTime = departureTime;
    }  
}
