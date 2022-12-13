#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool; // boolean type

void updateTemps(float *t);

int main(int argc, char *argv[])
{

    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);
    // shmget returns an identifier in shmid
    int shmid = shmget(key, 5 * sizeof(float), 0666 | IPC_CREAT);
    // shmat to attach to shared memory
    float *Temp = (float *)shmat(shmid, (void *)0, 0);

    float prev[] = {0, 0, 0, 0, 0};

    // Initial temperature of all processes
    Temp[0] = 15; // Central
    Temp[1] = 50; // 1
    Temp[2] = 30; // 2
    Temp[3] = 40; // 3
    Temp[4] = 20; // 4
    Temp[5] = 0;  // flag

    int stabilized = (int)Temp[5];
    printf("Central\t\tExt1\t\tExt2\t\tExt3\t\tExt4\n");
    while (!stabilized)
    {
        printf("%f\t%f\t%f\t%f\t%f\n", Temp[0], Temp[1], Temp[2], Temp[3], Temp[4]);
        sleep(1);

        // Update the temperature of the central process
        Temp[0] = (2 * Temp[0] + Temp[1] + Temp[2] + Temp[3] + Temp[4]) / 6;

        // checking for same temps
        if ((Temp[1] == prev[1]) && (Temp[2] == prev[2]) && (Temp[3] == prev[3]) && (Temp[4] == prev[4]))
        {
            stabilized = 1;
        }

        // storing previous temps
        for (int i = 0; i <= 4; i++)
        {
            prev[i] = Temp[i];
        }
    }
    printf("\nTemp Stabilized\nCentral Temp: %f\n", Temp[0]);

    int j;
    for (j = 1; j <= 4; j++)
    {
        printf("Ext%d Temp: %f\n", j, Temp[j]);
    }
    // detach from shared memory
    shmdt(Temp);

    // destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
