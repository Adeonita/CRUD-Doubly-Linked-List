#include "list/list.h"

#define DATABASE "./database.txt"

void menu()
{
    int id;
    int resp = 0;

    Client client; 
    List* database = create();

    printf("Bem vindo ao Cadastro!");

    while(resp != -1)
    {
        printf("\nDigite 1 para Inserir no inicio, 2 para inserir no final, 3 para remover do inicio, \n4 para remover do final, 5 para remover, 6 para consultar, 7 para listar -1 para sair: \n");
        scanf("%d", &resp);

        switch (resp)
        {
            case 1:
                printf("Insira o nome: ");
                scanf("%s", &client.name);

                printf("Insira o idade: ");
                scanf("%d", &client.age);
                
                insertFirst(database, client);
                break;

            case 2:           
                printf("Insira o nome: ");
                scanf("%s", &client.name);

                printf("Insira a idade: ");
                scanf("%d", &client.age);

                insertLast(database, client);

                break;

            case 3:
                if(database->first == NULL) {
                    emptyDatabaseMessage("remover");
                    break;
                }

                removeFirst(database);
                break;

            case 4:
                if(database->first == NULL) {
                    emptyDatabaseMessage("remover");
                    break;
                }

                removeLast(database);
                break;

            case 5:
                if (database->first == NULL)
                {
                    emptyDatabaseMessage("deletar");
                    break;
                }
                
                printf("Insira o id do usuário a ser deletado: ");
                scanf("%d", &id);

                if (id > database->totalElements - 1) {
                    notFound("User");
                    break;
                }

                toRemove(database, id);
                sleep(3);
                printWithLine("Usuário removido com sucesso!");
                break;  

            case 6:
                printf("Insira o id do usuário a ser consultado: ");
                scanf("%d", &id);
                
                if (database->first == NULL) {
                    printWithLine("Não há registros para serem consultados no banco de dados");
                    
                    break;
                }

                get(database, id);
                break;

            case 7:
                if (database->first == NULL) {
                    printWithLine("Não há registros para serem consultados no banco de dados");
                    
                    break;
                }

                getAll(database);
                break;
            default:
                break;
        }
    
    }
}

int main()
{
    menu();
}