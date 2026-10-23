#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<sqlite3.h>
#include"DATA_BASE.h"
int main(){
sqlite3 *db;
 char[] errmsg = sqlite3_errmsg; 
int rc = sqlite3_open("C:\Users\User\.dbclient\storage\1787668532958@@127.0.0.1@5432@clinique\create-schema-template.sql",&db);
if (rc=!SQLITE_OK){
printf("il ya une erreur \n");
sqlite3_err(db);

} else 

    return 0;
}