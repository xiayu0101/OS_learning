#include "thread.h"
#include "thread-sync.h"

#define N 3
sem_t locks[N];

void Tphilosopher(int id) {
    int lhs = (N + id - 1) % N;
    int rhs = id % N;
    while (1) {
        P(&locks[lhs]);
        printf("T%d Got %d\n", id, lhs + 1);
        P(&locks[rhs]);
        printf("T%d Got %d\n", id, rhs + 1);
        V(&locks[lhs]);
        V(&locks[rhs]);
//分布式方法
//        mutex_lock(&mutex);
//        while (!(avail[lhs] && avail[rhs])) {
//            wait(&cv, &mutex);
//        }
//        avail[lhs] = avail[rhs] = false;
//        mutex_unlock(&mutex);
//
//        mutex_lock(&mutex);
//        avail[lhs] = avail[rhs] = true;
//        broadcast(&cv);
//        mutex_unlock(&mutex);

//集中式解决方法
//        void Tphilosopher(int id) {
//            send_request(id, EAT);
//            P(allowed[id]); // waiter 会把叉子递给哲学家
//            philosopher_eat();
//            send_request(id, DONE);
//        }
//
//        void Twaiter() {
//            while (1) {
//                (id, status) = receive_request();
//                if (status == EAT) { ... }
//                if (status == DONE) { ... }
//            }
//        }
    }
}

int main(int argc, char *argv[]) {
//    for (int i = 0; i < N; i++) {
//        SEM_INIT(&locks[i], 1);
//    }
//    for (int i = 0; i < N; i++) {
//        create(Tphilosopher);
//    }
}