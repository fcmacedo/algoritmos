#include <stdio.h>

//prototipo
FILE* fileOpen(char[],char[]);

int main(){

    FILE *fp1,*fp2,*fp3;
    char file1[50],file2[50],target[]="target.txt";

    printf("Informe o nome dos dois aquivos: ");
    scanf("%s %s",file1,file2);

    fp1 = fileOpen(file1,"r");
    fp2 = fileOpen(file2,"r");
    fp3 = fileOpen(target,"w");

    while(feof(fp1)==0){
        fputc(fgetc(fp1),fp3);
    }

    int pos = ftell(fp3) - 1;
    printf("POS: %d",pos);

    fseek(fp3, 0, SEEK_END); //leva para o inicio
    //fseek(fp3, 10, SEEK_SET); //leva para o inicio
    char ch;
    while(feof(fp2)==0){
        if((ch = fgetc(fp2))!=EOF)
            fputc(ch,fp3);
    }

    fseek(fp3, pos, SEEK_SET);

    fputc('W',fp3);

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
