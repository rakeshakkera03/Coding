#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

#define MAX_BUFFER 10

typedef struct BUFFER
{
  int noOfElement;
  int in;
  int out;
  int buffer[MAX_BUFFER];

  pthread_cond_t empty;
  pthread_cond_t full;
  pthread_mutex_t lock;
}BUFFER;

unsigned long gettid()
{
    pthread_t ptid = pthread_self();
    unsigned long threadId = 0;
    memcpy(&threadId, &ptid, sizeof(ptid));
    return threadId;
}

void Initialize_buffer( BUFFER **buf)
{
  
  (*buf) = (BUFFER*)malloc(sizeof(BUFFER));
  
  (*buf)->noOfElement = 0;
  (*buf)->in = -1;
  (*buf)->out = -1;
  
  // memset( (*buf)->buffer, 0, sizeof(int) * MAX_BUFFER);
  
  pthread_cond_init(&(*buf)->empty,NULL);
  pthread_cond_init(&(*buf)->full, NULL);
  pthread_mutex_init(&(*buf)->lock, NULL);
  //(*buf)->empty = PTHREAD_COND_INITIALIZER;
  //(*buf)->full = PTHREAD_COND_INITIALIZER;
  //(*buf)->lock = PTHREAD_MUTEX_INITIALIZER;
}


void AcquireConsumerLock( BUFFER* printer_buffer)
{
  pthread_mutex_lock( &printer_buffer->lock );
    printf("\n Consumer Mutex Lock Acquired. \n");
  
  while( printer_buffer->noOfElement == 0 )
  {
    printf("\n Consumer blocked. \n");
    pthread_cond_wait( &printer_buffer->full, &printer_buffer->lock );
  }
  
}

void ReleaseConsumerLock( BUFFER* printer_buffer)
{
  
    printf("\n Consumer released. \n");
  pthread_cond_signal( &printer_buffer->empty );
  
  pthread_mutex_unlock( &printer_buffer->lock );
  
}

void AcquireProducerLock( BUFFER* printer_buffer)
{
  pthread_mutex_lock( &printer_buffer->lock );
  
    printf("\n Producer Mutex Lock Acquired. \n");
  while( printer_buffer->noOfElement == MAX_BUFFER )
  {
    printf("\n Producer blocked. \n");
    pthread_cond_wait( &printer_buffer->empty, &printer_buffer->lock );
  }
  
}

void ReleaseProducerLock( BUFFER* printer_buffer)
{
  
    printf("\n Producer Release. \n");
  pthread_cond_signal( &printer_buffer->full );
  
  pthread_mutex_unlock( &printer_buffer->lock );
  
}

void* ConsumerThread( void* arg )
{ 
  BUFFER* printer_buffer = ( void * )arg;
  
  for( int count = 0; count < 10000; count++ )
  {
    AcquireConsumerLock( printer_buffer );
    
    
    printer_buffer->noOfElement--;
    
    printer_buffer->out = (printer_buffer->out + 1) % MAX_BUFFER;
    
    printf("\n%d. Consumer %ld consumed item %d at location %d.", count, gettid(), printer_buffer->buffer[ printer_buffer->out ] , printer_buffer->out);
    
    printer_buffer->buffer[printer_buffer->out] = -1;
    
    
    ReleaseConsumerLock( printer_buffer );
    
  }
  
  pthread_exit(0);
  
}

void* ProducerThread( void* arg )
{ 
  BUFFER* printer_buffer = ( void * )arg;
  for( int count = 0; count < 10000; count++ )
  {
    AcquireProducerLock( printer_buffer );
    
    
    printer_buffer->noOfElement++;
    
    printer_buffer->in = (printer_buffer->in + 1) % MAX_BUFFER;
    
    printer_buffer->buffer[printer_buffer->in] = count;
    
    printf("\n%d. Producer %ld produced item %d at location %d.", count, gettid(), printer_buffer->buffer[ printer_buffer->in ] , printer_buffer->in);
    
    ReleaseProducerLock( printer_buffer );
    
  }
  
  pthread_exit(0);
  
}

int main()
{
  BUFFER *printer_buffer;
  
  
  
  Initialize_buffer( &printer_buffer );
  
  pthread_t producer1, producer2;
  pthread_t consumer1, consumer2;
  
  pthread_create( &producer1, NULL, ProducerThread, ( void *)printer_buffer);
  pthread_create( &producer2, NULL, ProducerThread, ( void *)printer_buffer);
  pthread_create( &consumer1, NULL, ConsumerThread, ( void *)printer_buffer);
  pthread_create( &consumer2, NULL, ConsumerThread, ( void *)printer_buffer);
  
  pthread_join( producer1, NULL);
  pthread_join( producer2, NULL);
  pthread_join( consumer1, NULL);
  pthread_join( consumer2, NULL);
  
  
  return 0;
}
