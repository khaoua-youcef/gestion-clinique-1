#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sqlite3.h>
#include"DATA_BASE.h"
bool cree_tble (sqlite3*X ){
    char *errmsg=NULL;
  const char *sql ="CREATE TABLE IF NOT EXISTS patiant("
  " tickets INTEGER PRIMARY KEY AUTOINCREMENT,"  
  "nom TEXT ,"
  "age INTEGER ,"
  "sex TEXT  );";
   int fl =sqlite3_exec(X,sql,NULL,0,&errmsg);
   if (fl==SQLITE_OK){
    return true ;
   }else{
    printf("l erreur : %s \n",errmsg);
    sqlite3_free(errmsg);
    return false ;
   }
}
int main(){
    bool  MN ;
sqlite3 *db;
 char *errmsg=NULL;
int rc = sqlite3_open("fichier1",&db);
if (rc!=SQLITE_OK){
printf("il ya une erreur dans la base de donnes %s",sqlite3_errmsg(db));

} else {
    printf("la base de donnes est ouverte\n");
       MN = cree_tble(db);
       if (MN==true){
        printf("la table est cree \n");
       }else{
        printf("il ya une erreur la table n est pas cree\n");
       }

}

    return 0;
}