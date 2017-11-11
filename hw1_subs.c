//
// Created by Maya Cahana on 11/6/17.
//

#include "hw1_subs.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char **argv) {
    printf("Start");
    // check the command line arguments
    // assert two argument
    if (argc != 3) {
        return 1;
    }
    const char *hw1dir = getenv("HW1DIR");
    const char *hw1tf = getenv("HW1TF");
    // in case of the env var not defined - return error
    if (hw1dir == NULL || hw1tf == NULL) {
        return 1;
    }
    // combine the input file path
    size_t len1 = strlen(hw1dir);
    size_t len2 = strlen(hw1tf);
    char *file_path = (char *) malloc((len1 + len2 + 2)*sizeof(char));
    // if (!file_path)
    strcpy(file_path, hw1dir);
    file_path[len1] = '/';
//    strcpy(&file_path[len1 + 1], hw1tf);
    // open the input file for reading
    int fd = open(file_path, O_RDWR);
    char *buffer;
    char c;
    // error in opening the file
    if (fd < 0) {
        printf("error open the file");
        //free
        return 1;
    }
//
//    // reading the file
//    fseek(fd, 0, SEEK_END);
//    long file_size = ftell(fd);
//    fseek(fd, 0, SEEK_SET);
//    buffer = malloc(file_size * sizeof(char));
//    size_t n = 0;
//    while ((c = fgetc(fd)) != EOF) {
//        buffer[n++] = (char) c;
//    }
//
//    buffer[n] = '\0';
    struct stat st;
    fstat(fd, &st);
    int size = st.st_size, i=0;
    buffer = (char *)malloc((size + 1) * sizeof(char));
    ssize_t len = read(fd,buffer,size);
    while (len < size) {
        
        len += read(fd,buffer,size);
    }
    if (len < 0){
        printf("Error reading from file");
        return 1;
    }
    buffer[len] = '\0'; // string closer
    // now iterate over the buffer to find the substrings


}