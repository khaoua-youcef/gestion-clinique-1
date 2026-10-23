#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sqlite3.h>
#include"DATA_BASE.h"
int main(){
sqlite3 *db;
 char *errmsg=NULL;
int rc = sqlite3_open("fichier1",&db);
if (rc!=SQLITE_OK){
printf("il ya une erreur dans la base de donnes %s",sqlite3_errmsg(db));

} else {
    printf("la base de donnes est ouverte\n");
   const char * sql ="CREATE TABLE IF NOT EXISTS patiant ("
   "ticket INTEGER PRIMARY KEY AUTOINCREMENT,"
   "nom TEXT,"
   "age INT,"
   " sex TEXT);";
    int fl  = sqlite3_exec (db,sql,NULL,0,&errmsg);
  if(fl==SQLITE_OK){
printf("la table est crree\n");
  } else{
printf("il y a un probleme dans %s",errmsg);
sqlite3_free(errmsg);

  }
  sqlite3_close(db);
}

    return 0;
}