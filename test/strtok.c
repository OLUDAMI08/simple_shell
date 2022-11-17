#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int ac, char **argv){
    char *prompt = "(shell) $ ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t n_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    (void)ac;

    while (1) {
        printf("%s", prompt);
        n_read = getline(&lineptr, &n, stdin);
        if (n_read == -1){
            return (-1);
        }

        lineptr_copy = malloc(sizeof(char) * n_read);
        if (lineptr_copy== NULL){
            perror("Error");
            return (-1);
        }
        /* copy lineptr to lineptr_copy */
        strcpy(lineptr_copy, lineptr);

        token = strtok(lineptr, delim);

        while (token != NULL){
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;



    }

free(lineptr);
free(lineptr_copy);
    return (0);
}

