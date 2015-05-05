//
//  main.c
//  Adam
//
//  Created by Abegael Jackson on 2015-05-05.
//  Copyright (c) 2015 Abegael Jackson. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    struct teenager {
        char *questionTeenager;
        char *yellAtTeenager;
        char *addressTeenager;
        char *everythingElse;
    };
    
    typedef struct teenager Teenager;
    
    Teenager Adam;
    Adam.questionTeenager = "Sure";
    Adam.yellAtTeenager = "Whoa, chill out!";
    Adam.addressTeenager = "Fine. Be that way!";
    Adam.everythingElse = "Whatever";
    
    while (1) {
        char conversationInput[256];
        printf("You say: ");
        scanf("%[^\n]", conversationInput);
        fpurge(stdin);
        
        // check for lower case (if time put this in it's own function)
        int i = 0;
        int isAllUpperCase = 1;
        
        while (conversationInput[i] != '\0') {
            if (conversationInput[i] >= 'a' && conversationInput[i] <= 'z') {
                isAllUpperCase = 0;
                break;
            }
            i++;
        }
        
        // check for empty input
        if (strlen(conversationInput) == 0) {
            printf("Adam says: %s\n", Adam.addressTeenager);
        }
        else if (strchr(conversationInput, '?') != NULL) {
            printf("Adam says: %s\n", Adam.questionTeenager); // "Sure"
        }
        else if (isAllUpperCase == 1) {
            printf("Adam says: %s\n", Adam.yellAtTeenager ); // "Whoa, chill out"
        }
        else if (strcmp(conversationInput, "exit") == 0){
            break;
        }
        else {
            printf("Adam says: %s\n", Adam.everythingElse); // "Whatever"
        }
    
        
        strncpy(conversationInput, "", strlen(conversationInput)); // clear the output
    }
    return 0;
}



