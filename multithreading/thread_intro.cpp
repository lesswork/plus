#include <iostream>
#include <pthread.h>
using namespace std;
#define NUM_THREADS     5

void *PrintHello(void *threadid)
{
    long tid;
    tid = (long)threadid;

    cout << "Hello from thread number: " << tid << endl;
    pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<NUM_THREADS; t++){
        cout << "In main: creating thread number : " <<  t << endl;
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if (rc){
            cout << "ERROR; return code from pthread_create() is " <<  rc << endl;
            return -1;
        }
    }

    /* Last thing  that main() should do */
    pthread_exit(NULL);
    return 0;
}
