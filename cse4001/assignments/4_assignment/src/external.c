#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum
{
    false,
    true
} bool; // boolean type

int main(int argc, char *argv[])
{

    int externalID = atoi(argv[1]);

    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 5 * sizeof(float), 0666 | IPC_CREAT);
    // shmat to attach to shared memory
    float *Temp = (float *)shmat(shmid, (void *)0, 0);
    int stabilized = (int)Temp[5];

    while (!stabilized)
    {
        // Update the temperature of this external process
        Temp[externalID] = (3 * Temp[externalID] + 2 * Temp[0]) / 5;
        stabilized = (int)Temp[5];
        sleep(1);
    }

    // detach from shared memory
    shmdt(Temp);

    return 0;
}
