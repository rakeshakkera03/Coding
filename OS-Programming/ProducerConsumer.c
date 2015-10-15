#include<stdio.h>
#include<pthread.h>
#include<assert.h>
#include<stdlib.h>

#define MAX_BUFFERS 8

typedef struct BUFFER {
	int numOfElements;
	int buf[MAX_BUFFERS];
	int in, out;
	pthread_mutex_t lock;
	pthread_cond_t full;
	pthread_cond_t empty;
}BUFFER;

void Initialize_Buffer( BUFFER** spooler )
{
	*spooler = (BUFFER*)malloc(sizeof(BUFFER));
	(*spooler)->numOfElements = 0;

	(*spooler)->in = 0;
	(*spooler)->out = 0;

	pthread_mutex_init(&(*spooler)->lock, NULL);
	pthread_cond_init(&(*spooler)->full, NULL);
	pthread_cond_init(&(*spooler)->empty, NULL);

}


void AcquireConsumerLock( void* arg )
{
	BUFFER* spooler = (BUFFER*)arg;

	pthread_mutex_lock( &spooler->lock );
	
	while( spooler->numOfElements == 0 )
	{
		printf(" \n Consumer Blocked \n" );
		pthread_cond_wait( &spooler->full, &spooler->lock );
	}

}

void ReleaseConsumerLock( void* arg )
{
	BUFFER* spooler = (BUFFER*)arg;
	
	pthread_cond_signal( &spooler->empty );

	pthread_mutex_unlock( &spooler->lock );
}


void* Consumer( void* arg )
{
	
	BUFFER* spooler = (BUFFER*)arg;
	
	for(int count = 0; count < 1000; count++ ) {

	AcquireConsumerLock( spooler );

	printf(" \nConsumed element %d \n", spooler->buf[spooler->in] );

	spooler->in = ( spooler->in + 1 ) % MAX_BUFFERS;
	
	spooler->numOfElements--;

	ReleaseConsumerLock( spooler );
	
	}

	pthread_exit(0);
}


void AcquireProducerLock( void* arg )
{
	BUFFER* spooler = (BUFFER*)arg;

	pthread_mutex_lock( &spooler->lock );
	
	while( spooler->numOfElements == MAX_BUFFERS )
	{
		printf(" \n Producer Blocked \n" );
		pthread_cond_wait( &spooler->empty, &spooler->lock );
	}
	

}

void ReleaseProducerLock( void* arg )
{
	BUFFER* spooler = (BUFFER*)arg;

	pthread_cond_signal( &spooler->full );

	pthread_mutex_unlock( &spooler->lock );
}

void* Producer( void* arg )
{
	BUFFER* spooler = (BUFFER*)arg;
	
	for(int count = 0; count < 1000; count++ ) {
	
	AcquireProducerLock( spooler );

	spooler->buf[spooler->out] = count;
	
	printf(" \nProduced element %d \n", spooler->buf[spooler->out] );
	
	spooler->out = ( spooler->out + 1 ) % MAX_BUFFERS;

	spooler->numOfElements++;

	ReleaseProducerLock( spooler );

	}

	pthread_exit(0);
}

int main()
{
	BUFFER* spooler;
	
	Initialize_Buffer( &spooler );

	pthread_t producer[1000]; //, producer2;
	pthread_t consumer[1000]; //, consumer2;

	for( int i = 0; i < 1000 ; i++ ) {
	pthread_create( &producer[ i ], NULL, Producer, (void*)spooler );
//	pthread_create( &producer2, NULL, Producer, (void*)spooler );
	pthread_create( &consumer[ i ], NULL, Consumer, (void*)spooler );
//	pthread_create( &consumer2, NULL, Consumer, (void*)spooler );
	}

	for( int i = 0; i < 1000 ; i++ ) {
	pthread_join( producer[ i ], NULL );
//	pthread_join( producer2, NULL );
	pthread_join( consumer[ i ], NULL );
//	pthread_join( consumer2, NULL );
	}


	return 0;
}
