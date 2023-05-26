# CRUD com Listas Encadeadas Dinâmicas
## Objetivo

Desenvolver uma biblioteca para cadastro de dados utilizando uma estrutura de dados genérica na linguagem C .
<br>
<br>

## Especificações

1- O sistema deverá possuir um menu para escolha das funções por parte do usuário, conforme o exemplo:

    1) Inserir dados no inicio
    2) Inserir dados no final
    3) Remover no início
    4) Remover no final
    5) Remover um item qualquer da lista
    6) Localizar um item qualquer da lista em arquivo
    7) Imprimir a lista
    -1) Sair

<br>

## Métodos implementados

Criação de uma nova lista 
```
List* create()
```

Inserir um novo registro no inicio da lista
```
void insertFirst(List* list, Client client) 
```

Inserir um novo registro no final da lista
```
void insertLast(List* list, Client client) 
```

Remove um novo registro no inicio da lista
```
void removeFirst(List* list)
```

Remove um novo registros no final da lista
```
void removeLast(List* list)
```

Remove um novo registro da lista pelo seu Id
```
void toRemove(List* list, int id)
```

Exibe todos os registros da lista
```
void getAll(List* list) 
```

Busca um registro na lista pelo id
```
ListNode* get(List* list, int id)

```

Busca e atuzaliza um registro na lista pelo id
```
ListNode* getAndUpdate(List* list, int id, Client client)
```

Atualiza um registro na lista pelo id
```
ListNode* update(List* list, int id, Client client)
```

```
## Requisitos 

- [gcc](https://gcc.gnu.org/onlinedocs/)


## Como Rodar
Na raiz do arquivo execute o comando 

<code> bash exec.sh</code>