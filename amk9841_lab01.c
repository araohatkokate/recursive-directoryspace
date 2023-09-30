//Name - Araohat Kokate
//Net ID - 1001829841
//Language version - Ubuntu 11.3.0
//OS used - Windows 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

//calculate_total_size is a recursive function that opens the directory and iterates through the entries. 
//If its a directory, the function is called recursively, otherwise the size of the file is added.
long long int calculate_total_size(const char *directory) 
{
    struct dirent *entry;
    struct stat info;// uses stat to check if its a regular directory or a file
    DIR *dir = opendir(directory);
    long long int total_size = 0; // stores the total size of the files in bytes

    if (!dir) 
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) 
        {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

        if (stat(path, &info) == -1) 
        {
            perror("stat");
            continue;
        }

        if (S_ISDIR(info.st_mode)) 
        {
            total_size += calculate_total_size(path);
        } 
        else if (S_ISREG(info.st_mode)) 
        {
            total_size += info.st_size;
        }
    }

    closedir(dir);
    return total_size;
}

int main() 
{
    const char *current_directory = ".";
    long long int total_size = calculate_total_size(current_directory);

    printf("Total size : %lld bytes\n", total_size);

    return 0;
}
