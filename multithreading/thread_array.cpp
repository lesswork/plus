#include <iostream>
#include <cstring>
#include <cstdlib>
#include <pthread.h>

using namespace std;

class thread_array
{
	private:
    pthread_t thread1;
    pthread_t thread2;
    pthread_attr_t attr;

    pthread_mutex_t       mutex;
    pthread_mutexattr_t   m_attr;
    
    int 	rc;
    int count;
    void* status;
	int array[10];
public:
	thread_array()
	{
		count = 0;
		pthread_mutexattr_init(&m_attr);
        pthread_mutex_init(&mutex, &m_attr);
		for(int x=0 ; x<10 ; ++x)
		{
			array[x] = x+1;
		}
	}
	~thread_array() {pthread_mutexattr_destroy(&m_attr); }
	void doProcess();
	static void *threadFunction(void *t);
	void print();
};

void thread_array::print()
{
	for(int i=0 ; i<10 ; ++i)
		cout << array[i] << endl;
}

void thread_array::doProcess()
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

void *thread_array::threadFunction(void *t)
{

    cout << "Entering thread" << endl;
    thread_array *my_data;
    
    my_data = (thread_array	*) t;
    for( ; my_data->count < 10 ; )
    {
    	pthread_mutex_lock(&my_data->mutex);
	    //cout << "> " << my_data->array[my_data->count] << endl;
	    my_data->array[my_data->count] = (my_data->array[my_data->count] * my_data->array[my_data->count]);
	    my_data->count++;
	    pthread_mutex_unlock(&my_data->mutex);
 	}
	
    pthread_exit((void*) t);
}

int main (int argc, char *argv[])
{
    thread_array ob1;

    ob1.print();	
    ob1.doProcess();
    ob1.print();	

    pthread_exit(NULL);
    return 0;
}
