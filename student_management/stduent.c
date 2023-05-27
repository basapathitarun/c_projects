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
        fprintf(ft,"%d %s %s %d %s \n",(count+100),s.name,s.br,s.sem,s.college);
        count++;
    }
}


void update_fun(FILE *ft) {
        int num,choice;
        int found = 0,i=1;
        int size_first=0, size_end;
        printf("Enter the line number you want to update: ");
        scanf("%d", &num);
        rewind(ft);
        while (fscanf(ft, "%d %s %s %d %[^\n]", &s.usn, s.name, s.br, &s.sem, s.college) != EOF) {
        size_end=ftell(ft);
        printf("first->%d",size_first);
        printf("end->%d\n",size_end);
        fseek(ft,size_first,SEEK_SET);
        if (s.usn == num) {
                   while(i){
                   printf("enter the number:\n1.usn\n2.name\n3.branch\n4.sem\n5.college\n6.nothing\n");
                   scanf("%d",&choice);
                   switch(choice){
                   case 1:
                       printf("enter usn:\n");
                       scanf("%d",&s.usn);
                       break;
                   case 2:
                       printf("enter name :\n");
                       fflush(stdin);
                       gets(s.name);
                       break;

                   case 3:
                       printf("enter branch:\n");
                       fflush(stdin);
                       gets(s.br);
                       break;

                   case 4:
                       printf("enter sem\n");
                       scanf("%d",&s.sem);
                       break;

                   case 5:
                       printf("enter college\n");
                       gets(s.college);
                       break;

                   default:i=0;
                       break;


                   }
                   }

                   found = 1;
                   fprintf(ft, "%d %s %s %d %s\n", s.usn, s.name, s.br, s.sem, s.college);
                   break;
        }
        size_first=size_end;
        }
        if (found) {
        printf("Line %d updated successfully.\n", num);
        } else {
        printf("Line %d not found.\n", num);
        }
    }

void delete_fun(FILE *ft){
        rewind(ft);
        unsigned int size=0;
        int size_first=0,size_end,num;
        printf("enter the usn\n");
        scanf("%d",&num);
        while(fscanf(ft,"%d %s %s %d %[^\n]", &s.usn, s.name, s.br, &s.sem, s.college) != EOF){
        size_end=ftell(ft);
        if(s.usn==num){
                   break;

        }
        size_first=size_end;
        }

        while(fscanf(ft,"%d %s %s %d  %[^\n]",&s.usn,s.name,s.br,&s.sem,s.college)!=EOF){
        size=ftell(ft);
        fseek(ft,size_first,SEEK_SET);
        fprintf(ft,"%d %s %s %d %s \n", s.usn,s.name,s.br,s.sem,s.college);
        size_first=ftell(ft);
        fseek(ft,size,SEEK_SET);
        }
        size_end=ftell(ft);

        fseek(ft, 0, SEEK_END);
        size = ftell(ft);
        ftruncate(fileno(ft), size - (size_end - size_first));
        printf("Line deleted successfully.\n");
}










    //void delete_fun(FILE *ft){
    //    rewind(ft);
    //    FILE *ftemp;
    //    int lineToDelete;
    //    int currentLine = 1;
    //    ftemp=fopen("replace.tmp","w");
    //    if(ftemp==NULL){
    //        printf("file does not exit\n");
    //        exit(0);
    //    }

    //    printf("enter roll number which student delete\n");
    //    scanf("%d",&lineToDelete);
    //    fseek(ft,0,SEEK_CUR);
    //    while(!feof(ft)){
    //        fscanf(ft,"%d %s %s %d  %[^\n]",&s.usn,s.name,s.br,&s.sem,s.college);
    //        if(lineToDelete == s.usn){
    //            continue;
    //        }
    //        else{
    //        }
    //   }
    //    fclose(ft);
    //    fclose(ftemp);

    //    remove("C:\\Qt\\returnfunction\\pointer_in_c\\project1\\student_management\\program.txt");
    //    rename("replace.tmp", "C:\\Qt\\returnfunction\\pointer_in_c\\project1\\student_management\\program.txt");
    //    printf(" deleted successfully.\n put exit for delete on file\n");





    //void delete_fun(FILE *ft) {
    //        int num;
    //        int sem = 0,usn=0;
    //        char name='\0';
    //        char br='\0';
    //        char college='\0';
    //        int found = 0;
    //        int size_first=0, size_end;
    //        printf("Enter the line number you want to update: ");
    //        scanf("%d", &num);
    //        rewind(ft);
    //        while (fscanf(ft, "%d %s %s %d %[^\n]", &s.usn, s.name, s.br, &s.sem, s.college) != EOF) {
    //        size_end=ftell(ft);
    //        printf("first->%d",size_first);
    //        printf("end->%d\n",size_end);
    //        fseek(ft,size_first,SEEK_SET);
    //        if (s.usn == num) {
    //                   found = 1;
    //                   fprintf(ft, "\n%d %s %s %d %s \n", usn, name, br, sem, college);
    //                   break;
    //        }
    //        size_first=size_end;
    //        }
    //        if (found) {
    //        printf("Line %d updated successfully.\n", num);
    //        } else {
    //        printf("Line %d not found.\n", num);
    //        }
    //    }
