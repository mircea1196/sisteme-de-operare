#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wc(char* file_path, char* word){
    FILE *fp;
    int count = 0;
    int ch, len;

    if(NULL==(fp=fopen(file_path, "r")))
        return -1;
    len = strlen(word);
    for(;;){
        int i;
        if(EOF==(ch=fgetc(fp))) break;
        if((char)ch != *word) continue;
        for(i=1;i<len;++i){
            if(EOF==(ch = fgetc(fp))) goto end;
            if((char)ch != word[i]){
                fseek(fp, 1-i, SEEK_CUR);
                goto next;
            }
        }
        ++count;
        next: ;
    }
end:
    fclose(fp);
    return count;
}

int main(){//testestest : count 2
    char key[254];
    scanf("%s", key); // the string I am searching for
    int wordcount = 0;

    wordcount = wc("input.txt", key);
    printf("%d",wordcount);
    printf("\n");
    return 0;
}

