import math
import time

def check_for_prime(num):
    lowest_factor=num

    if num%2==0:
        lowest_factor=2
    elif num%3==0:
        lowest_factor=3
                
    else:
        sqr_root=math.floor(math.sqrt(num))
                          
        for i in range(5,sqr_root,6):
            if (num % i== 0):
                lowest_factor=i
                break 
            elif(num%(i+2) == 0):
                lowest_factor=i+2
                break 

    return lowest_factor

def Execute():

    num = int(input("Enter a number: "))
    #num=9999991

    print("Testing primality for the number:",num)

    start = time.time()
    lowest_factor=check_for_prime(num)

    if(num>lowest_factor):
        print(num," is not a prime number. The lowest factor is: ", lowest_factor)
    else:
        print(num,"is a prime number")


    done = time.time()

    elapsed = done - start
    print("Time taken: ", elapsed)

Execute()