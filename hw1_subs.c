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

int main(int argc, char **argv)
{
    printf("Start");
    // check the command line arguments
    // assert two argument
    if (argc > 3)
    {
        perror("Error : Wrong number of argument");
        return 1;
    }
    
    const char *str1 = argv[1];
    const char *str2 = argv[2];
    const char *hw1dir = getenv("HW1DIR");
    const char *hw1tf = getenv("HW1TF");
    struct stat st;
    int size, i = 0;
    char *buffer;
    // in case of the env var not defined - return error
    if (hw1dir == NULL || hw1tf == NULL)
    {
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
    // error in opening the file
    if (fd < 0)
    {
        perror("Error :");
        //free
        return 1;
    }
    fstat(fd, &st);
    size = st.st_size;
    buffer = (char *)malloc((size + 1) * sizeof(char));
    //ssize_t len = read(fd, buffer, size);
    ssize_t tmp = 0;
    while (i < size)
    {
        tmp = read(fd, buffer[i], size);
        if (tmp < 0)
        {
            close(fd);
            return 1;
        }
        i += tmp;
        if (!tmp)
            break;
    }
    if (i != size)
    {
        perror("Error :");
        return 1;
    }
    buffer[i] = '\0'; // string closer
    close(fd);
    if (argc = 2){
        printf("%.*s",size,buffer);
        return 0;
    }
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    int *c = strstr(buffer,str1);
    while (c != NULL){
        printf("%.*s",(int)(c-(int)buffer),buffer);
        buffer = c;
        printf("%.*s",len2,str2);
        buffer += len1;
        c = strstr(buffer,str1);
    }
    free(buffer);
    free(file_path);
    return 0;
    // const char *original_pattern;
    // char *location;
    // for (original_pattern = str1; location = strstr(buffer, str1); original_pattern = (location + len1))
    // {
    //     cnt++;
    // }
    // size_t const result_len = size + cnt * (str2 - str1);
    // char* result = (char *)malloc(sizeof(char) * (result_len + 1));
    // char* ptr = result;
    // if (result != NULL) {
    //     for (original_pattern = str1; location = strstr(buffer,str1); original_pattern = (location + len1)){
    //         size_t const skip_len = location - original_pattern;//len1 or original_pattern
    //         //
    //         strncpy(ptr,original_pattern,skip_len);
    //         ptr+=skip_len;
    //         strncpy(ptr,str2,len2);
    //         ptr+=len2;

    //     }
    // }
    // fwrite(result, 1, result_len, stdout);
    // // now iterate over the buffer to find the substrings
    // char *insert_pont = &buffer[0];
    // size_t len1 = strlen(str1);
    // size_t len2 = strlen(str2);
    // char *p;
    // p = strstr(buffer[0], str1);
    // // printing the start
    // write (stdout, buffer, p);
    // // iterating on all the occurences
    // buffer = buffer+p;
    // while (p && (p = strstr(buffer[i], str1)))
    // {

    // }
    // // printing until the end
    
}