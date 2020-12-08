#include <stdio.h>
#include <stdlib.h>
int tamanhoLote = 80, tamanhoTipo = 16, tamanhoPlataforma = 50; // Tamanhos de vetor e strings
int i, j;


/* Funções auxiliares do código */

int contaVetoresLote(int *vetor) {
    int contaVetor = 0;
    for (i = 0; i < tamanhoLote; i++){
        if (vetor[i] != 0){
            contaVetor++;
        }
    }
    return contaVetor;
}

void ordenaVetor(int *vetor) {
    int limiteSuperior = tamanhoLote - 1, troca, aux;
    do{
        troca = 0;
        for (i = 0; i <= (limiteSuperior - 1); i++){
            if(vetor[i] > vetor[i+1]) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                troca = 1;
            }
        }
        limiteSuperior = limiteSuperior - 1;
        
    } while (troca == 1);
}

int pesquisaCodigo(int *vetor, int codigo, int tamanhoVetor) {
    int limiteSuperior = tamanhoVetor - 1, limiteInferior = 0, meio, posicao = -1;

    while((limiteInferior <= limiteSuperior) && (posicao == -1)) {
        meio = (limiteInferior + limiteSuperior) / 2;
        if(vetor[meio] == codigo) {
            posicao = meio;
        } else {
            if(vetor[meio] > codigo) {
                limiteSuperior = meio - 1;
            } else {
                limiteInferior = meio + 1;
            }
        }
    }
    return posicao;
}

/* Funções para cada caso da consulta */

void adicionaLote(int *codigos, int *quantidades, char **tipos, char **plataformas, float *compras, float *vendas) {
    int tamanhoVetorLote = contaVetoresLote(codigos), novoCodigo;
    int novoVetor[tamanhoVetorLote], contador1 = 0, confereCodigo = 0;
    for (i = 0; i < tamanhoLote; i++){
        if (codigos[i] != 0){
            novoVetor[contador1] = codigos[i];
            contador1++;
        }
        
    }

    for (i = 0; i < tamanhoVetorLote; i++){
        if(novoVetor[i] != (1001 + i)) {
            printf("%d\n", novoVetor[i]);
            novoCodigo = 1001 + i;
            confereCodigo = 1;
            codigos[0] = novoCodigo;
        }
    }

    if(confereCodigo == 0) {
        novoCodigo = 1000 + (tamanhoVetorLote + 1);
        codigos[0] = novoCodigo;
    }

    int quantidade, tamanhoNovoVetor = contaVetoresLote(codigos), contador2 = 0, posicaoItens;
    int vetorCodigoAtual[tamanhoNovoVetor];
    char tipo[tamanhoTipo], plataforma[tamanhoPlataforma];
    float compra, venda;

    ordenaVetor(codigos);

    for (i = 0; i < tamanhoLote; i++){
        if (codigos[i] != 0){
            vetorCodigoAtual[contador2] = codigos[i];
            contador2++;
        }
        
    }

    posicaoItens = pesquisaCodigo(vetorCodigoAtual, novoCodigo, tamanhoNovoVetor);
    
    printf("Insira as informações do lote\n");
    printf("Quantidade de barris: ");
    scanf("%d", &quantidade);
    quantidades[posicaoItens] = quantidade;
    printf("Tipo do lote: ");
    gets(tipo);
    tipos[posicaoItens] = tipo;
    printf("Plataforma de origem: ");
    gets(plataforma);
    plataformas[posicaoItens] = plataforma;
    printf("Preço de compra: ");
    scanf("%f", &compra);
    compras[posicaoItens] = compra;
    printf("Preço de venda: ");
    scanf("%f", &venda);
    vendas[posicaoItens] = venda;
    printf("\n");
    printf("Lote criado!");

}

void deletaLote(int *codigos, int *quantidades, char **tipos, char **plataformas, float *compras, float *vendas) {
    int tamanhoVetorLote = contaVetoresLote(codigos), codigo, posicaoVetor, posicaoCodigo;
    int novoVetor[tamanhoVetorLote], contador = 0;
    for (i = 0; i < tamanhoLote; i++){
        if (codigos[i] != 0){
            novoVetor[contador] = codigos[i];
            contador++;
        }
        
    }

    printf("Insira o código do lote a ser deletado: ");
    scanf("%d", &codigo);
    posicaoVetor = pesquisaCodigo(novoVetor, codigo, tamanhoVetorLote);

    if(posicaoVetor == -1) {
        printf("Lote não encontrado\n");
    } else {
        codigos[posicaoVetor] = 0;
        quantidades[posicaoVetor] = 0;
        tipos[posicaoVetor] = 0;
        plataformas[posicaoVetor] = 0;
        compras[posicaoVetor] = 0;
        vendas[posicaoVetor] = 0;

        printf("Lote deletado!\n");
    }

}

