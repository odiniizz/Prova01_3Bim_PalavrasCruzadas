# include "Palavra.h"

std::string Palavra::percorrerArquivo(int sorteado){
    std::string linha, palavra;
    int aux = 0;
    std::ifstream arq("palavras.txt");
    if (arq.is_open()){
        while (getline(arq, linha)) {
            if (aux == sorteado)
                palavra = linha;
            aux++;
        }
        arq.close();
    }
    return palavra;
};

void Palavra::sortearPalavras(){
    int sorteado;
    std::string palavra;
    int posicao = 0;
    for (int i = -1; i < 10; i++){
        if (i == -1) {
            do {
                sorteado = rand() % 245366;
            } while(percorrerArquivo(sorteado).length() != 10);
            setPalavraVertical(percorrerArquivo(sorteado));
        } else {
            do {
                sorteado = rand() % 245366;
                palavra = percorrerArquivo(sorteado);
            } while (verificaPalavra(palavra, posicao) != true);
            palavrasHorizontais[i] = palavra;
            posicao++;
        }
    }
};

bool Palavra::verificaPalavra (std::string palavra, int posicao){
    for (int j = 0; j < palavra.length(); j++) {
        if (getPalavraVertical()[posicao] == palavra[j]){
            return true;
        }
    }
    return false;
};

void Palavra::maiorPalavra(std::string palavrasHorizontais[]){
    int tamanho = 0;
    for (int i = 0; i < 10; i++){
        if ((palavrasHorizontais[i].length()) > tamanho){
            tamanho = palavrasHorizontais[i].length();
        }
    }
    setTamanhoMaiorPalavra(tamanho);
    setQuantidadeColunas(getTamanhoMaiorPalavra() * 2);
};

void Palavra::cruzamentos(){
    for (int i = 0; i < 10; i++){
        bool cruz = false;
        std::string linha = palavrasHorizontais[i];
        for (int j = 0; j < linha.length(); j++){
            if (!cruz && palavraVertical[i] == linha[j]){
                setPosCruzamento(i, j);
                break;
            }
        }
    }
};

void Palavra::criarMatrizes(){
    matriz = new char*[10];
    auxmatriz = new char*[10];

    for (int i = 0; i < 10; i++) {
        matriz[i] = new char[quantidadeColunas];
        auxmatriz[i] = new char[quantidadeColunas];
    }

    for(int i = 0; i < 10; i++){
        for (int j = 0; j < quantidadeColunas; j++){
            matriz[i][j] = '-';
            matriz [i][j] = '-';
        }
    }
};

void Palavra::preencherMatriz(){
    meio = quantidadeColunas / 2 - 1;
    for (int i = 0; i < 10; i++){
        std::string linha = palavrasHorizontais[i];
        int inicio = meio-poscruzamento[i];
        for (int j = 0; j < linha.length(); j++){
            matriz[i][inicio] = linha[j];
            inicio++;
        }
    }
};

void Palavra::preencherMatrizAuxiliar(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < quantidadeColunas; j++){
            if(j == meio){
                auxmatriz[i][j] = matriz[i][j];
            } else {
                auxmatriz[i][j] = '-';
            }
        }
    }
};

void Palavra::exibirMatriz(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < quantidadeColunas; j++){
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }
};

void Palavra::exibirMatrizAuxiliar(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < quantidadeColunas; j++){
            std::cout << auxmatriz[i][j] << " ";
        }
        std::cout << "\n";
    }
};

bool Palavra::verificaIgualdade(){
    bool matrizesIguais = true;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < quantidadeColunas; j++){
            if (auxmatriz[i][j] != matriz[i][j]) {
                matrizesIguais = false;
                break;
            }
        }
    }
    return matrizesIguais;
};

bool Palavra::verificaChute (char letra){
    bool flag = false;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < quantidadeColunas; j++){
            if (matriz[i][j] == letra){
                auxmatriz[i][j] = matriz[i][j];
                flag = true;
            }
        }
    }
    return flag;
};

/***************** Métodos get e set *****************/

void Palavra::setPalavraVertical(std::string palavraVertical){
    this->palavraVertical = palavraVertical;
};

std::string Palavra::getPalavraVertical(){
    return palavraVertical;
};

void Palavra::setPosCruzamento(int pos, int valor){
    poscruzamento[pos] = valor;
};

int Palavra::getPosCruzamento(int pos){
    return poscruzamento[pos];
};

void Palavra::setTamanhoMaiorPalavra(int valor){
    this->tamanhoMaiorPalavra = valor;
};

int Palavra::getTamanhoMaiorPalavra(){
    return tamanhoMaiorPalavra;
};

void Palavra::setQuantidadeColunas(int valor){
    this->quantidadeColunas = valor;
};

int Palavra::getQuantidadeColunas(){
    return quantidadeColunas;
};

void Palavra::setMeio(int valor){
    this->meio = valor;
};

int Palavra::getMeio(){
    return meio;
};
