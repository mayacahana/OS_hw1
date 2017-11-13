//
// Created by Maya Cahana on 11/6/17.
//

#include "hw1_subs.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
    printf("Start");
    // check the command line arguments
    // assert two argument
    if (argc != 3) {
        perror("Error : Wrong number of argument");
        return 1;
    }
    const char *str1 = argv[1];
    const char *str2 = argv[2];
    const char *hw1dir = getenv("HW1DIR");
    const char *hw1tf = getenv("HW1TF");
    struct stat st;
    int size, i=0;
    // in case of the env var not defined - return error
    if (hw1dir == NULL || hw1tf == NULL) {
        return 1;
    }
    // combine the input file path
    char *file_path = (char *)malloc((strlen(hw1dir) + strlen(hw1tf) + 2) * sizeof(char));
    // if (!file_path) - malloc didn't succseeded
    if (!file_path)
        return 1;
    strcpy(file_path, hw1dir);
    file_path[strlen(hw1dir)] = '/';
    strcpy(&file_path[strlen(hw1dir) + 1], hw1tf);
    // open the input file for reading
    int fd = open(file_path, O_RDWR);
    char *buffer;
    char c;
    // error in opening the file
    if (fd < 0) {
        perror("Error :");
        //free
        return 1;
    }
    fstat(fd, &st);
    size = st.st_size;
    buffer = (char *)malloc((size + 1) * sizeof(char));
    ssize_t len = read(fd, buffer, size);
    while (len < size) {
        i += len;
        len += read(fd, &buffer[i], size);
    }
    if (len != size) {
        perror("Error :");
        return 1;
    }
    buffer[len] = '\0'; // string closer
    // now iterate over the buffer to find the substrings
    char *insert_pont = &buffer[0];
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *p;
    int i = 0;
    while (buffer[i]) {
        if (!(p = strstr(buffer + i, str1))) {
            fwrite(&buffer[i], sizeof(char), len - i, stdout);
            i = len;
        }
        else {
            fwrite()
        }
    }
}