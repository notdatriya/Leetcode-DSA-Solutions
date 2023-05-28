brute force- We can take another array, and fill the array according to question,
but in this , space comp.=O(n^2)
optimal solution:
we will first transpose the matrix and then reverse the rows of the matrix;
In transpose, Only 0 to n-1 rows will be traversed, and in every row, we will traverse from i+1 column to end column, it order to remove swapping two times.
time comp. = O(n/2 * n/2)
n/2 almost for 1 st loop and almost n/2 for second loop.
Space comp. = O(1)
For reversing the rows, we will iterate to half in every row using two pointers and swap the elements with the end ke elments.
Also, in the loops, we can either iterate on the upper triangle in n-1 rows and swap the elments or in the lower triangle in all rows and swap accordingly.
