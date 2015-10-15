#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<assert.h>
#include<string.h>

#define MAX_ELEMENTS 10

typedef struct Buffer
{
	int 		buf[MAX_ELEMENTS];
	int 		in;
	int 		out; 
	pthread_mutex_t lock;
	pthread_cond_t 	full;
	pthread_cond_t	empty;

}BUFFER;

void Initialize_buffer( BUFFER** buffer )
{
	(*buffer) = (BUFFER*)malloc(sizeof(BUFFER));

	memset( (*buffer)->buf, 0, sizeof(int) * MAX_ELEMENTS );

	(*buffer)->in = 0;
	(*buffer)->out = 0;
	int rc = pthread_mutex_init( &(*buffer)->lock, NULL );	
	assert( rc == 0 );
	rc = pthread_cond_init( &(*buffer)->full, NULL );	
	assert( rc == 0 );
	rc = pthread_cond_init( &(*buffer)->empty, NULL );	
	assert( rc == 0 );

}

void AcquireConsumerLock( BUFFER* buffer )
{
	int rc = pthread_mutex_lock( &buffer->lock );
	assert( rc == 0 );

	if( buffer->in == buffer->out )
	{
		printf("\n Buffer is empty\n");

		while( buffer->in == buffer->out )
		{
			pthread_cond_wait( &buffer->full, &buffer->lock );
		}
	}

}

void ReleaseConsumerLock( BUFFER* buffer )
{
	pthread_cond_signal( &buffer->empty );

	int rc = pthread_mutex_unlock( &buffer->lock );
	assert( rc == 0 );

}	

void* Consumer ( void* arg )
{
	BUFFER* buffer = (BUFFER*)arg;
	for( int i = 0; i < 10 ; i++ )
	{
		AcquireConsumerLock( buffer );
		
		buffer->in = ( buffer->in + 1 ) % MAX_ELEMENTS;
		
		int consumed_value = buffer->buf[buffer->in];
		
		printf("\n Consumer consumed %d item at location %d\n", consumed_value, buffer->in );
		
		ReleaseConsumerLock( buffer );
	}

	return NULL;
}

void AcquireProducerLock( BUFFER* buffer )
{
	int rc = pthread_mutex_lock( &buffer->lock );
	assert( rc == 0 );

	if( buffer->in == ( buffer->out + 1 ) % MAX_ELEMENTS )
	{
		printf("\n Buffer is full\n");

		while( buffer->in == ( buffer->out + 1 ) % MAX_ELEMENTS )
		{
			pthread_cond_wait( &buffer->empty, &buffer->lock );
		}
	}
	
}

void ReleaseProducerLock( BUFFER* buffer )
{
	pthread_cond_signal( &buffer->full );

	int rc = pthread_mutex_unlock( &buffer->lock );
	assert( rc == 0 );

}	

void* Producer ( void* arg )
{
	BUFFER* buffer = (BUFFER*)arg;

	for( int i = 0; i < 10 ; i++ )
	{
		AcquireProducerLock( buffer );
		
		buffer->out = ( buffer->out + 1 ) % MAX_ELEMENTS;
		
		buffer->buf[buffer->out] = i;
		
		printf("\n Producer produced one item in location %d\n", buffer->out );
		
		ReleaseProducerLock( buffer );
	}

	return NULL;
}


int main(void)
{
	BUFFER* buffer;
	
	Initialize_buffer( &buffer );
	pthread_t producer_thread_1;
	pthread_t producer_thread_2;
	pthread_t consumer_thread_1;
	pthread_t consumer_thread_2;


	pthread_create(&producer_thread_1, NULL, Producer, buffer );
	pthread_create(&producer_thread_2, NULL, Producer, buffer );
	pthread_create(&consumer_thread_1, NULL, Consumer, buffer );
	pthread_create(&consumer_thread_2, NULL, Consumer, buffer );
		
	pthread_join(producer_thread_1, NULL );	
	pthread_join(producer_thread_2, NULL );	
	pthread_join(consumer_thread_1, NULL );	
	pthread_join(consumer_thread_2, NULL );	
	return 0;
}
