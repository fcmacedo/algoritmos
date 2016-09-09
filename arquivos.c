#include <stdio.h>

FILE* fileOpen(char[],char[]);

int main(){

    FILE *fp1,*fp2,*fp3;
    char file1[50],file2[50],target[]="destino.txt";

    printf("Informe o nome dos dois aquivos: ");
    scanf("%s %s",file1,file2);

    fp1 = fileOpen(file1,"r");
    fp2 = fileOpen(file2,"r");
    fp3 = fileOpen(target,"w");

    while(feof(fp1)==0){
        fputc(fgetc(fp1),fp3);
    }

    fseek(fp3, -1, SEEK_CUR);

    while(feof(fp2)==0){
        fputc(fgetc(fp2),fp3);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);


    return 0;
}


FILE* fileOpen(char nome[],char modo[]){
    FILE *fp;
    if((fp = fopen(nome,modo)) == NULL){
        printf("Erro ao abrir o arquivo <%s>",nome);
        exit(1);
    }
    return fp;
}
