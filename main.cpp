#include <iostream>
#include <fstream>

#include "headers/ForwardList.h"


void carregarDadosArquivo(ForwardList &list){
    std::ifstream file("01.txt");
    
    std::string line;
    std::string company;
    std::string destination;
    std::string origin;
    int numberLine;

    while(getline(file, line)){
        numberLine = stoi(line);


        getline(file, company);


        getline(file, line);

        origin = line.substr(0, line.find(';'));
        line = line.substr(line.find(';') + 1, line.size());
        destination = line.substr(0, line.find(';'));

        list.insert(numberLine, company, destination, origin);

        while(getline(file, line)){
            if(file.peek() >= '0' && file.peek() <= '9'){
                break;
            }
            
            std::string stopName = line.substr(0, line.find(';'));
            line = line.substr(line.find(';') + 1, line.size());

            std::string arrivalTime = line.substr(0, line.find(';'));
            line = line.substr(line.find(';') + 1, line.size());
            
            std::string departureTime = line.substr(0, line.find(';'));

            

            list.insertP(numberLine, stopName, arrivalTime, departureTime, '0');
        }
    }

}

int main(){    
    std::string password;
    std::string command;

    // cria a lista
    ForwardList list;

    // carrega os dados do arquivo
    carregarDadosArquivo(list);

    while(true){
        std::cout << "--- Menu ---" << std::endl;
        std::cout << "(1) Procurar linha de onibus" << std::endl;
        std:: cout << "(2) Manutencao do Programa" << std::endl;
        std::cout << "(3) Sair" << std::endl;
        std::cout << "-------------" << std::endl;
        std::cout << std::endl;

        std::cout << "Digite o comando:" << std::endl;

        getline(std::cin, command);

        if(command == "1"){
            std::cout << "Digite o destino: " << std::endl;
            std::string destination;
            getline(std::cin, destination);

            std::cout << "Digite o horario aproximado que deseja chegar: " << std::endl;
            std::string arrivalTime;
            getline(std::cin, arrivalTime);

            list.search(destination, arrivalTime);
        
        }else if(command == "2"){
            std::cout << "Digite a senha: " << std::endl;
            getline(std::cin, password);

            if(password == "admin"){
                while(true){
                    std::cout << "--- Menu ---" << std::endl;
                    std::cout << "(1) Inserir linha de onibus" << std::endl;
                    std::cout << "(2) Remover linha de onibus" << std::endl;
                    std::cout << "(3) Inserir parada na linha de onibus" << std::endl;
                    std::cout << "(4) Remover parada de uma linha de onibus" << std::endl;
                    std::cout << "(5) Imprimir a lista de onibus" << std::endl;
                    std::cout << "(6) Alterar parada de uma linha de onibus" << std::endl;
                    std::cout << "(7) Sair" << std::endl;
                    std::cout << "-------------" << std::endl;
                    std::cout << std::endl;

                    std::cout << "Digite o comando:" << std::endl;
                    getline(std::cin, command);
                    
                    std::cout << command << std::endl;

                    if(command == "1"){
                        int numberLine;
                        std::cout << "Digite o numero da linha: " << std::endl;
                        std::cin >> numberLine;
                        std::cin.ignore();

                        std::string company;
                        std::cout << "Digite o nome da empresa: " << std::endl;
                        getline(std::cin, company);


                        std::string origin;
                        std::cout << "Digite a origem: " << std::endl;
                        getline(std::cin, origin);

                        std::string destination;
                        std::cout << "Digite o destino: " << std::endl;
                        getline(std::cin, destination);

                        list.insert(numberLine, company, destination, origin);

                    }else if(command == "2"){
                        int numberLine;
                        std::cout << "Digite o numero da linha: " << std::endl;
                        std::cin >> numberLine;

                        list.remove(numberLine);

                    }else if(command == "5"){
                        list.print();

                    }else if(command == "3"){
                        int numberLine;
                        std::cout << "Digite o numero da linha: " << std::endl;
                        std::cin >> numberLine;
                        std::cin.ignore();

                        std::string stopName;
                        std::cout << "Digite o nome da parada: " << std::endl;
                        getline(std::cin, stopName); 
                        
                        std::string arrivalTime;
                        std::cout << "Digite o horario de chegada: " << std::endl;
                        getline(std::cin, arrivalTime);

                        std::string departureTime;
                        std::cout << "Digite o horario de saida: " << std::endl;
                        getline(std::cin, departureTime);

                        list.insertP(numberLine, stopName, arrivalTime, departureTime, '1');
                    
                    
                    }else if(command == "4"){
                        int numberLine;
                        std::cout << "Digite o numero da linha: " << std::endl;
                        std::cin >> numberLine;


                        std::cout << "Digite a posicao da parada: " << std::endl;
                        int position;
                        std::cin >> position;

                        list.removeP(numberLine, position);
                    
                    }else if(command == "6"){
                        std::cout << "Digite o numero da linha: " << std::endl;
                        int numberLine;
                        std::cin >> numberLine;
                        std::cin.ignore();

                        list.edit(numberLine);
                    
                    }else if(command == "7"){
                        break;
                    
                    }else{
                        std::cout << "Comando invalido" << std::endl;
                    }
                }
            }else{
                std::cout << "Senha incorreta" << std::endl;
            }
        
        }else if(command == "3"){
            break;
        }else{
            std::cout << "Comando invalido" << std::endl;
        }
    }    
}