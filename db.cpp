/* C file take connects MySQL to Database server */
#include <mysql.h>
#include <stdio.h>

main() {
   MYSQL *connection;
   MYSQL_RES *result;
   MYSQL_ROW row;

   char *server = "localhost";
   char *user = "root";
   char *password = "user"; /* set me first */
   char *database = "tower";

   connection = mysql_init(NULL);

   /* Connect to database */
   if (!mysql_real_connect(connection, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(connection));
      exit(1);
   }

   /* send SQL query */
   if (mysql_query(connection, "show tables")) {
      fprintf(stderr, "%s\n", mysql_error(connection));
      exit(1);
   }

   result = mysql_use_result(connection);

   /* output table name */
   printf("MySQL Tables in mysql database:\n");
   while ((row = mysql_fetch_row(result)) != NULL)
      printf("%s \n", row[0]);

   /* close connection */
   mysql_free_result(result);
   mysql_close(connection);
}
