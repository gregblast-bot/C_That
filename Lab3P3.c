#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

// initialize threads
pthread_t thread1, thread2, thread3;
// declare pthread_mutex_t type variable name mutex
pthread_mutex_t mutex;
pthread_mutexattr_t mutexattr;
// initialize schedule paramater, priority and policy as round robin
struct sched_param param;
int priority = 10;
int policy = SCHED_RR;
int g = 0;

void *function()

{
	printf("\nIn function.");
	sleep(100);
	int x = 0 + 0;
	printf("\nx = %d", x);
	return 0;
}

 

void *function1()

{
	printf("\nThread 1 in.");
	//function 1 for thread 1.
	int s1 = 1;
	printf("\ns1 = %d", s1);
	printf("\nThread 1 out.");
	sleep(200);
	return 0;
}

 

void *function2()

{
	printf("\nThread 2 in.");
	pthread_mutex_lock(&mutex);      //lock mutex
	//function 2 for thread 2.
	int s2 = 2 + g;
	g++;
	printf("\ns2 = %d and global variable g = %d", s2, g);
	//do some work here and call function()
	function();
	printf("\nThread 2 out.");
	pthread_mutex_unlock(&mutex);  //unlock mutex
	sleep(200);
	return 0;
}

 

void *function3()

{
	printf("\nThread 3 in.");
	//function 3 for thread 3.
	int s3 = 3;
	printf("\ns3 = %d", s3);
	printf("\nThread 3 out.");
	sleep(200);
	return 0;
}

 

int main()

{
	
    // create mutex and initialize it.
	pthread_mutexattr_setprotocol(&mutexattr, PTHREAD_PRIO_INHERIT);  // set protocol for mutex attributes as priority inheritance
	pthread_mutex_init(&mutex, &mutexattr);                           // mutex initialize
	
	// create thread 1, thread 2 and thread 3
	pthread_create(&thread1, NULL, function1, NULL);
	pthread_create(&thread2, NULL, function2, NULL);
	pthread_create(&thread3, NULL, function3, NULL);
	
	
	// set different priority for each thread
	int maxpriority = sched_get_priority_max(policy);   // set max priority according to policy
	int minpriority = sched_get_priority_min(policy);	// set min priority according to policy
	param.sched_priority = maxpriority;                    // schedule priority to 10
	
	pthread_setschedparam(thread1,policy,&param);
	pthread_setschedparam(thread2,policy,&param);
	pthread_setschedparam(thread3,policy,&param);

	printf("\nMAX priority = %d", maxpriority);
	printf("\nMIN priority = %d", minpriority);
	
	// set handler for thread 1, thread 2 and thread 3 respectively. For instance, function 1 for thread 1, function 2 for thread 2 and function 3 for thread 3
	printf("\nThread 1 starts.");
	int threadp1 = pthread_getschedparam(thread1,&policy,&param);
	printf("\nThread1 priority = %d", threadp1);
	pthread_join(thread1, NULL);
	printf("\nThread 1 ends.");
	printf("\nThread 2 starts.");
	pthread_join(thread2, NULL);
	int threadp2 = pthread_getschedparam(thread2,&policy,&param);
	printf("\nThread2 priority = %d", threadp2);
	printf("\nThread 2 ends.");
	printf("\nThread 3 starts.");
	pthread_join(thread3, NULL);
	int threadp3 = pthread_getschedparam(thread3,&policy,&param);
	printf("\nThread3 priority = %d", threadp3);
	printf("\nThread 3 ends.");
}
