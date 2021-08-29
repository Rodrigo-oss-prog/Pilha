#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 100
#define EXPSIZE 200

typedef struct stack{
    int topo; //variável para definirmos o topo da pilha
    char items[STACKSIZE];//variável do tipo char que receberá STACKSIZE
}Stack;

int empty(Stack *pilha){
    if(pilha->topo == -1)
        return 1;
    else
        return 0;
}

void push(Stack *pilha ,char a){ //função inserção de dados 
    if(pilha->topo == STACKSIZE -1){
        printf("Sem memória insuficiente");
        exit(1);
    }
    pilha->items[++(pilha->topo)]= a;//inserção na pilha
}

char pop(Stack *pilha){
    if(empty(pilha)){//condição chamando a função para verificar se a pilha esta vazia
        return 1;
    }
    return pilha->items[(pilha->topo--)];//remoção de um dado primeiro irá indexar o dado na estrutura items e depois decrementar
}

int main(){
    Stack pilha; //instânciando uma pilha
    pilha.topo = -1;//instanciando a pilha
    char exp[EXPSIZE];//setor de caracteres para guardar a expressão
    int val = 0;//inicializar em zero para dizer se a expressão é válida


    //armazena a expressão em um vetor
    printf("Digite um expressão matemática: ");
    fgets(exp, EXPSIZE, stdin);

    //percorrer o vetor e adiconar as expressões na pilha
    for(int i = 0;i < strlen(exp);i++){// percorre desde zero ao tamanho da exp
        if(exp[i]=='(' || exp[i] == '[' || exp[i] == '{'){
            push(&pilha, exp[i]);//ao encontrar uma expressão será chamada a função push para empilhar
        }else{
            if(exp[i] == ')' && pop(&pilha)!='('){ //ao encontrar um caracter de fechamento da expressão, será chamado a função pop par desempilhar
                val= 1;
                break;
            }
            if(exp[i] == ']' && pop(&pilha)!= '['){
                val = 1;//sera verificado se é de abertura ou fechamento na expressão
                break;
            }
            if(exp[i] == '}' && pop(&pilha)!= '{'){
                val = 1;//será caracteres de fechamento e abertura na expressão
                break;
            }    
        }
    }
    if(val == 0 && empty(&pilha)){
        printf("Expressão válida!");

    }else{
        printf("Expressão inválida");
    
    }
}