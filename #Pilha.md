# Pilha em C


## Breve resumo

   Esta é uma demonstração do conteúdo aprendido em aula de
Estrutura de Dados e a línguagem de programação utilizada é C.
    Pilha ou stack é uma estrutura linear em que inserções de dados 
ou remoção de dados é feito em uma extremidade,no código e intuitivamente foi definido uma variável chamada topo. Este conceito é também conhecido como, o último a entrar é o primeiro a sair - LIFO(Lats in First out).

## Validando uma expressão matemática.

    Este código tem a finalidade de reconhecer os caracteres de abertura e fechamento de uma expressão matemática qualquer digitada por um usuário.

    No código é criado uma função onde verificaremos se a pilha esta vazia:

    int empty(Stack *pilha){
    if(pilha->topo == -1)
        return 1;
    else
        return 0;}


    Criaremos também uma função de inserção de dados, caso a memória esteja insuficiente, podemos imprimir este alerta:

    void push(Stack *pilha ,char a){ 
        if(pilha->topo == STACKSIZE -1){
            printf("Sem memória insuficiente");
            exit(1);
    }
    pilha->items[++(pilha->topo)]= a;}

    Criaremos também, uma função de remoção onde primeiro será verificado se a pilha esta fazia, para tal chamaremos na condicional 'if' a função empty(verificação), caso o retorno seja 'False' o dado do topo será removido primeiro indexando o dado na estrutura items e depois decrementar:

    char pop(Stack *pilha){
    if(empty(pilha)){/
        return 1;
    }
    return pilha->items[(pilha->topo--)];}


