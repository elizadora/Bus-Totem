# BusTotem - Um Sistem de Informação de Linhas de Ônibus

# Descrição
O sistema BusTotem tem como objetivo principal auxiliar o usuário a encontrar as linhas de ônibus que passam por um determinado ponto destino no qual ele deseja chegar. O sistema então retorna as linhas de onibus disponiveis, contendo origem e destino delas, além de mostrar os horários de partida e chegada de cada linha.

# Funcionalidades
Além de mostrar as linhas de ônibus disponiveis, o sistema permite funcionalidades para o usuário administrador, como adicionar, editar e excluir linhas de ônibus, além de adicionar, editar e excluir pontos de ônibus.
> Para a realização dessas funcionalidades, o usuário administrador deve inserir uma senha de acesso.

# Tecnologias
O projeto é feito puramente em C++, fazendo uso da leitura de arquivos e conceitos básicos de programação orientada a objetos, utilizando também de estruturas de dados para a manipulação dos dados.

# Como usar
Para a utilização do sistem, basta fazer a compilação do arquivo `main.cpp` e executar o arquivo gerado. O sistema irá mostrar um menu com as opções disponiveis, onde o usuário poderá escolher a opção desejada.

Para a compilação do arquivo, basta executar o seguinte comando no terminal:
```bash
g++ *.cpp -o main -Wall -Wextra
```

Ao executar o arquivo será mostrado um menu com as opções disponiveis, onde o usuário poderá escolher a opção desejada. Caso o usuário escolha a opção de administrador, será solicitado uma senha de acesso. Mas caso o usuário escolha a opção de usuário comum, será solicitado o ponto de destino desejado e a hora que ele deseja.
> Nota: a hora deve ser inserida no formato de 24 horas, com os minutos separados por `:`. Exemplo: `14:30`.