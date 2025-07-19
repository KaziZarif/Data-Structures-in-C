#include <pthread.h>

typedef struct {
    int count;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} semaphore_t;

void sem_init(semaphore_t* sem, int value) {
    sem->count = value;
    pthread_mutex_init(&sem->lock, NULL);
    pthread_cond_init(&sem->cond, NULL);
}

void sem_wait(semaphore_t* sem) {
    pthread_mutex_lock(&sem->lock);
    while (sem->count == 0) {
        pthread_cond_wait(&sem->cond, &sem->lock);
    }
    sem->count--;
    pthread_mutex_unlock(&sem->lock);
}

void sem_post(semaphore_t* sem) {
    pthread_mutex_lock(&sem->lock);
    sem->count++;
    pthread_cond_signal(&sem->cond);
    pthread_mutex_unlock(&sem->lock);
}

void sem_destroy(semaphore_t* sem) {
    pthread_mutex_destroy(&sem->lock);
    pthread_cond_destroy(&sem->cond);
}