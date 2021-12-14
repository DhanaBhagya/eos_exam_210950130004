#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    pid_t id;
    char buff[16];
    int fd[2];//fd:file descrpitor
    pipe(fd);//pipe is created
    printf("Before fork\n");
    id = fork();//fork process invoked
    printf("After fork\n");
    if (id == 0)
    {
       open("dictionary.txt",O_RDONLY);
        printf("process 2: Reads the data\n");//child process
        read(fd[0],buff,16);// ssize_t read(int fd, void *buf, size_t count);
        printf("Process 2 :%s\n",buff);
        close(fd[1]); 
    }
    else
    {
        printf("Process 1:writes the data\n");//parent process
        write(fd[1],"monax",16);//ssize_t write(int fd, const void *buf, size_t count);
        printf("Process 1 :sends the data to process2\n");
        close(fd[0]);
    }  

       return 0;
    }
   
    
    
       

