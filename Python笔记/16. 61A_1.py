"""Write a function that will count the number of even numbers between a given start number and a given end number.
It should include the start or end if they are even.
"""
def count_evens(start, end):
    """
    >>> count_evens(2, 2)
    1
    >>> count_evens(-2, 52)
    28
    >>> count_evens(237, 500)
    132
    """
    # YOUR CODE HERE
    return (end - start) // 2 + 1


"""Write a function that will count the amount of multiples
of a given divisor between a given start number and a given end number.
It should include the start or end if they are a multiple.

For example, if the range is 1 to 12 and the divisor is 3,
the function should return 4, since 3, 6, 9, and 12 can all be evenly divided by 3.
"""

def count_multiples(start, end, divisor):
    """
    >>> count_multiples(2, 2, 1)       # 2 is a multiple of 1
    1 
    >>> count_multiples(2, 2, 2)       # 2 is a multiple of 2
    1 
    >>> count_multiples(2, 2, 3)       # 2 is not a multiple of 3
    0
    >>> count_multiples(1, 12, 3)      # 3, 6, 9, 12
    4 
    >>> count_multiples(237, 500, 10)
    27
    """
    # YOUR CODE HERE
    divisor_list = []
    
    while start <= end:
        if start % divisor == 0:
            divisor_list.append(start)
        start += 1
    
    return len(divisor_list)


""""
Write a function that sums up the multiples of a given number between a given start and end.
If the start or end numbers are also multiples, it should include them in the sum.

For example, if the range is 1-12 and the divisor is 4, the function should add 4+8+12, returning 24.
"""
def sum_multiples(start, end, divisor):
    """
    >>> sum_multiples(1, 12, 4)
    24
    >>> sum_multiples(1, 12, 13)
    0
    >>> sum_multiples(2, 2, 2)
    2
    >>> sum_multiples(2, 2, 3)
    0
    >>> sum_multiples(23, 81, 13)
    260
    """
    # YOUR CODE HERE
    divisor_list = []
    
    while start <= end:
        if start % divisor == 0:
            divisor_list.append(start)
        start += 1
    
    sum = 0
    
    for i in divisor_list:
        sum += i
    
    return sum


"""
This function should return the product 
of all the numbers from 1 to the given end number
(including the end number).

It is mostly written for you, but it has several bugs!
Tips for debugging:
* Read through the code and trace it on paper for small inputs
* Try running the tests and observe the output
* If you have a hunch, try changing the code and seeing how the output changes
"""

def product_of_numbers(end):
    """
    >>> product_of_numbers(1)
    1
    >>> product_of_numbers(2)
    2
    >>> product_of_numbers(3)
    6
    >>> product_of_numbers(10)
    3628800
    """
    result = 1
    counter = 1
    while counter <= end:
        result *= counter
        counter += 1
    return result

def dipping(dots):
    if print("you dip"):
        return print("i dip")
    else:
        return print(dots) or dots or print("we dip")

dipping(0)