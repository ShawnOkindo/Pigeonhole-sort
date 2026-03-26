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
* n - input size.

## Space Complexity
O(n) where n is input size. 

## Step-by-step demonstration on a small example
* I’ll show exactly how my algorithm works using this unsorted list: 5 1 8 3 (n = 4).

### a) Find min and max (comparisons happen here)
* Start: min = 5, max = 5
* • Look at 1: 1 < 5? Yes → min = 1 (1 comparison)
* 1 > 5? No (1 comparison)
* • Look at 8: 8 < 1? No (1 comparison)
* 8 > 5? Yes → max = 8 (1 comparison)
* • Look at 3: 3 < 1? No (1 comparison)
* 3 > 8? No (1 comparison)
* Total comparisons so far: 6 (exactly 2 × (4-1))

### b) Create pigeonholes
* Range = max - min + 1 = 8 - 1 + 1 = 8 holes
* Holes look like this (index 0 = value 1, index 7 = value 8):
[0, 0, 0, 0, 0, 0, 0, 0]

### Put numbers into holes (no comparisons)
* • 5 goes to hole 4 → hole[4] = 1
* • 1 goes to hole 0 → hole[0] = 1
* • 8 goes to hole 7 → hole[7] = 1
* • 3 goes to hole 2 → hole[2] = 1
* Now holes: [1, 0, 1, 0, 1, 0, 0, 1]
  
### Build sorted list in DESCENDING order (no swaps)
* Start from the highest hole and go down:
* • Hole 7 (value 8): put 8 once → list = [8]
* • Hole 6 (value 7): 0 times
* • Hole 5 (value 6): 0 times
* • Hole 4 (value 5): put 5 once → list = [8, 5]
* • Hole 3 (value 4): 0 times
* • Hole 2 (value 3): put 3 once → list = [8, 5, 3]
* • Hole 1 (value 2): 0 times
* • Hole 0 (value 1): put 1 once → list = [8, 5, 3, 1]

* Final sorted list (descending): 8 5 3 1
* Comparisons: 6
* Swaps: 0
* The pigeons (numbers) just fly into their holes and then we pull them out from biggest to smallest.
  
## Time complexity (best, average, worst case)
* I counted every operation myself while writing the code:

* Finding min/max → always 2(n-1) comparisons (no matter what the numbers are).
* Putting numbers into holes → exactly n operations.
* Building the sorted list → exactly n operations (we visit every pigeon once and copy each number once).

* So the total time is O(n + k) where k = (max - min + 1) is the range.

* Best case: When all numbers are the same → k = 1. Time is basically O(n). 
* Average case: When numbers are random but the range k is not crazy huge (like 0 to 1000) → still O(n + k) which is pretty much O(n) if k is small.
* Worst case: When the range k is enormous (e.g. one number is 1 and another is 1,000,000,000) → O(n + k) becomes slow because we have to create a giant array of 1 billion holes. Memory also explodes, but the algorithm still finishes in linear time relative to k.

## Space complexity
* We need:

* i)The original list → O(n)
* ii)The pigeonhole (count) array → O(k)

* So total extra space is O(k) (the pigeonholes).
* That’s the trade-off: pigeonhole sort uses more memory than something like quicksort, but it’s really fast when k is small. For my tests I kept numbers between 1 and 1000 so k never got bigger than 1000.
