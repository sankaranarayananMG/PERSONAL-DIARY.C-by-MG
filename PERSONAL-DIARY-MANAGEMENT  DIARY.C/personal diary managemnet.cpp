#include<stdio.h>
#include<string.h>
#include<stdlib.h>

Void welcome_message();
Int insert();
Int append();
Int view();

Int main()
{
    FILE *fp;
    Char press;
    Int num;
First:
    Printf("\n\n---- Press ----- operation ------\n\n");
    Printf("     '+' ------ add new note     \n");
    Printf("     'a' ------ append new note     \n");
    Printf("     'v' ------ View Previous     \n");
    Printf("     'e' ------ Exit Program     \n\n");
    Printf("-------------------------------\n\n");

While(1)
{
    Scanf("%c",&press);

    If (press == '+'){
        Insert();
        Printf("Press '1' for continue\n'0' for Exit\n");
        Scanf("%d", &num);
        If (num == 1){
            Goto First;
        }
        Else{
            Break;
        }
    }
    Else if (press == 'a'){
        Append();
        Printf("Press '1' for continue\n'0' for Exit\n");
        Scanf("%d", &num);
        If (num == 1){
            Goto First;
        }
        Else{
            Break;
        }
    }
    Else if (press == 'v'){
        View();
        Printf("Press '1' for continue\n'0' for Exit\n");
        Scanf("%d", &num);
        If (num == 1){
            Goto First;
        }
        Else{
            Break;
        }
    }
    Else if (press == 'e'){
        Return 0;
    }
    Else{
        Printf("Please press correct key.\n");
    }
}
    Return 0;
}

Void welcome_message() {
    Printf("---***---***----***----***----***---\n\n");
    Printf("|     Welcome to our Diary    '|\n\n");
    Printf("---***---***----***----***---***---\n\n");
}

Int insert(){
    FILE *fp;
    Char note[2000], date[20] ;
    Welcome_message();
    Printf("Enter date of your note : ");
    Scanf("%s", date);
    //printf("%s",date);
    Printf("\n");
    Printf("Just write your note from here….\n--'>");
    Scanf(" %[^\n]s",note);
    Fp = fopen("diary.txt", "w");
    Fprintf(fp, date);
    Fprintf(fp, "\n");
    Fprintf(fp, note);
    Fprintf(fp, "\n\n");
    Printf("\nSuccessfully Copied…..:)\n");
    Fclose(fp);
    Return 0;
}

Int append() {
    FILE *fp;
    Char note[2000], date[20] ;
    Welcome_message();
    Printf("Enter date of your note : ");
    Scanf("%s", date);
    //printf("%s",date);
    Printf("\n");
    Printf("Just write your note from here….\n--'>");
    Scanf(" %[^\n]s", note);
    Fp = fopen("diary.txt", "a");
    Fprintf(fp, date);
    Fprintf(fp, "\n");
    Fprintf(fp, note);
    Fprintf(fp, "\n\n");
    Printf("\nSuccessfully Copied…..:)\n");
    Fclose(fp);
    Return 0;
}

Int view() {
    FILE *fp;
    Char ch;
    Fp = fopen("diary.txt", "r");
    If (fp == NULL){
        Perror("Error while opening the file.\n");
        Exit(EXIT_FAILURE);
    }
    Printf("\nYour previous note : \n\n");
    Printf("===============================================================================\n");

    While( ( ch = fgetc(fp) ) != EOF ){
        Printf("%c", ch);
    }
    Printf("\n");
    Printf("===============================================================================\n");
    Fclose(fp);
    Return 0;
}
