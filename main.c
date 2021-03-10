#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>


char* substr(const char *src, int m, int n)
{

	int len = n - m;                                            /* keywordleri ve pathleri
                                                                    satir dizisinden almiza yarayan substring fonksiyonumuz...*/

	char *dest = (char*)malloc(sizeof(char) * (len + 1));

	for (int i = m; i < n && (*(src + i) != '\0'); i++)
	{
		*dest = *(src + i);
		dest++;
	}

	*dest = '\0';

	return dest - len;
}

int main()
{
    char filename[50];
	char *test;

	printf("Enter a pmk file\n");                       //kullanicidan pmk ismi alıyoruz.
	scanf("%s",&filename);
	char * new_str ;
	new_str = malloc(strlen(filename)+4);
    new_str[0] = '\0';
    strcat(new_str,filename);
    strcat(new_str,".pmk");
    //char changing[] ;
    char  listee [10][50];
    FILE *fp;
    int bufferLength = 255;                         //identifierlarimiz.
    char satir[bufferLength];
    int substringlength=0;
    char* subs;
    char* dest;
    char* path;
    char slash[10]="/";
    int check;
    int compare1;
     int compare2;
     int compare3;
   bool yildizliif=true;
   bool yildizliifnot=true;
    int ifde_mi=0;
    int ifnot_mi=0;
    bool flag1=false;
    bool flag2=false;
    bool icicemi=false;
int satirlength=0;
    fp = fopen(new_str, "r");
   char cwd[PATH_MAX];
    char kopyacwd[PATH_MAX];
      char kopyaacwd[PATH_MAX];

   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       //printf("Current working dir: %s\n", cwd);
       int i=0;
        while(cwd[i]!='\0')
    {
        if(cwd[i]=='\\')
        {
            cwd[i]='/';
        }
        i++;
    }
    printf("Current working dir: %s\n", cwd);           //current dir basiliyor.
   } else {
       perror("getcwd() error");
       return 1;
   }
     if ((fp) == NULL){
 printf("Dosya okumada hata var");
   }
