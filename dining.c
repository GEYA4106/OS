#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define N 5
pthread_mutex_t mutex;
pthread_cond_t cond[N];
int state[N];
#define THINKING 0
#define HUNGRY 1
#define EATING 2
int left(int i) {
    return (i + N - 1) % N;
}
int right(int i) {
    return (i + 1) % N;
}
void test(int i) {
    if (state[i] == HUNGRY &&
        state[left(i)] != EATING &&
        state[right(i)] != EATING) {
        state[i] = EATING;
        printf("Philosopher %d is Eating\n", i);
        pthread_cond_signal(&cond[i]);
    }
}
void take_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = HUNGRY;
    printf("Philosopher %d is Hungry\n", i);
    test(i);
    while (state[i] != EATING) {
        pthread_cond_wait(&cond[i], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}
void put_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d is Thinking\n", i);
    test(left(i));
    test(right(i));
    pthread_mutex_unlock(&mutex);
}
void* philosopher(void* num) {
    int i = *(int*)num;
    while (1) {
        sleep(1);
        take_forks(i);
        sleep(1);
        put_forks(i);
    }
}
int main() {
    pthread_t thread_id[N];
    int phil[N];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < N; i++) {
        pthread_cond_init(&cond[i], NULL);
        state[i] = THINKING;
    }
    for (int i = 0; i < N; i++) {
        phil[i] = i;
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
        printf("Philosopher %d is Thinking\n", i);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(thread_id[i], NULL);
    }
    return 0;
}