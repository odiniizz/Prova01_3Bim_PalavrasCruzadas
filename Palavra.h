#include <iostream>
#include <fstream>
#include <time.h>


class Palavra{
    private:
        std::string palavraVertical;
        int poscruzamento[10];
        int tamanhoMaiorPalavra, quantidadeColunas, meio;

    public:
        std::string palavrasHorizontais[10];
        char** matriz;
        char** auxmatriz;

        std::string percorrerArquivo(int);
        bool verificaPalavra (std::string, int);
        void sortearPalavras();
        void maiorPalavra(std::string[]);
        void cruzamentos();

        void criarMatrizes();
        void preencherMatriz();
        void preencherMatrizAuxiliar();
        void exibirMatriz();
        void exibirMatrizAuxiliar();

        bool verificaIgualdade();
        bool verificaChute (char);

        /***************** Métodos get e set *****************/

        void setPalavraVertical(std::string palavraVertical);
        std::string getPalavraVertical();
        void setPosCruzamento(int pos, int valor);
        int getPosCruzamento(int pos);
        void setTamanhoMaiorPalavra(int);
        int getTamanhoMaiorPalavra();
        void setQuantidadeColunas(int);
        int getQuantidadeColunas();
        void setMeio(int valor);
        int getMeio();
};
