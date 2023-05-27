#include<stdio.h>
#include<stdlib.h>
#include "stduent.c"

int main(){

    int num;
    //opening file
    FILE *ft=fopen("C:\\Qt\\returnfunction\\pointer_in_c\\project1\\student_management\\program.txt","r+");

    //checking file exist or not
    if(ft==NULL){
        printf("file does not exit\n");
        exit(0);
    }

    for(;;){
        printf("enter number\n1.inser\n2.display\n3.update\n4.delete\n5.exit\n");
        scanf("%d",&num);
        enum val{insert=1,display,update,delete,back};
        switch(num){
        case insert:
                    write(ft);
                    break;

        case display:
                //printing the file content
                    readcontent(ft);
                    break;


        case update:
                    update_fun(ft);
                    break;

        case delete:
                    delete_fun(ft);
                    break;

        case back: fclose(ft);
                    exit(0);


        }
    }
    return 0;
}
