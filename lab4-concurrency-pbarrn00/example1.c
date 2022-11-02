/**
 * Author: Pablo Javier Barrio Navarro
*/

/**
 * RULE: CON43-C. Do not allow data races in multithreaded code
 * This rule says that when multiple threads can read or modify the same data, use synchronization techniques to avoid software flaws that can lead to security vulnerabilities.
 * 
 * PROBLEM: When we use threads, if a program contains a data race with conflicts between multiple threads and at least one of which is non-atomic and neither occurs before
 * the other it can result in undefined behavior.
 * 
 * In the next example, we have two functions in which credit is added or withdrawn from a bank account, and since the addition and subtraction operations of the function are not atomic,
 * it is possible to perform both operations at the same time but only the result of one is saved.
 * In this way, if a large number of small debits are made, there may be actions that are not carried out correctly against the account balance,
 * thus generating a vulnerability in the program.
*/

/*
static volatile int account_balance;
 
void debit(int amount) {
  account_balance -= amount;
}
 
void credit(int amount) {
  account_balance += amount;
}
*/

/**
 * SOLUTION: To avoid this problem, we can use a mutex to lock the critical section of the code, so that only one thread can access it at a time.
 * The solution to this type of problem is to use a mutex or semaphore to avoid a data race and that the registers cannot be accessed if a function is writing to a variable.
 * When this process is finished, you can continue making deposits, thus avoiding money being stolen from the bank.
*/

#include <stdio.h>
#include <threads.h>
 
static int account_balance;
static mtx_t account_lock;
  
int debit(int amount) {
  if (mtx_lock(&account_lock) == thrd_error) {
    return -1;   /* Indicate error to caller */
  }
  account_balance -= amount;
  if (mtx_unlock(&account_lock) == thrd_error) {
    return -1;   /* Indicate error to caller */
  }
  return 0;   /* Indicate success */
}
 
int credit(int amount) {
  if (mtx_lock(&account_lock) == thrd_error) {
    return -1;   /* Indicate error to caller */
  }
  account_balance += amount;
  if (mtx_unlock(&account_lock) == thrd_error) {
    return -1;   /* Indicate error to caller */
  }
  return 0;   /* Indicate success */
}
  
int main(void) {
  if(mtx_init(&account_lock, mtx_plain) == thrd_error) {
    /* Handle error */
  }
  /* ... */
}