void modificaLotes(int *codigos, int *quantidades, char **tipos, char **plataformas, float *compras, float *vendas) {
    int tamanhoVetorLote = contaVetoresLote(codigos), codigo, posicaoVetor;
    int novoVetor[tamanhoVetorLote], contador = 0;
    for (i = 0; i < tamanhoLote; i++){
        if (codigos[i] != 0){
            novoVetor[contador] = codigos[i];
            contador++;
        }
        
    }

    int quantidade, opcao;
    char tipo[tamanhoTipo], plataforma[tamanhoPlataforma];
    float compra, venda;
    printf("Insira o código do lote que deseja atualizar: ");
    scanf("%d", &codigo);
    posicaoVetor = pesquisaCodigo(novoVetor, codigo, tamanhoVetorLote);
    printf("\n");

    do{
        do{
            printf("ATUALIZAÇÃO DE LOTE");
            printf("\n----------------------------------\n");
            printf("1 - Quantidade de barris\n");
            printf("2 - Tipo do lote\n");
            printf("3 - Plataforma de origem\n");
            printf("4 - Preço de compra\n");
            printf("5 - Preço de venda\n");
            printf("6 - Encerrar atualização\n");
            printf("Escolha uma das 6 opções acima para atualizar: ");
            scanf("%d", &opcao);
        } while (opcao < 1 && opcao > 6);
        
        switch (opcao){
        case 1:
            printf("Insira a quantidade de barris: ");
            scanf("%d", &quantidade);
            quantidades[posicaoVetor] = quantidade;
            break;
        case 2:
            printf("Insira o tipo do lote: ");
            gets(tipo);
            tipos[posicaoVetor] = tipo;
            break;
        case 3:
            printf("Insira a plataforma de origem: ");
            gets(plataforma);
            plataformas[posicaoVetor] = plataforma;
            break;
        case 4:
            printf("Insira o preço de compra: ");
            scanf("%f", &compra);
            compras[posicaoVetor] = compra;
            break;
        case 5:
            printf("Insira o preço de venda: ");
            scanf("%f", &venda);
            vendas[posicaoVetor] = venda;
            break;
        case 6:
            printf("Atualização encerrada!\n");
            break;

        default: printf("Opção inválida\n");
            break;
        }
        printf("\n");
    }while (opcao != 6);

    printf("\n\nInformações do lote: %d\n", novoVetor[posicaoVetor]);
    printf("----------------------------------\n");
    printf("Quantidade de barris: %d\n", quantidades[posicaoVetor]);
    printf("Tipo do lote: %s\n", tipos[posicaoVetor]);
    printf("Plataforma de origem: %s\n", plataformas[posicaoVetor]);
    printf("Preço de compra do barril: %.2f\n", compras[posicaoVetor]);
    printf("Preço de venda do refinado: %.2f\n", vendas[posicaoVetor]);

}

void consultaPrecos(int *codigos, float *compras, float *vendas) {
    int tamanhoVetorLote = contaVetoresLote(codigos), codigo, posicaoVetor;
    int novoVetor[tamanhoVetorLote], contador = 0;
    for (i = 0; i < tamanhoLote; i++){
        if (codigos[i] != 0){
            novoVetor[contador] = codigos[i];
            contador++;
        }
        
    }

    printf("Insira o código do lote para consultar seus preços: ");
    scanf("%d", &codigo);

    posicaoVetor = pesquisaCodigo(novoVetor, codigo, tamanhoVetorLote);
    if(posicaoVetor == -1) {
        printf("Código não encontrado\n");
        printf("\n");
    } else{
        printf("Preços do lote %d", codigo);
        printf("\n----------------------------------\n");
        printf("Preço de compra: %.2f\n", compras[posicaoVetor]);
        printf("Preço de venda refinado: %.2f\n", vendas[posicaoVetor]);
        printf("\n");
    }

}

