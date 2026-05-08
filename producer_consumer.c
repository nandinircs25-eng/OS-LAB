#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0;
int item = 1;
int count = 0;   // to track number of items

sem_t empty, full, mutex;

// Enqueue
void enqueue() {
    queue[rear] = item;
    printf("Produced: Item %d\n", item);
    rear = (rear + 1) % SIZE;
    item++;
    count++;
}

// Dequeue
void dequeue() {
    int data = queue[front];
    printf("Consumed: Item %d\n", data);
    front = (front + 1) % SIZE;
    count--;
}

// Producer
void* producer(void* arg) {
    if (count == SIZE) {
        printf("Buffer Full\n");
        pthread_exit(NULL);
    }

    sem_wait(&empty);
    sem_wait(&mutex);

    enqueue();

    sem_post(&mutex);
    sem_post(&full);

    pthread_exit(NULL);
}

// Consumer
void* consumer(void* arg) {
    if (count == 0) {
        printf("Buffer Empty\n");
        pthread_exit(NULL);
    }

    sem_wait(&full);
    sem_wait(&mutex);

    dequeue();

    sem_post(&mutex);
    sem_post(&empty);

    pthread_exit(NULL);
}

int main() {
    int choice;
    pthread_t p, c;

    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    while (1) {
        printf("\n1.Producer  2.Consumer  3.Exit : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&p, NULL, producer, NULL);
                pthread_join(p, NULL);
                break;

            case 2:
                pthread_create(&c, NULL, consumer, NULL);
                pthread_join(c, NULL);
                break;

            case 3:
                printf("Exit\n");
                sem_destroy(&empty);
                sem_destroy(&full);
                sem_destroy(&mutex);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
