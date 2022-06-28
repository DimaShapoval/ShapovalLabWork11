#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include "libpq-fe.h"

int main(int argc, char **argv) {
                const char *conninfo;
                PGconn *conn;
                PGresult *res;
                PGnotify *notify;
                char db[] = "shapoval_dmitro";

                conn = PQsetdbLogin(NULL, NULL, NULL, NULL, db, NULL, NULL);
                if (PQstatus(conn) != CONNECTION_OK) {
                                fprintf(stderr, "Connection failed: %s", PQerro$
                                PQfinish(conn);
                                exit(1);
                }
        res = PQexec(conn, "LISTEN andruh");



        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                fprintf(stderr, "LISTENING failed: %s", PQerrorMessage(conn));
                PQclear(res);
                PQfinish(conn);
                          exit(1);
        }
        PQclear(res);
        while(1==1) {
                PQconsumeInput(conn);
                while ((notify = PQnotifies(conn)) != NULL) {
                        fprintf(stderr, "%s's NOTIFY reserved from PID %d:%s\n"$
                        PQfreemem(notify);
                        PQconsumeInput(conn);
                }
                                                }
        }
        fprintf(stdout, "Done.\n");
                PQfinish(conn);
        return 0;
}


