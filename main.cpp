//Júlio César Diniz - 2º Informática
//Prova 01 do 2º Bimestre - Laboratório de Linguagem de Programação II - 05/10/2023

#include "Palavra.h"
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));
    Palavra P;
    int op, erros = 0;
    string l;


    do {
    cout << "###### MENU ######\n";
    cout << "1 - Nível fácil (10 erros)\n";
    cout << "2 - Nível médio (8 erros)\n";
    cout << "3 - Nível difícil (5 erros)\n";
    cout << "4 - Sair\n";
    cout << "Digite a opção de jogo desejada: ";
    cin >> op;
    switch(op){
        //Modo de jogo fácil
        case 1:
            erros = 10;
            P.sortearPalavras();
            P.maiorPalavra(P.palavrasHorizontais);
            P.cruzamentos();

            P.criarMatrizes();
            P.preencherMatriz();

            cout << "\n";

            P.preencherMatrizAuxiliar();
            system ("clear");
            P.exibirMatrizAuxiliar();

            do {
                cout << "Você ainda pode errar " << erros << " vezes.\n";
                cout << "Digite uma letra:\n";

                //verifica que o usuário está digitando apenas uma letra
                do{
                    cin >> l;
                    if (l.length() != 1){
                        cout << "Digite apenas UMA letra.\n";
                    }
                }while (l.length() != 1);

                P.verificaChute(l[0]);
                P.exibirMatrizAuxiliar();

                //Os erros diminuem caso a letra não esteja na matriz
                if (!P.verificaChute(l[0])){
                    erros--;
                }

            }while(erros != 0 && P.verificaIgualdade() != true);
            //irá sair do laço quando o jogador perder (quantidade de erros for zerada), ou quando o jogador ganhar (quando a matriz auxiliar for igual à original).

            //teste para exibir a mensagem final
            if (erros == 0){
                cout << "Fim de jogo!!! Você excedeu a quantidade máxima de erros.\n";
                cout << "O gabarito é:\n";
                P.exibirMatriz();
                cout << "\n";
            } else  {
                cout << "VITÓRIA!!!!!!!!\n";
                cout << "Você acertou todas as palavras!!!\n";
                cout << "\n";
            }

        break;

        //Modo de jogo médio
        case 2:
            erros = 8;
            P.sortearPalavras();
            P.maiorPalavra(P.palavrasHorizontais);
            P.cruzamentos();

            P.criarMatrizes();
            P.preencherMatriz();

            cout << "\n";

            P.preencherMatrizAuxiliar();
            system ("clear");
            P.exibirMatrizAuxiliar();

            do {
                cout << "Você ainda pode errar " << erros << " vezes.\n";
                cout << "Digite uma letra:\n";

                //verifica que o usuário está digitando apenas uma letra
                do{
                    cin >> l;
                    if (l.length() != 1){
                        cout << "Digite apenas UMA letra.\n";
                    }
                }while (l.length() != 1);

                P.verificaChute(l[0]);
                P.exibirMatrizAuxiliar();

                //Os erros diminuem caso a letra não esteja na matriz
                if (!P.verificaChute(l[0])){
                    erros--;
                }

            }while(erros != 0 && P.verificaIgualdade() != true);
            //irá sair do laço quando o jogador perder (quantidade de erros for zerada), ou quando o jogador ganhar (quando a matriz auxiliar for igual à original).

            //teste para exibir a mensagem final
            if (erros == 0){
                cout << "Fim de jogo!!! Você excedeu a quantidade máxima de erros.\n";
                cout << "O gabarito é:\n";
                P.exibirMatriz();
                cout << "\n";
            } else  {
                cout << "VITÓRIA!!!!!!!!\n";
                cout << "Você acertou todas as palavras!!!\n";
                cout << "\n";
            }
        break;
        //modo de jogo difícil
        case 3:
            erros = 10;
            P.sortearPalavras();
            P.maiorPalavra(P.palavrasHorizontais);
            P.cruzamentos();

            P.criarMatrizes();
            P.preencherMatriz();

            cout << "\n";

            P.preencherMatrizAuxiliar();
            system ("clear");
            P.exibirMatrizAuxiliar();

            do {
                cout << "Você ainda pode errar " << erros << " vezes.\n";
                cout << "Digite uma letra:\n";

                //verifica que o usuário está digitando apenas uma letra
                do{
                    cin >> l;
                    if (l.length() != 1){
                        cout << "Digite apenas UMA letra.\n";
                    }
                }while (l.length() != 1);

                P.verificaChute(l[0]);
                P.exibirMatrizAuxiliar();

                //Os erros diminuem caso a letra não esteja na matriz
                if (!P.verificaChute(l[0])){
                    erros--;
                }

            }while(erros != 0 && P.verificaIgualdade() != true);
            //irá sair do laço quando o jogador perder (quantidade de erros for zerada), ou quando o jogador ganhar (quando a matriz auxiliar for igual à original).

            //teste para exibir a mensagem final
            if (erros == 0){
                cout << "Fim de jogo!!! Você excedeu a quantidade máxima de erros.\n";
                cout << "O gabarito é:\n";
                P.exibirMatriz();
                cout << "\n";
            } else  {
                cout << "VITÓRIA!!!!!!!!\n";
                cout << "Você acertou todas as palavras!!!\n";
                cout << "\n";
            }

        break;

        case 4:
            cout << "Até mais!";
        break;

        default:
            cout << "Opção inválida. Tente novamente.";

    }

    }while (op != 4);

 return 0;
}
