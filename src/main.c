#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

// Function to print command history
void print_history(void)
{
    HIST_ENTRY **hist = history_list();

    if (hist == NULL)
    {
        printf("No commands in history.\n");
        return;
    }

    for (int i = 0; hist[i] != NULL; i++)
    {
        printf("%d %s\n", i + 1, hist[i]->line);
    }
}

int main(void)
{
    // Welcome Banner
    printf("=====================================\n");
    printf("          Shellforge\n");
    printf("   A Unix Style Shell written in C\n");
    printf("=====================================\n");

    // Initialize history
    using_history();

    char *line;

    while (1)
    {
        line = readline("shellforge$ ");

        if (line == NULL)
        {
            printf("\nGoodbye!\n");
            break;
        }

        // Ignore empty input
        if (strlen(line) == 0)
        {
            free(line);
            continue;
        }

        // Exit command
        if (strcmp(line, "exit") == 0)
        {
            free(line);
            printf("Exiting...\n");
            break;
        }

        // Save command in history
        add_history(line);

        // Show history
        if (strcmp(line, "history") == 0)
        {
            print_history();
            free(line);
            continue;
        }

        // Echo user input
        printf("YOU ENTERED : %s\n", line);

        free(line);
    }

    return 0;
}
