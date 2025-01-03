#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void plus();
int menu();
void mines();
void multiply();
void divide();
//struct Leadrboard : untuk menampung nama dan poin yang akan disimpan dalam file txt
typedef struct{
    char nama[20];
    int poin;
}Leaderboard;
char name[20];

int main() {
    printf("please input your name: ");
    scanf("%s",&name);
    menu();
    return 0;
}
//menu() : menampilkan menu dan mengarahkan ke fungsi atau fitur yang diinginkan pengguna(plus,mines,multiply,divide,exit).
int menu(){
    system("cls");
    int a;
    printf("welcome to math quiz\nselect operator:\n1.plus\n2.mines\n3.multiply\n4.divided\nclick x to exit\n");
    scanf("%d",&a);
    if(a==1){
        plus();
    }
    else if(a==2){
        mines();
    }
    else if(a==3){
        multiply();
    }
    else if(a==4){
        divide();
    }
    else{
        system("cls");
        printf("Thankyou for playing!");
        return 0;
    }
}

//Leaderboards() : menyimpan poin setiap orang ke dalam file txt ketika terjadi game over(nyawa habis). 
//Setelah nama dan poin disimpan, poin semua orang dalam teks txt akan di sorting dan akan ditampilkan 5 perolehan poin tertinggi beserta namanya.
void Leaderboards(const char *filename, const char *nama, const int poin){
    Leaderboard entry[100];
    int e = 0;

    FILE *fp;
    fp = fopen(filename,"r");
    if(fp != NULL){
        while(fscanf(fp,"%s %d",entry[e].nama,&entry[e].poin) == 2){
            e++;
        }
    }

    strcpy(entry[e].nama,nama);
    entry[e].poin = poin;
    e++;
    int i,j;
    //sorting poin
    for(i = 0; i< e-1; i++){
        for(j = i+1;j<e;j++){
            if(entry[i].poin < entry[j].poin){
                Leaderboard temp = entry[i];
                entry[i] = entry[j];
                entry[j] = temp;
            }
        }
    }

    fp = fopen(filename,"w");
    for(i=0;i<e;i++){
        fprintf(fp,"%s %d\n",entry[i].nama,entry[i].poin);
    }
    fclose(fp);
    //menanpilkan leaderboard
    printf("\n=== Top 5 Leaderboard ===\n");
    for ( i = 0; i < e && i < 5; i++) { 
        printf("%d. %s - %d points\n", i + 1, entry[i].nama, entry[i].poin);
    printf("=========================\n");
    }
}
//plus() : sebuah fungsi yang akan berjalan ketika menu plus dipilih dan akan memberikan pertanyaan pertambahan 2 angka acak. 
//Didalamnya terdapat tingkatan level dari 1 hingga 3 dimana level 1 angka nya akan berkisar dari 0 - 10, level 2 berkisar dari 0 - 100, level 3 berkisar dari 0 - 1000. 
//level 1 masing-masing jawaban benar akan bernilai 1, level 2 bernilai 2 dan level 3 bernilai 5.
void plus(){
    system("cls");
    int level,num1=0,num2=0,point=0,lives=3,answer,response;
    printf("\nwelcome to plus quiz\npilih level:\n1.easy\n2.medium\n3.hard\n");
    scanf("%d",&level);
    if(level==1){
        while(lives!=0){
            system("cls");
            num1=rand() % 11;
            num2=rand() % 11;
            printf("\npoin: %d\t\tlives: %d\n\n",point,lives);
            printf("%d  +  %d =  ",num1,num2);
            scanf("%d", &answer);
            if(answer==num1+num2){
                point+=1;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboardPlus.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
    if(level==2){
        while(lives!=0){
            system("cls");
            num1=rand() % 101;
            num2=rand() % 101;
            printf("\npoin: %d\t\tlives: %d\n\n",point,lives);
            printf("%d  +  %d =  ",num1,num2);
            scanf("%d", &answer);
            if(answer==num1+num2){
                point+=2;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboardPlus.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
    if(level==3){
        while(lives!=0){
            system("cls");
            num1=rand() % 1001;
            num2=rand() % 1001;
            printf("\npoin: %d\t\tlives: %d\n\n",point,lives);
            printf("%d  +  %d =  ",num1,num2);
            scanf("%d", &answer);
            if(answer==num1+num2){
                point+=5;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboardPlus.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
}
//mines() : sebuah fungsi yang akan berjalan ketika menu mines dipilih dan akan memberikan pertanyaan pertambahan 2 angka acak. 
//Didalamnya terdapat tingkatan level dari 1 hingga 3 dimana level 1 angka nya akan berkisar dari 0 - 10, level 2 berkisar dari 0 - 100, level 3 berkisar dari 0 - 1000. 
//level 1 masing-masing jawaban benar akan bernilai 1, level 2 bernilai 2 dan level 3 bernilai 5. 

void mines(){
    system("cls");
    int level,num1,num2,point=0,lives=3,answer,response;
    printf("welcome to mines quiz\npilih level:\n1.easy\n2.medium\n3.hard\n");
    scanf("%d",&level);
    if(level==1){
        while(lives!=0){
            system("cls");
            num1=rand() % 11;
            num2=rand() % 11;
            printf("\npoin: %d\t\tlives: %d\n\n",point,lives);
            printf("%d  -  %d =  ",num1,num2);
            scanf("%d", &answer);
            if(answer==num1-num2){
                point+=1;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");    
        Leaderboards("leaderboardMinus.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
    if(level==2){
        while(lives!=0){
            system("cls");
            num1=rand() % 101;
            num2=rand() % 101;
            printf("\npoin: %d\t\tlives: %d\n\n",point,lives);
            printf("%d  -  %d =  ",num1,num2);
            scanf("%d", &answer);
            if(answer==num1-num2){
                point+=2;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboardMinus.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
    if(level==3){
        while(lives!=0){
            system("cls");
            num1=rand() % 1001;
            num2=rand() % 1001;
            printf("\npoin: %d\t\tlives: %d\n\n",point,lives);
            printf("%d  -  %d =  ",num1,num2);
            scanf("%d", &answer);
            if(answer==num1-num2){
                point+=5;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboardMinus.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
}
//multiply() : sebuah fungsi yang akan berjalan ketika menu multiply dipilih dan akan memberikan pertanyaan pertambahan 2 angka acak. 
//Didalamnya terdapat tingkatan level dari 1 hingga 3 dimana level 1 angka nya akan berkisar dari 0 - 10, level 2 berkisar dari 0 - 100, level 3 berkisar dari 0 - 1000. 
//level 1 masing-masing jawaban benar akan bernilai 1, level 2 bernilai 2 dan level 3 bernilai 5.
void multiply(){
    system("cls");
    int level,num1,num2,point=0,lives=3,answer,response;
    printf("welcome to multiply quiz\npilih level:\n1.easy\n2.medium\n3.hard\n");
    scanf("%d",&level);
    if(level==1){
        while(lives!=0){
            system("cls");
            num1=rand() % 11;
            num2=rand() % 11;
            printf("\npoin: %d\t\tlives: %d\n\n",point,lives);
            printf("%d  x  %d =  ",num1,num2);
            scanf("%d", &answer);
            if(answer==num1*num2){
                point+=1;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboardMultiply.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
    if(level==2){
        while(lives!=0){
            system("cls");
            num1=rand() % 101;
            num2=rand() % 101;
            printf("\npoin: %d\t\tlives: %d\n\n",point,lives);
            printf("%d  x  %d =  ",num1,num2);
            scanf("%d", &answer);
            if(answer==num1*num2){
                point+=2;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboardMultiply.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
    if(level==3){
        while(lives!=0){
            system("cls");
            num1=rand() % 1001;
            num2=rand() % 1001;
            printf("\npoin: %d\t\tlives: %d\n\n",point,lives);
            printf("%d  x  %d =  ",num1,num2);
            scanf("%d", &answer);
            if(answer==num1*num2){
                point+=5;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboardMultiply.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
}
//divide() : sebuah fungsi yang akan berjalan ketika menu divide dipilih dan akan memberikan pertanyaan pertambahan 2 angka acak. 
//Didalamnya terdapat tingkatan level dari 1 hingga 3 dimana level 1 angka nya akan berkisar dari 1 - 10, level 2 berkisar dari 1 - 100, level 3 berkisar dari 1 - 1000. 
//level 1 masing-masing jawaban benar akan bernilai 1, level 2 bernilai 2 dan level 3 bernilai 5.
void divide(){
    system("cls");
    int level,point=0,lives=3,response,num1,num2;
    int answer,hasil;
    printf("welcome to divide quiz\npilih level:\n1.easy\n2.medium\n3.hard\n");
    scanf("%d",&level);
    if(level==1){
        while(lives!=0){
            system("cls");
            num1=(rand() % 10) +1;
            num2=(rand() % 10)+1;
            printf("\npoin: %d\t\tlives: %d\t\tBulatkan ke bawah!!\n\n",point,lives);
            printf("%d  /  %d =  ",num1,num2);
            scanf("%d", &answer);
            hasil=num1/num2;
            if(answer==hasil){
                point+=1;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboarddivide.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
    if(level==2){
        while(lives!=0){
            system("cls");
            num1=(rand() % 100)+1;
            num2=(rand() % 100)+1;
            printf("\npoin: %d\t\tlives: %d\t\tBulatkan ke bawah!!\n\n",point,lives);
            printf("%d  /  %d =  ",num1,num2);
            scanf("%d", &answer);
            hasil=num1/num2;
            if(answer==hasil){
                point+=2;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboarddivide.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
    if(level==3){
        while(lives!=0){
            system("cls");
            num1=(rand() % 1000)+1;
            num2=(rand() % 1000)+1;
            printf("\npoin: %d\t\tlives: %d\t\tBulatkan ke bawah!!\n\n",point,lives);
            printf("%d  /  %d =  ",num1,num2);
            scanf("%d", &answer);
            hasil=num1/num2;
            if(answer==hasil){
                point+=5;
            }else{
                lives-=1;
            }
        }
        printf("game over\nexit(0)\tback to menu(1): ");
        Leaderboards("leaderboarddivide.txt",name,point);
        scanf("%d",&response);
        if(response==1){
            menu();
        }else{
            printf("\\(^-^)/ bye...");
        }
    }
}