else{
  while(fgets(satir, bufferLength, fp)) {           //bu dongude dosyayi satir satir okuyoruz...
         int pathlength=0;
         bool hatali=false;

   printf(" %s\n", satir );

    int i;

    for(i=0;i<strlen(satir);++i){
            int result;
    int  begin=0;
    if(isalpha(satir[i]))
        {    begin=i;

             while(isalpha(satir[i])||satir[i]=='_'||isdigit(satir[i])||satir[i]==' '){     //keywordlarimizi bulmak için
                                                                                            //kullanigimiz dongu.
                substringlength++;
                i++;
            }


            dest = substr(satir, begin, begin+substringlength);     //keywordlar için substring fonksiyonumuz kullanilir.
            substringlength=0;

            begin=0;


        }

            if(yildizliif&&yildizliifnot){          //keywordlarin if ifnot durumlarinda kontrolu bu iflerle saglanmistir.
            if((ifde_mi!=2||(ifde_mi==1&&flag1==true))||(ifnot_mi!=2||(ifnot_mi==1&&flag1==true))){
        if(strcmp(dest,"go ")==0||strcmp(dest,"go")==0){
                printf("Keyword %s\n",dest);
                 if(ifde_mi==0&&ifnot_mi==2){
                        printf("Directory can't be changed..\n");
                    continue;
                }
                if(ifde_mi==2&&ifnot_mi==0){
                    printf("Directory can't be changed..\n");
                    continue;
                }


                if(satir[i]=='<'){                          //bu dongude
                    i++;                                    //o satirdaki path alınır.
                    begin=i;

                    while(satir[i]!='>'){


                            substringlength++;
                            i++;

                    }

                    path=substr(satir, begin, begin+substringlength);
                    substringlength=0;

                    pathlength=strlen(path);


                    if(path[0]=='/'||path[pathlength-1]=='/'){              /* hatali yazimlarda programi exit yapiyoruz.*/

                        printf("'(/hi/there) is not allowed!'\n");

                        exit(1);


                    }
                    int yildizmi;
                    yildizmi=strcmp(path,"*");
                    if(yildizmi==0){                        /* 'go <*>' komutunun ust dizine gitmesini saglayan kod.*/



                        chdir("..");
                        printf("Directory is changed:  %s\n",getcwd(cwd, sizeof(cwd)));



                    }


   int b =0;
        if((isalpha(path[0])==0)&&(path[0]!='*')){
            printf("Baslangic karakteri harf olmali ' %c ' ile baslayamazsiniz ", path[0]);
                    exit(0);
                    }

struct stat s;
int err = stat(path, &s);
if(-1 == err) {
    if(ENOENT == errno) {
        /* does not exist */
        if(path[0]=='*'){
            printf("\n");
        }
        else{printf("Boyle bir dizin yok\n");}
    } else {
        perror("stat");
        exit(1);
    }
} else {
    if(S_ISDIR(s.st_mode)) {



        chdir(path);
        printf("Directory is changed:  %s\n",getcwd(cwd, sizeof(cwd)));

        /* it's a dir */
        //printf("var.");
    } else {
        /* exists but is no dir */
    }
}

        }}}}

          if(yildizliif&&yildizliifnot){
        if((ifde_mi!=2||(ifde_mi==1&&flag1==true))||(ifnot_mi!=2||(ifnot_mi==1&&flag1==true))){
         if(strcmp(dest,"make")==0 ||strcmp(dest,"make ")==0){

                printf("Keyword %s\n",dest);
                if(ifde_mi==0&&ifnot_mi==2){
                    //printf("gec burayi..\n");
                    printf("Directory can't be created..\n");
                    continue;
                }
                if(ifde_mi==2&&ifnot_mi==0){

                    printf("Directory can't be created..\n");
                    continue;
                }

                size_t destination_size = sizeof (cwd);
                strncpy(kopyacwd, cwd, destination_size);
                //printf("kopya %s\n",kopyacwd);
//i++;
                if(satir[i]=='<'){
                    i++;
                    begin=i;

                    while(satir[i]!='>'){


                            substringlength++;
                            i++;

                    }

                    path=substr(satir, begin, begin+substringlength);
                    substringlength=0;
                    pathlength=strlen(path);

                       if(path[0]=='/'||path[pathlength-1]=='/'){

                        printf("'(/hi/there) is not allowed!'\n");

                        exit(1);


                    }

                    char* token = strtok(path, "/");

  int b =0;
   while (token != NULL) {
       // printf("%s\n", token);

strcpy(listee[b], token);

        //a[b] = token;
        token = strtok(NULL, "/");
        //printf("Liste[0]: %c \n",listee[b][0]);
        if((isalpha(listee[b][0])==0)&&(listee[b][0]!='*')){
            printf("Baslangic karakteri harf olmali '%c' ile baslayamaz.",listee[b][0]); //hata mesajlari bastirilir.
                    exit(0);

                    }
        b++;
    }
     //compare3=strcmp(listee[0][0],"*");

bool yildiz ;
  compare1=strcmp(listee[0],"*");
  if(compare1!=0){

    yildiz==false;
  }

  compare2=strcmp(listee[1],"*");

   if(compare1!=0&& compare2==0){

        printf("'(hi/*/there) is not allowed!'\n");

        exit(1);

    }
                int indeks=0;
                int a=0;

               while(indeks<b){

                    if(compare1==0&&indeks==0&& hatali==false){

                        chdir("..");
                         printf("%s \n",getcwd(cwd, sizeof(cwd)));

                            indeks++;
                    }
                if(compare2==0&&indeks==1&& hatali==false){



                        chdir("..");
                         printf("%s \n",getcwd(cwd, sizeof(cwd)));

                            indeks++;
                    }


if(!hatali){

                            char* dirname =listee[indeks];
                                 check = mkdir(dirname);

                                // check if directory is created or not
                                if (!check)
                                    printf("Directory created\n");
                                else {
                                    printf("Directory is created before!\n");
                                        strcat(cwd,slash);
                        strcat(cwd,dirname);
                                chdir(cwd);
                            //token = strtok(NULL, "/");
                            indeks++;
                                    continue;
                                    //exit(1);
                                    getch();

                                system("dir");
                                getch();

                                }

                            strcat(cwd,slash);      //make komutunda currenta dir ekleme işlemi.
                strcat(cwd,dirname);
                    chdir(cwd);

                    printf("%s\n",getcwd(cwd, sizeof(cwd)));

                //listee[indeks];

                    indeks++;
                    yildiz=true;
                    //hatali=true;
               }
                //printf("%d",indeks);
               }

                indeks==0;
                b=0;

    //int b =0;
    //while(b<a){

        chdir(kopyacwd);
        //b++;
    //}
    printf("Current Directory: %s\n",getcwd(cwd, sizeof(cwd)));

//printf("%d",a);

                }

        }}}

        if(ifde_mi!=2||(ifde_mi==1&&flag1==true)||(ifde_mi!=2&&flag1==false)){
        if(strcmp(dest,"if")==0||strcmp(dest,"if ")==0){
                printf("Keyword %s\n",dest);

                  if(satir[i]=='<'){
                    i++;
                    begin=i;

                    while(satir[i]!='>'){


                            substringlength++;
                            i++;

                    }
                    path=substr(satir, begin, begin+substringlength);
                    substringlength=0;
                    pathlength=strlen(path);


                    if(path[0]=='/'||path[pathlength-1]=='/'){

                        printf("'(/hi/there) or (hi/there/) is not allowed!'\n");

                        exit(1);


                    }
                  //  printf("%s pathh\n",path);

                    int d;
                    if(strcmp(path,"*")==0){
                            //printf("girdi..");
                             size_t destination_size = sizeof (cwd);
                    strncpy(kopyaacwd, cwd, destination_size);
                        //printf("kopya %s\n",kopyaacwd);
                printf("Current Directory: %s\n",getcwd(cwd, sizeof(cwd)));

                        //chdir(kopyaacwd);
                        int i=0;
                        int slashsayi=0;
                        int chdirsayi;

                       if (getcwd(cwd, sizeof(cwd)) != NULL) {
                           //printf("Current working dir: %s\n", cwd);
                           int i=0;
                            while(cwd[i]!='\0')                 /*if keywordunde üst dizinin varligini kontrol
                                                                    ettigimiz kod bolumu*/
                        {
                            if(cwd[i]=='\\')
                            {
                                slashsayi++;
                            }
                            i++;
                        }
                        //printf("%d\n",slashsayi);
                        chdirsayi=slashsayi-1;


                        if(chdirsayi>0){

                            yildizliif=true;            //go ve make keywordlerine girisi kontrol icin kullanıcak bool yapiları.
                            ifde_mi=1;

                        }
                        else{

                            yildizliif=false;
                            ifde_mi=2;



                        }

                       }


                    }

  //char* token = strtok(path, "/");

    int b =0;
    //printf("Liste[0]: %c \n",path[0]);
        if((isalpha(path[0])==0)&&(path[0]!='*')){
            printf("Baslangic karakteri harf olmali ' %c ' ile baslayamazsiniz ", path[0]);
                    exit(0);
                    }


 struct stat s;
int err = stat(path, &s);
if(ifde_mi!=1){                                 /*pathin varligini kontrol eden if-else yapisi...*/
if(-1 == err) {
    if(ENOENT == errno) {
        /* does not exist */
        //printf("ife girilemedi\n");
        ifde_mi=2;
    } else {
        perror("stat");
        exit(1);
    }
} else {

    //ifde_mi=true;
    if(S_ISDIR(s.st_mode)) {

            if(icicemi&&ifde_mi==2){

                ifde_mi=2;


            }
 else{
        ifde_mi=1;

        /* it's a dir */

    }}
    else {
        /* exists but is no dir */
    }
}}

        }

        }}

          if(strcmp(dest,"ifnot")==0||strcmp(dest,"ifnot ")==0){
                printf("Keyword:  %s\n",dest);
                if(satir[i]=='<'){
                    i++;
                    begin=i;

                    while(satir[i]!='>'){


                            substringlength++;
                            i++;

                    }
                    path=substr(satir, begin, begin+substringlength);
                    substringlength=0;
                    pathlength=strlen(path);

                    if(path[0]=='/'||path[pathlength-1]=='/'){

                       printf("'(/hi/there) or (hi/there/) is not allowed!'\n");

                        exit(1);

                    }

                     if(strcmp(path,"*")==0){
                            //printf("girdi..");
                             size_t destination_size = sizeof (cwd);
                    strncpy(kopyaacwd, cwd, destination_size);
                        //printf("kopya %s\n",kopyaacwd);
                printf("Current Directory: %s\n",getcwd(cwd, sizeof(cwd)));

                        //chdir(kopyaacwd);
                        int i=0;
                        int slashsayi=0;
                        int chdirsayi;

                       if (getcwd(cwd, sizeof(cwd)) != NULL) {
                           //printf("Current working dir: %s\n", cwd);
                           int i=0;
                            while(cwd[i]!='\0')
                        {
                            if(cwd[i]=='\\')
                            {
                                slashsayi++;
                            }
                            i++;
                        }
                        //printf("%d\n",slashsayi);
                        chdirsayi=slashsayi-1;
                        //printf("bu kadar chdir yapabilir..%d\n",chdirsayi);

                        if(chdirsayi>0){

                            yildizliifnot=false;
                            ifnot_mi=1;

                        }
                        else{

                            yildizliif=true;
                            ifnot_mi=2;

                        }

                       }

                    }

                    //printf("%s pathh\n",path);

  //char* token = strtok(path, "/");
  int b =0;

    //printf("Liste[0]: %c \n",path[0]);
        if((isalpha(path[0])==0)&&(path[0]!='*')){
            printf("Baslangic karakteri harf olmali ' %c ' ile baslayamazsiniz ", path[0]);
                    exit(0);
                    }


 struct stat s;
int err = stat(path, &s);
if(-1 == err) {
    if(ENOENT == errno) {
        /* does not exist */

        ifnot_mi=1;
    } else {
        perror("stat");

        exit(1);
    }
} else {

    //ifde_mi=true;
    if(S_ISDIR(s.st_mode)) {
        ifnot_mi=2;

    } else {
        /* exists but is no dir */
    }
}
        }
        }

        if((ifnot_mi==1&&satir[i]=='{')||(ifde_mi==1&&satir[i]=='{')){
            flag1=true;
            if(ifnot_mi==1){
                //printf("ifnota girdi!!!");
            }
            if(ifde_mi==1){
                //printf("ife girdi...\n");
            }

        }

         if((ifde_mi==1||ifde_mi==2&&satir[i]=='}')||(ifnot_mi==1||ifnot_mi==2&&satir[i]=='}')){
            flag1=false;
            ifde_mi=0;
            ifnot_mi=0;

            //printf("iften/ifnottan ciktik\n");
        }
            satirlength ++;

        if(satir[i]=='{'){                              //if ve ifnotta parantez durumu kontrolleri.


       flag2=true;
        }

        if(satir[i]=='}'&&flag2){
            //printf("if bitimi\n");
            ifde_mi=0;
            ifnot_mi=0;
            flag2=false;
            yildizliif=true;
            yildizliifnot=true;


        }
         if(satir[i]==';'&&flag1==false&&flag2==false){
            //printf("if bitimi ...\n");
            //ifde_mi=0;
            flag2=false;
            ifde_mi=0;
            ifnot_mi=0;
            yildizliif=true;
            yildizliifnot=true;


        }

         dest=" ";

        }


        }
  }

  fclose(fp);
   return 0;
}
