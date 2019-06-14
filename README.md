# tpPDS2

Arquivos da maquininha de busca:

O projeto foi todo feito usando o Visual Studio. Para abrir o projeto, basta clicar no arquivo "TP-PDS2.sln".
Ao abrir o projeto, abra o gerenciador de soluções do Visual Studio. Lá estarão todos os arquivos usados para fazer o programa de busca.
Os arquivos podem ser abertos também abrindo a pasta "main". Todos estão contidos lá, inclusive os arquivos de texto que serão lidos.

Na pasta principal, está o projeto que estávamos desenvolvendo inicialmente. Ele lê arquivos do tipo "d1.txt", "d2.txt", "dn.txt", com n >= 1. Nessa implementação, todos os arquivos tem que estar sequenciais, ou seja, se na pasta tiverem os arquivos: "d1.txt", "d2.txt" e "d4.txt", o programa só vai ler até o arquivo "d2.txt", tudo automático. O programa principal irá ler os arquivos nomeados dessa forma, sequencialmente, até não houver mais arquivos.

Os testes unitários estão contidos no arquivo "teste.cpp".

Depois de o software já estar pronto, descobrimos que o professor tinha colocado vários arquivos para testes, que variavam de 10000 até 100000. Sem nenhuma extensão, e não necessariamente sequenciais. Pensamos em mudar o programa principal para ler estes arquivos, mas como os testes unitários já haviam todos sidos desenvolvidos para a primeira versão do programa, decidimos pegar e adaptar a versão para ler os arquivos que o professor mandou. Esse projeto adaptado está contido na pasta "Adaptação para arquivos professor". Ele está otimizado para ler os arquivos dentro da pasta "\Adaptação para arquivos professor\main\txts".
Para ler todos os 18 mil arquivos, o programa está demorando muito tempo, então deixamos a pasta com somente 1000 arquivos, o que dá um tempo de leitura e pesquisa razoável: da ordem de 2 minutos. Esse programa atualmente está configurado para ler arquivos de "50000" até "78000". Para mudar o range de pesquisa de arquivos, ou seja, ler arquivos por exemplo de "10000" até "100000", é só abrir o arquivo "\Adaptação para arquivos professor\main\LeituraArquivos.cpp" e mudar nas linhas 14 e 107, o range do loop "for". Então ficaria: "for (int i = 10000; i <= 100000; i++)" para ler arquivos de 10000 até 100000. Não esqueça de mudar nas duas linhas.


Grupo:

André L. A. Rezende - 2018104050

Arthur de Lapertosa Lisboa - 2018115469

Thales Pereira Tenebra 2018072080
