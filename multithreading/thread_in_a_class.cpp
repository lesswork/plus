#include<iostream>
#include<cstring>
#include<cstdlib>
#include <pthread.h>
using namespace std;

class Packet{
private:
    pthread_t thread;
    pthread_attr_t attr;
    int rc;
    void* status;

    int  thread_id;
    int  sum;
    char message[10];

public:
    Packet(int id, int s, char* msg): thread_id(id), sum(s)
    {
        strcpy(message, msg);
    }

    void CreateThread();

    static void *threadFunction(void *t);
};

void Packet::CreateThread()
{    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


    cout << "Packet::CreateThread creating thread now" << endl;
    rc = pthread_create(&thread, &attr, threadFunction, (void *)this);

    if (rc) {
        cout << "ERROR; return code from pthread_create() is : " << rc << endl;
        exit(-1);
    }

    pthread_attr_destroy(&attr);

    rc = pthread_join(thread, &status);

    if (rc) {
        cout << "ERROR; return code from pthread_join() is : " <<  rc << endl;
        exit(-1);
    }
}

void *Packet::threadFunction(void *t)
{
    Packet *my_data;

    my_data = (Packet *) t;

    int taskid = my_data->thread_id;
    int sum = my_data->sum;
    
    char *hello_msg = my_data->message;
    
    cout << "From Thread: : " << taskid << " sum " <<  sum << " " << hello_msg << endl;

    pthread_exit((void*) t);
}

int main (int argc, char *argv[])
{

    Packet pack1 (1, 92929, "Hello from Ajay");

    pack1.CreateThread();

    pthread_exit(NULL);
    return 0;
}
