#include <stdbool.h>
#include <stdio.h>

// complete the following code
// function prime_nume returns array of prime number in range of min_val to max_val

int *prime_num( ... min_val, ... max_val){
    static int prime_num[1000]; // array of prime numbers
    int prime_idx=0; // index of array
    bool flag=true; // var to label the number. true for prime, and false for not prime
    
    // when min_val is lower than 2, replace it with 2.
    .... {
        ... ;
    }
    ////

    // this loop will scan through numbers in range
    for(int num=min_val; num ... ; ....){
        flag= ... ; //appropriate initial value of flag at every start of loop
        
        // stop the loop if min_val is greater than max_val
        if(...){     
            ...;
        }

        // logic to check whether the current number is prime or not
        for(int j=2; j < ... ; j++){
            if(...){
                flag=....;
                ....
            }
        }

        // assign the prime number based on the flag
        if(....){
            prime_num[prime_idx]= ... ;
            ++prime_idx;
        }
    }
    .... prime_num; // return array prime_num
}

int main()
{
    // range of numbers, you decide.
    int min=...;
    int max=...;
    
    int *my_prime;
    // call the function, pass min and max as the arguments
    my_prime= ... ;

    int len= 1000;
    printf("prime number between %d - %d:\n", min, max);
    
    for(int i=0; i<len; i++){
        if(*(my_prime+i)==0){
            break;
        }
        printf("%d ", *(my_prime+i));
    }

    return 0;
}
