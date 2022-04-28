#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/random.h>
#include <string.h>

#define MAX_LENGTH_FIRST_NAME 32
#define MAX_LENGTH_LAST_NAME 32
#define MAX_LENGTH_PASSWORD 6
#define MAX_LENGTH_DATA_STRING 512
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
int password_validate(char *password)
{
    return 0;
}

char *password_hash(char *password)
{
    char *hashed_password = crypt(password, "$6$rounds=20000$$");
    return hashed_password;
}

// Função responsável por retornar a senha do arquivo responsável por registrar os usuários
// Recebe o ponteiro como parametro e retorna
// Retorna o hash salvo no arquivo
void password_of_file(FILE file)
{
    printf("sssssssssssssss");
};

void register_user(char *first_name, char *last_name, char *password)
{
    char *data_string = malloc(MAX_LENGTH_DATA_STRING);

    strcat(data_string, first_name);
    strcat(data_string, ";,;");
    strcat(data_string, last_name);
    strcat(data_string, ";,;");
    strcat(data_string, password_hash(password));
    strcat(data_string, ";;\n");

    printf("First name: %s \n\n", first_name);
    printf("%s\n\n", data_string);

    FILE *fp;

    fp = fopen(FILENAME, "a+");

    fputs(data_string, fp);

    fclose(fp);

    free(data_string);

    printf("Usuário registrado com sucesso! \n\n");
}

void login()
{
    FILE *fp;

    fp = fopen(FILENAME, "r");

    char *first_name = malloc(MAX_LENGTH_FIRST_NAME);
    char *last_name = malloc(MAX_LENGTH_LAST_NAME);
    char *hashed_password = malloc(MAX_LENGTH_DATA_STRING);

    while (!feof(fp))
    {
        fscanf(fp, "%s;,;%s;,;%s;;\n", first_name, last_name, hashed_password);

        printf("Nome: %s \nSobrenome %s \nHash %s\n\n", first_name, last_name, hashed_password);
    }

    free(first_name);
    free(last_name);
    free(hashed_password);
}

int main(void)
{
    int option = 1;
    char *first_name = malloc(MAX_LENGTH_FIRST_NAME);
    char *last_name = malloc(MAX_LENGTH_LAST_NAME);
    char *password = malloc(MAX_LENGTH_PASSWORD);

    printf("Registre-se\n");

    // printf("Digite seu primeiro nome: \n");
    // scanf("%s", first_name);

    // printf("Digite seu segundo nome: \n");
    // scanf("%s", last_name);

    // printf("Digite sua senha: \n");
    // scanf("%s", password);

    login();
    // register_user(first_name, last_name, password);

    // while (option)
    // {
    //     print_menu();
    //     scanf("%d\n", &option);

    //     switch (option)
    //     {
    //     case 2:
    //         printf("Login");
    //         break;
    //     case 3:

    //         printf("Registre-se\n");

    //         printf("Digite seu primeiro nome: \n");
    //         scanf("%s", first_name);

    //         printf("Digite seu segundo nome: \n");
    //         scanf("%s", last_name);

    //         printf("Digite sua senha: \n");
    //         scanf("%s", password);

    //         register_user(first_name, last_name, password);
    //         break;
    //     case 0:
    //         exit(0);

    //     default:
    //         printf("Digite uma opcao valida\n");
    //     }
    // }

    free(first_name);
    free(last_name);
    free(password);
}