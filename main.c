#include <stdio.h>
#include <stdlib.h>

int minusSignHandler(char *ptr_sign) {
    int counter = 0; 
    while((int)*ptr_sign == (int)'-') {
        counter++;
        ptr_sign++;
    }
    return counter;
}

int calculator(int a, char *operator, int b)
{
    int answer = 0;

    switch (*operator) {
        case '+':
            return answer = (a) + (b);
            break;
        
        case '*':
            return answer = (a) * (b);
            break;

        case '/':
            if(b == 0) {
                printf("Error! You can`t divide by zero!");
                break;
            }
            return answer = (a) / (b);
            break;
        
        case '-':
            answer = minusSignHandler(operator)%2 ? (a) - (b) : (a) + (b);
            return answer;
            break;
    }
    return answer;
}

int parseArguments(char ** argv, char *targetArgv) {
    int temp = 0, i = 0;
    char *args;
    char minusSign = '-';
    char zero = '0'; /* we need it for convertion char -> int */
    int isNegative = 0; /* false: 0 | true: 1 */

    for(i = 1; argv[i] != NULL; i++) {
        if(argv[i] == targetArgv){
            for(args = argv[i]; *args != '\0'; ++args) {
                
                if((int)*argv[i] == minusSign) {
                    if((minusSignHandler(argv[i]))) {
                        if((minusSignHandler(argv[i]))%2) {
                            isNegative = 1;
                        }
                        args += (minusSignHandler(args));
                    }
                }
                
                if(temp != 0) {
                    temp = (temp * 10) + ((int)*args - (int)zero);
                } else {
                    temp = (int)*args - (int)zero;
                }
            }
        }
    }
    if(isNegative) {
        temp = temp * -1;
    }

    return temp;
}

int main(int argc, char* argv[])
{
    double a = 0.0;
    double b = 0.0;

    if(argc < 4) {
        printf("Too few arguments! You passed %d arguments.\n", argc);
    } else if (argc > 4) {
        printf("Too many arguments! You passed %d arguments.\n", argc);
    } else {

        a = parseArguments(argv, argv[1]);
        b = parseArguments(argv, argv[3]);

        printf("\nanswer: %d\n", calculator(a, argv[2], b));
    }

    return 0;
}
