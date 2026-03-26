# Okindo Shawn Okindo
# EB3/68734/23


# Pigeonhole-sort
* It is a sorting algorithm that is used preferably when the number of elements and the range of elements are nearly the same.
* It applies the Pigeonhole principle which states that if there are n pigeons and m number of pigeonholes , and n>m, at least 1 pigeonhole will house at least 2 pigeons.

## When to use 
* When the number of elements and range of elements are nearly the same.
* When the values being sorted are all integers.
* When you can easily calculate the minimum and maximum values in advance.

## How to use 
* First find the minimum and maximum values in the array.Let the values be represented by 'min' and 'max' respectively.
* Find the range using formula (Range = max - min + 1).
* Set up an array of initially empty 'pigeonholes' the same number as the range.
* Visit each element in the array and place it in its pigeonhole.An element arr[i] is placed in its pigeonhole at index (arr[i]-min).
* Start the loop all over the pigeonhole array in order and put the elements in non empty holes back into the original.

## Time Complexity 
O(n + Range) where :
* n - input size

## Space Complexity
O(n) where n is input size 
