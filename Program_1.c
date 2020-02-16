#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;
void *OddNumber(void *arg);
void *EvenNumber(void *arg);

int main()
{
	sem_init(&sem,0,1);
	pthread_t thread_1,thread_2;
	int reval_1,renVal_2;
	reval_1=pthread_create(&thread_1,NULL,OddNumber,NULL);
	usleep(4000);
	renVal_2=pthread_create(&thread_2,NULL,EvenNumber,NULL);
	printf("WElcome to c Program\n");
	pthread_join(thread_1,NULL);
	pthread_join(thread_2,NULL);
	printf("End of Main\n");
}
void *OddNumber(void *arg)
{
	int Number=0;
	int error=0;
	printf("Thread started \n");
	while(1)
	{
		sem_wait(&sem);
		if(Number%2==1)
		{
			printf("Odd Number	 : %d\n",Number);
		}
		sem_post(&sem);
		if (Number == 10)	
		{
			break;
		}
		Number++;
		usleep(4000);
	}
	printf("Thread End\n");

}
void *EvenNumber(void *arg)
{
	int Number=1;
	printf("Thread_2 started \n");
	while(1)
	{
		sem_wait(&sem);
		if(Number%2 ==0)
		{
			printf("Even Number	 : %d\n",Number);
		}
		sem_post(&sem);
		if(Number==10)
		{
			break;
		}
		Number++;
		usleep(4000);
	}
	printf("Thread_2 End\n");
}
