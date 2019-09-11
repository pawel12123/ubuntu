#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//JUST NEED TO ADD 4.4 and 4.5 EXTRA CREDIT!


int prime(int n){
    int valid = 0;

    if( n == 2){
        return valid;
    }
    else{
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0){
                valid = 1;
                break;
            }
        }
    }
    return valid;
}

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

void find_primes1(char* name, int amount)
{
    int count = 0;
    int primes[40000];
    if(amount < 1){
        printf("%s's argument is not a strictly positive integer.",name);
    }
    else{
        int i = 2;
        while(count < amount){
            if(prime(i) == 0){
                primes[count] = i;
                count++;
            }
        i++;
        }
        //Addresses the case that the user asks for the first prime number
        if(amount == 1){
            printf("The first prime number is ", primes[0]);
        }
        //Converts output message from "There are 4", to "There re four" as long as number is below 20.
        else if(amount < 20){
            char* numList[20] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","eleven","twelve", "thirteen", "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
            printf("The first %s prime numbers are: ", numList[amount-1]);
        }

        else{
            printf("The first %d prime numbers are: ",count);
        }
        for(int i = 0; i < count; i++){
            printf("%d", primes[i]);
            if(count - i == 1){
                printf(".");
            }
            else{
            printf(",");
            }
        }
    }
}

void find_primes2(char* name, int lower, int upper, int pos)
{
    if(lower < 1 && upper < 1){
        printf("Both of %s's arguments aren't strictly positive integers", name);
    }
    else if(lower < 1){
        if(pos == 1){
            printf("%s's first argument is not a strictly positive integer.\n",name);
        }
        else{
            printf("%s's second argument is not a strictly positive integer.\n",name);
        }
    }
    else if (upper < 1){
        if(pos == 1){
            printf("%s's second argument is not a strictly positive integer.\n",name);
        }
        else{
            printf("%s's first argument is not a strictly positive integer.\n",name);
        }
    }
    else{
        int count = 0;
        int primes[40000];

        for(int i = lower; i < upper; i++){
            if(prime(i) == 0){
                primes[count] = i;
                count++;
            }
        }
        if(count < 1){
            printf("There is no prime number between %d and %d.", lower, upper);

        }
        else if(count == 1){
            printf("There is only one prime number between %d and %d: %d ", lower, upper, primes[0]);
        }
        else if(count > 1 && count < 20){
            char* numList[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","eleven","twelve", "thirteen", "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
            printf("There are %s prime numbers between %d and %d: ",numList[count-1], lower, upper);
        }
        else{
            printf("There are %d prime numbers between %d and %d: ",count, lower, upper);
        }
        if(count > 1){
            for(int i = 0; i < count; i++){
                printf("%d", primes[i]);
                if(count - i == 1){
                    printf(".");
                }
                else{
                    printf(", ");
                }
            }
        }
    }
}

int main(int argc, char* argv[]){
    //Calls function to find program name.
    char* name = get_program_name(argv[0]);

    //Check arguments to see if there is enough arguments to proceed or generates an error.
    if(argc < 2){
        printf("%s launched with no argument.\nProper usage: prog m [n]\n",name);
    }
    else if(argc == 2){
        find_primes1(name,atoi(argv[1]));
    }
    else if(argc == 3){
        if(atoi(argv[1]) <= atoi(argv[2])){
            find_primes2(name,atoi(argv[1]),atoi(argv[2]),1);
        }
        else{
            find_primes2(name,atoi(argv[2]),atoi(argv[1]),2);
        }
    }
    else{
        printf("%s launched with too many arguments.\nProper usage: prog m [n]\n",name);
    }
}
