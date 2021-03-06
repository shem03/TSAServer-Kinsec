#ifndef LOCKER_H
#define LOCKER_H

#include <exception>
#include <pthread.h>
#include <semaphore.h>

//信号量
class sem
{
public:
    sem()
    {
        if(sem_init(&m_sem,0,0)!=0)
        {
            throw std::exception();
        }
    }
    ~sem()
    {
        sem_destroy(&m_sem);
    }
    bool wait()
    {
        return sem_wait(&m_sem)==0;
    }
    bool post()
    {
        return sem_post(&m_sem)==0;
    }
private:
    sem_t m_sem;
};

//互斥锁
/*mutex class*/
class locker
{
public:
    locker() {
        if(pthread_mutex_init(&m_mutex,NULL)!=0)
        {
            throw std::exception();
        }
    }
    ~locker() {
        pthread_mutex_destroy(&m_mutex);
    }

    bool lock()
    {
        return pthread_mutex_lock(&m_mutex)==0;
    }

    bool unlock()
    {
        return pthread_mutex_unlock(&m_mutex)==0;
    }

private:
    pthread_mutex_t m_mutex;
};

//条件变量
/*condition_variable class*/
class cv
{
public:
    cv()
    {
        if(pthread_mutex_init(&m_mutex,NULL)!=0)
        {
            throw std::exception();
        }
        if(pthread_cond_init(&m_cv,NULL)!=0)
        {
            pthread_mutex_destroy(&m_mutex);
            throw std::exception();
        }
    }
    ~cv()
    {
        pthread_mutex_destroy(&m_mutex);
        pthread_cond_destroy(&m_cv);
    }

    bool wait()
    {
        int ret=0;
        pthread_mutex_lock(&m_mutex);
        ret=pthread_cond_wait(&m_cv,&m_mutex);
        pthread_mutex_unlock(&m_mutex);
        return ret==0;
    }

    bool signal()
    {
        pthread_cond_signal(&m_cv);
    }

private:
    pthread_mutex_t m_mutex;
    pthread_cond_t m_cv;
};


#endif
