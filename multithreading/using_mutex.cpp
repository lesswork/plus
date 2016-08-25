#include<iostream>
#include<cstring>
#include<cstdlib>
#include <pthread.h>
using namespace std;

class MyCounter{
private:
    pthread_t thread1;
    pthread_t thread2;
    pthread_attr_t attr;

    pthread_mutex_t       mutex;
    pthread_mutexattr_t   m_attr;
    
    int rc;
    void* status;
    
    // this is accessed by both threads commonly
    int numOfEvents;  
public:
    MyCounter(): numOfEvents(0)
    {
        pthread_mutexattr_init(&m_attr);
        pthread_mutex_init(&mutex, &m_attr);
    }

    ~MyCounter() { pthread_mutexattr_destroy(&m_attr); }
    
    int GetCount() { return numOfEvents; }
    void CreateTwoThreads();

    static void *threadFunction(void *t);
};

void MyCounter::CreateTwoThreads()
{    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    rc = pthread_create(&thread1, &attr, threadFunction, (void *)this);

    if (rc) {
        cout << "ERROR; return code from pthread_create() is : " << rc << endl;
        exit(-1);
    }
 
    rc = pthread_create(&thread2, &attr, threadFunction, (void *)this);

    if (rc) {
        cout << "ERROR; return code from pthread_create() is : " << rc << endl;
        exit(-1);
    }


    pthread_attr_destroy(&attr);

    rc = pthread_join(thread1, &status);
    if (rc) {
        cout << "ERROR; return code from pthread_join() is : " <<  rc << endl;
        exit(-1);
    }

    rc = pthread_join(thread2, &status);
    if (rc) {
        cout << "ERROR; return code from pthread_join() is : " <<  rc << endl;
        exit(-1);
    }
}

void *MyCounter::threadFunction(void *t)
{

    cout << "Entering thread" << endl;
    MyCounter *my_data;

    my_data = (MyCounter *) t;

    pthread_mutex_lock(&my_data->mutex);    
    for (int i = 0 ; i < 10000; ++i)
        ++my_data->numOfEvents;

    pthread_mutex_unlock(&my_data->mutex);

    pthread_exit((void*) t);
}

int main (int argc, char *argv[])
{
    MyCounter ob1;

    ob1.CreateTwoThreads();

    cout << "num of Events after both threads completed: " << ob1.GetCount() << endl;

    pthread_exit(NULL);
    return 0;
}
