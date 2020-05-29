#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char *marks_filepath;
    char *xdg_data_home;
    char *b;

    if ((xdg_data_home = getenv("XDG_DATA_HOME")) != NULL)
    {
        marks_filepath = xdg_data_home;
    }
    else
    {
        char *home_path;
        if ((home_path = getenv("HOME")) != NULL)
        {
            char *share_path = "/.local/share";
            b = malloc(strlen(home_path) + strlen(share_path) + 1);
            strcpy(b, home_path);
            strcat(b, share_path);
            xdg_data_home = b;
        }
        else
        {
            perror("Could not find user $HOME directory");
            return 1;
        }

    }
    printf("%s\n", xdg_data_home);

    free(b);
    return 0;
}

