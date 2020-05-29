#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char *marks_filepath;
    char *xdg_data_home;

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
            char b[strlen(home_path) + strlen(share_path)];
            strcat(b, home_path);
            strcat(b, share_path);
            xdg_data_home = b;
            // printf(home_path);
            // printf(share_path);
        }
        else
        {
            perror("Could not find user $HOME directory");
            return 1;
        }

    }
    printf(xdg_data_home);

    return 0;
}

