#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "Shapoval"

int main(int argc, char ** argv) {
        sem_t *sem;

        if (argc != 2) {
                if ((sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0770, 0)) == SEM_FAILED) {
                        fprintf(stderr, "ERROR in opening semaphore");
                        return 1;
                }
        printf("sem_open. Semaphore is here\nWaiting for it to drop\n");
        if (sem_wait(sem) < 0)
                fprintf(stderr, "sem_wait ERROR");
        if (sem_close(sem) < 0)
                fprintf(stderr, "sem_close ERROR");
        return 0;
        } else {
                printf("Shapoval is dropping semaphore\n");
                if ((sem = sem_open(SEMAPHORE_NAME, 0)) == SEM_FAILED) {
                        fprintf(stderr, "sem_open ERROR");
                        return 1;
                }
                sem_post(sem);
                printf("sem_post. Shapoval dropped semaphore\n");
                return 0;
        }
}



