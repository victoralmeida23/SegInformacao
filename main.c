#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/random.h>
#include <string.h>

#define MAX_LENGTH 6
#define FILENAME "data.txt"

// Função responsável por realizar o print do menu inicial
void print_menu()
{
    printf("Menu \n");
    printf("2 - Realizar Login \n");
    printf("3 - Registrar-se \n");
    printf("0 - Sair \n");
};


// valida se a senha digitada está de acordo com a politica de senhas estabelecida
// recebe a senha digitada
// retorna 1 para senha de acordo com a politica e 0 para não
int password_validate(char password[MAX_LENGTH])
{
    return 0;
}

char *password_hash(char password[MAX_LENGTH])
{
    return crypt(password, "$6$rounds=20000$$");
}

// Função responsável por retornar a senha do arquivo responsável por registrar os usuários
// Recebe o ponteiro como parametro e retorna
// Retorna o hash salvo no arquivo
char password_of_file(FILE file) {
    return "";
};

int main(void)
{
    int option = 1;
    do
    {
        print_menu();
        scanf("%d\n", &option);

        switch (option)
        {
        case 2:
            printf("Login");
            break;
        case 3:
            printf("Registro");
            break;
        case 0:
            exit(0);

        default:
            printf("Digite uma opcao valida\n");
        }
    } while (option);
}