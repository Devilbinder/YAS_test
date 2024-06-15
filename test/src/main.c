#include <stdio.h>
#include "yas_scheduler.h"
#include "yas_timer.h"

void yas_sleep_idle(int64_t time){
    // printf("idle time %ldms\n", time);
}

void task_0(yas_task_t *task, void *context){
    printf("task id: %d\n", task->id);
    
    yas_task_sleep(task, 500);
}

void task_1(yas_task_t *task, void *context){
    printf("task id: %d\n", task->id);
    
    yas_task_sleep(task, 1000);
}


void timer_callback(void *context){

    /* Note: From timer_create(2) — Linux manual page. 
            "calling printf() from a signal handler is not safe
            (and should not be done in production programs), since
            printf() is not async-signal-safe; see signal-safety(7).
            Nevertheless, we use printf() here as a simple way of
            showing that the handler was called."
            Same logic applies to this.
    */
    printf("timer expired\n");
    yas_stop();
}

int main(void){

    int ret = 0;

    yas_timer_t timer;

    ret = yas_init();

    if(ret != YAS_OK){
        printf("Init failed: %d", ret);
        return ret;
    }

    yas_set_idle_hook(yas_sleep_idle);

    ret = yas_create_timer(&timer, timer_callback, NULL);

    if(ret != YAS_OK){
        printf("Create timer failed: %d", ret);
        return ret;
    }

    ret = yas_start_timer(&timer, YAS_TIMER_ONESHOT, 5000);

    if(ret != YAS_OK){
        printf("Start timer failed: %d", ret);
        return ret;
    }

    yas_create_task(task_0, NULL);
    yas_create_task(task_1, NULL);

    yas_start();

    yas_deinit();

    yas_free_timer(&timer);


    return 0;
}