void consultaLotes(int *codigos, int *quantidades, char **tipos, char **plataformas, float *compras, float *vendas) {
    int tamanhoVetorLote = contaVetoresLote(codigos);
    int novoVetor[tamanhoVetorLote], contador = 0;
    for (i = 0; i < tamanhoLote; i++){
        if (codigos[i] != 0){
            novoVetor[contador] = codigos[i];
            contador++;
        }
        
    }
    
    for (i = 0; i < tamanhoVetorLote; i++){
        printf("\n\nInformações do lote: %d\n", novoVetor[i]);
        printf("----------------------------------\n");
        printf("Quantidade de barris: %d\n", quantidades[i]);
        printf("Tipo do lote: %s\n", tipos[i]);
        printf("Plataforma de origem: %s\n", plataformas[i]);
        printf("Preço de compra do barril: %.2f\n", compras[i]);
        printf("Preço de venda do refinado: %.2f\n", vendas[i]);
    }
    printf("\n\n\n");
}

int main(void) {
    int operacao, 
    codigoLote[80] = { 1001, 1004, 1003, 1002, 1005, 1008, 1007, 1006, 1009, 1010 }, //Código de cada lote no formato 10XX, sendo XX seu número principal
    quantidadeLote[80] = { 60, 70, 80, 75, 65, 55, 86, 98, 92, 51 }; // Quantidade de barris em cada lote
    char *tipoLote[80] = { "Parafínicos", "Naftênicos", "Aromáticos", "Parafínicos", "Mistos", "Aromáticos", "Naftênicos", "Parafínicos", "Mistos", "Parafínicos" }, // Tipo de petróleo de cada lote
    *plataformaLote[80] = { "FPSO CIDADE DE ITAGUAÍ", "FPSO CIDADE DE MARICÁ", "FPSO CIDADE DE SAQUAREMA", "PETROBRAS 58", "FPSO CIDADE DE MANGARATIBA", "FPSO CIDADE DE SÃO PAULO", "FPSO CIDADE DE ILHA BELA", "FPSO CIDADE DE PARATY", "FPSO CIDADE DE ANGRA DOS REIS", "PETROBRAS 52" }; //Plataforma de origem do lote
    float compraLote[80] = { 220.40, 220.60, 210.37, 214.78, 200.76, 215.39, 190.54, 200.78, 205.65, 200.23 }, // Preço de compra do barril bruto a unidade
    vendaLote[80] = { 240.50, 235.60, 220.67, 234.75, 210.76, 245.39, 200.54, 230.78, 215.65, 204.23 }; // Preço de venda do petróleo refinado a unidade
    do{
        do{
            printf("\nCONSULTA REFINARIA\n");
            printf("1 - Cadastrar um novo lote de barris\n");
            printf("2 - Excluir um determinado lote pelo código\n");
            printf("3 - Atualizar os dados de um lote já cadastrado\n");
            printf("4 - Consultar valor total comprado de um fornecedor\n");
            printf("5 - Consultar o relatório de lucratividade\n");
            printf("6 - Consultar os dados dos lotes\n");
            printf("7 - Encerrar o sistema\n");
            printf("Escolha uma das 7 opções acima: ");
            scanf("%d", &operacao);
            
            printf("\n----------------------------------\n\n");

        } while (operacao < 1 && operacao > 7);
        
        switch (operacao){
        case 1:
            ordenaVetor(codigoLote);
            adicionaLote(codigoLote, quantidadeLote, tipoLote, plataformaLote, compraLote, vendaLote);
            break;

        case 2:
            ordenaVetor(codigoLote);
            deletaLote(codigoLote, quantidadeLote, tipoLote, plataformaLote, compraLote, vendaLote);
            printf("\nOpção: 2\n");
            break;

        case 3:
            ordenaVetor(codigoLote);
            modificaLotes(codigoLote, quantidadeLote, tipoLote, plataformaLote, compraLote, vendaLote); //Função que atualiza os dados de cada lote
            break;
        case 4:
            ordenaVetor(codigoLote); //Função que ordena o vetor de códigos
            consultaPrecos(codigoLote, compraLote, vendaLote); //Função de consulta dos valores por busca binária
            break;
        case 5:
            printf("\nOpção: 5\n");
            break;
        case 6:
            ordenaVetor(codigoLote); //Função que ordena o vetor de códigos
            consultaLotes(codigoLote, quantidadeLote, tipoLote, plataformaLote, compraLote, vendaLote); //Função que imprimi a consulta de todas informações de todos os lotes
            break;
        case 7:
            printf("\nOpção: 7\nPrograma encerrado\n");
            break;
        
        default: printf("\nOpção inválida!\nTente outra opção\n");
            break;
        }
        
    } while (operacao != 7);
    
    return 0;
}
