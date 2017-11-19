//
// Created by Maya Cahana on 11/6/17.
//

#include "hw1_subs.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>


int main(int argc, char **argv)
{
    
    // check the command line arguments
    // assert 1/2 argument
    if (argc > 3 || argc < 2) {
        printf("Error: %s \n",strerror(errno));
        return 1;
    }
    const char *str1 = argv[1];
    const char *str2 = argv[2];
    const char *hw1dir = getenv("HW1DIR");
    const char *hw1tf = getenv("HW1TF");
    struct stat st;
    int size, i = 0;
    char *buffer;
    char *ptr_to_start;

    // in case of the env var not defined - return error
    if (hw1dir == NULL || hw1tf == NULL) {
        printf("Error: %s \n",strerror(errno));
        return 1;
    }
    // combine the input file path
    char *file_path = (char *)malloc((strlen(hw1dir) + strlen(hw1tf) + 2) * sizeof(char));
    // if (!file_path) - malloc didn't succseeded
    if (!file_path) {
        printf("Error: %s \n",strerror(errno));
        return 1;
    }
    // concat the file path
    strcpy(file_path, hw1dir);
    file_path[strlen(hw1dir)] = '/';
    strcpy(&file_path[strlen(hw1dir) + 1], hw1tf);
    // open the input file for reading
    int fd = open(file_path, O_RDWR);
    // error in opening the file
    if (fd < 0) {
        printf("Error: %s \n",strerror(errno));
        close(fd);
        free(file_path);
        return 1;
    }
    fstat(fd, &st);
    size = st.st_size;
    buffer = (char *)malloc((size + 1) * sizeof(char));
    if (!buffer) {
        printf("Error: %s \n",strerror(errno));
        close(fd);
        free(file_path);
        return 1;
    }
    ssize_t tmp = 0;
    while (i < size && buffer+i)
    {
        tmp = read(fd, buffer+i, size-i);
        if (tmp < 0) {
            printf("Error: %s \n",strerror(errno));
            close(fd);
            free(buffer);
            free(file_path);
            return 1;
        }
        i += tmp;
        if (!tmp)
            break;
        }
        
    if (i != size) {
        printf("Error: %s \n",strerror(errno));
        close(fd);
        free(buffer);
        free(file_path);
        return 1;
    }
    // string closer
    buffer[i] = '\0';
    // closing the file
    close(fd);
    if (argc == 2) {
        printf("%.*s",size,buffer);
        free(buffer);
        free(file_path);
        return 0;
    }
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    // saving ptr to the start 
    ptr_to_start = buffer;
    char *c = strstr(buffer,str1);
    while (c != NULL){
        printf("%.*s",(int)((intptr_t)c-(intptr_t)buffer),buffer);
        buffer = c;
        printf("%.*s",(int)len2,str2);
        buffer += len1;
        c = (char *)strstr(buffer,str1);
    }
    printf("%.*s",(int)(size-(intptr_t)c),buffer);
    free(ptr_to_start);
    free(file_path);
    return 0;
    
}
