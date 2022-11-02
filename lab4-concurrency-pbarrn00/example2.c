/**
 * Author: Pablo Javier Barrio Navarro
 */

/**
 * RULE: CON39-C. Do not join or detach a thread that was previously joined or detached
 * A thread shall not be joined once it was previously joined or detached. 
 * Similarly, a thread shall not be detached once it was previously joined or detached.
 * Violating either of these subclauses results in undefined behavior.
 * 
 * PROBLEM: The problem in the next example is that a detached thread is later joined, which is not allowed.
*/

/*

#include <stddef.h>
#include <threads.h>
  
int thread_func(void *arg) {
  / Do work /
  thrd_detach(thrd_current());
  return 0;
}
 
int main(void) {
  thrd_t t;
 
  if (thrd_success != thrd_create(&t, thread_func, NULL)) {
    / Handle error /
    return 0;
  }
 
  if (thrd_success != thrd_join(t, 0)) {
    / Handle error /
    return 0;
  }
  return 0;
}
*/

/**
 * SOLUTION: Don't detach the thread. Its resources are released upon successfully joining with the main thread
*/

#include <stddef.h>
#include <threads.h>
   
int thread_func(void *arg) {
  /* Do work */
  return 0;
}
 
int main(void) {
  thrd_t t;
 
  if (thrd_success != thrd_create(&t, thread_func, NULL)) {
    /* Handle error */
    return 0;
  }
 
  if (thrd_success != thrd_join(t, 0)) {
    /* Handle error */
    return 0;
  }
  return 0;
} 