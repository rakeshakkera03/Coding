Skip to content
This repository  
Pull requests
Issues
Gist
 @rakeshakkera03
 Watch 1
  Star 0
  Fork 1 sandeepkru/algos
Branch: master  algos/misc/rwlock.cc
a7b392  on Jun 14
@sandeepkru sandeepkru rwlock
1 contributor
RawBlameHistory     122 lines (107 sloc)  1.32 KB
truct lock_t{
	int flag;
};


77;10003;0clock_t lock;

acquirelock(&lock);

releaselock(&lock);

acquirelock(lock_t* lock)
{
	while ( testandtest(lock) == 1 )
		sleep() or suspend();
	else
		return;
}

releaselock(lock_t lock)
{
	lock->flag = 0;
	wakeup();
}
atomic:
int testandtest(lock_t* lock)
{
	int old = lock->flag;
	lock->flag = 1;
	return old;
}


class rwlock
{
private:
	uint32_t readercount;
	sem_t    mutex;
	sem_t    wrlock;
public:
	init();
	readlock();
	readunlock();
	writelock();
	writelock();
};

void
rwlock::init()
{
	readercount = 0;
	sem_init(&mutex,  1);
	sem_init(&wrlock, 1);
}
void
rwlock::readlock()
{
	sem_wait(&mutex);
	++readercount;
	if ( readercount == 1 )
	{
		sem_wait(&wrlock);
	}
	sem_post(&mutex);
}

void
rwlock::readunlock()
{
	sem_wait(&mutex);
	--readercount;
	if ( readercount == 0 )
	{
		sem_post(&wrlock);
	}
	sem_post(&mutex);
}

void
rwlock::writelock()
{
	sem_wait(&wrlock);
}
void
rwlock::writeunlock()
{
	sem_post(&wrlock);
}

void
stack::readStack( )
{
	rwl.readlock();
	cout << s.top() << endl;
	rwl.readunlock();

}
void
stack::writeStack(int a)
{
	rwl.writelock();
	s.push(a);
	rwl.writeunlock();
}
class stack
{
private:
	rwlock rwl;
public:
	stack() { rwl.init(); }
	readStack();
	writetoStack(int a);

};
int main()
{
	stack s;
	// 10 threads are calling this.
	s.readStack();
	s.writetoStack(10);
}

