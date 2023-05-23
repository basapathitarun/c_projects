struct student{
    int usn;
    char name[20];
    char br[10];
    int sem;
    char college[10];


};
struct student s;

void readcontent(FILE *ft)
{
    rewind(ft);
//    fseek(ft, 0, SEEK_CUR);
    printf("USN NAME BRANCH SEM COLLEGE\n");
    while(fscanf(ft,"%d %s %s %d  %[^\n]",&s.usn,s.name,s.br,&s.sem,s.college)!=EOF){

           printf("%d %s %s %d %s\n",s.usn,s.name,s.br,s.sem,s.college);

        }


}


void write(FILE *ft){
    rewind(ft);
    //initialising variable
    int count=0,init=0;
    //find total nimber of lines
    if(init==0){
        rewind(ft);
           while(fscanf(ft,"%d %s %s %d  %[^\n]",&s.usn,s.name,s.br,&s.sem,s.college)!=EOF)
                   count=count+1;

        init++;
    }
    if(count<100){
        printf("enter student name\n");
        fflush(stdin);
        gets(s.name);
        printf("enter student branch\n");
        gets(s.br);
        printf("enter student sem\n");
        scanf("%d",&s.sem);
        printf("enter the college\n");
        fflush(stdin);
        gets(s.college);
        fprintf(ft,"%d %s %s %d %s\n",(count+100),s.name,s.br,s.sem,s.college);
        count++;
    }
}

void update_fun(FILE *ft){
    int  a,b;
    FILE *fTemp;
    int value;
    printf("enter unique number of student\n");
    scanf("%d",&a);
    rewind(ft);
    fTemp = fopen("replace.tmp", "w");
    fseek(ft,0,SEEK_CUR);
    while(fscanf(ft,"%d %s %s %d  %[^\n]",&s.usn,s.name,s.br,&s.sem,s.college)!=EOF){
        if(a==s.usn){
                printf("which value u are updating\n1.name\n2.branch\n3.cie1\n4.cie2\n5.cie3\n6.nothing\n");
                scanf("%d",&b);
                enum value{name=1,brach,sem,college,nothing};
                switch(b){
            case name:
                printf("enter student name\n");
                fflush(stdin);
                gets(s.name);
                break;

            case brach:
                printf("enter student branch\n");
                fflush(stdin);
                gets(s.br);
                break;
            case sem:
                printf("enter the sem\n");
                scanf("%d",&s.sem);
                break;
            case college:
                printf("enter the college\n");
                gets(s.college);
                break;
            case nothing:exit(0);
            }
          }
        else{
            printf("can not find \n");
            continue;
        }

        fprintf(fTemp,"%d %s %s %d %s\n",s.usn,s.name,s.br,s.sem,s.college);
    }

    fclose(fTemp);
    fclose(ft);
    /* Delete original source file */
    remove("C:\\program.txt");

    /* Rename temporary file as original file */
    rename("replace.tmp", "C:\\program.txt");
    printf("update succesfully\n plase exit from terminal to update on file\n");

}

void delete_fun(FILE *ft){
    rewind(ft);
    FILE *ftemp;
    int lineToDelete;
    int currentLine = 1;
    ftemp=fopen("replace.tmp","w");
    if(ftemp==NULL){
        printf("file does not exit\n");
        exit(0);
    }

    printf("enter roll number which student delete\n");
    scanf("%d",&lineToDelete);
    fseek(ft,0,SEEK_CUR);
    while(!feof(ft)){
        fscanf(ft,"%d %s %s %d  %[^\n]",&s.usn,s.name,s.br,&s.sem,s.college);
        if(lineToDelete == s.usn){
            continue;
        }
        else{
            fprintf(ft,"%d %s %s %d %s\n",s.usn,s.name,s.br,s.sem,s.college);
        }
   }
    fclose(ft);
    fclose(ftemp);

    remove("C:\\program.txt");
    rename("replace.tmp", "C:\\program.txt");
    printf(" deleted successfully.\n put exit for delete on file\n");

}

