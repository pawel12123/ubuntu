#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_program_name(char* str)
{
    int last_backslash = 0;
    int i = 0;
    char *name = (char *) malloc(3);
    //Determine where the last path delimiter '\' is to find program name.
    while(str[i] != '\0'){
        if(str[i] == '\\'){
            last_backslash = i;
        }
        i++;
    }
    int startStr = 0;
    for(int j = last_backslash+1; j < i; j++){
        name[startStr] = str[j];
        startStr++;
        if(i - j == 1){
            name[startStr] = '\0';
        }
    }
    return name;
}


int find_primes1(int upper)
{


}

int find_primes2(int lower, int upper)
{


}

int main(int argc, char* argv[]){
    //Calls function to find program name.
    char* name = get_program_name(argv[0]);

    printf("Name of Prog: %s\n",name);

    //Check arguments to see if there is enough arguments to proceed or generates an error.
    if(argc < 2){
        printf("%s launched with no argument.\nProper usage: prog m [n]\n",name);
    }
    else if(argc == 2){
        find_primes1(atoi(argv[1]));
    }
    else if(argc == 3){
        if(atoi(argv[1]) <= atoi(argv[2])){
            find_primes2(atoi(argv[1]),atoi(argv[2]));
        }
        else{
            find_primes2(atoi(argv[2]),atoi(argv[1]));
        }
    }
    else{
        printf("%d\n",argc);
    }
}
