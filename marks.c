#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <sys/stat.h>
// #include <sys/types.h>
#include <sys/fcntl.h>
#include <stdbool.h>

int main(int argc, char * argv[])
{
    const unsigned char PATH_BUF_SIZE = 128;
    char path[PATH_BUF_SIZE];
    char *home_path;
    char *filename = "marks";

    char *xdg_data_home;
    if ((xdg_data_home = getenv("XDG_DATA_HOME")) != NULL)
    {
        long xdglen = strlen(xdg_data_home);
        unsigned char xdg_path_size = strlen(filename) + 2; // Extra for slash
        if (xdglen > PATH_BUF_SIZE - xdg_path_size)
        {
            perror("XDG Data Home path is unusually large, exiting...");
            return 1;
        }
        xdg_path_size += xdglen;

        strcpy(path, xdg_data_home);
        strcat(path, "/");
        strcat(path, filename);
    }
    else
    {
        if ((home_path = getenv("HOME")) == NULL)
        {
            perror("Could not find user $HOME environment variable.");
            return 1;
        }

        char *marks_filepath = "/.local/share/";
        long homelen = strlen(home_path);
        unsigned char path_size = strlen(marks_filepath) + strlen(filename) + 1;
        if (homelen > PATH_BUF_SIZE - path_size)
        {
            perror("HOME path is unusually large, exiting...");
            return 1;
        }
        path_size += homelen;

        strcpy(path, home_path);
        strcat(path, marks_filepath);
        strcat(path, filename);
    }


    int fd = open(path, O_RDWR | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("Error opening/creating file marks file.");
        return 1;
    }
    printf("The file descriptor is: %i", fd);


    return 0;
}

