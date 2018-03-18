# Mwagh
RMIT C++ codes

Our job was to create a PageRank. This will tell us the number of links from webpage i to webpage j. We were given specific instructions (mentioned in the assignment pdf) on what type of functions we had to create and how they should implement. We were only given one sample input case, who's output case was also given. However, in order to successfully complete the assignment, the code would be tested with 78 hidden inputs on Hackerrank. Hackerrank is an online portal for competitive coding. There were 75 test cases on hackerrank which tested whether the code would run in all kinds of situations. I'll share an example input with expected output and you can check it on my code. I'll also write what each line of code is doing.
Initially we create a sparsematrix header that only points to itself. As we add elements, we add row headers and column headers, thus creating an entire matrix of circular linked lists. All nodes in the list are connected horizontally and vertically. Initially everything points to itself. As we add elements within rows and columns, we build our matrix.
10 -> This input is the number of operations which you want to implement  
1 -> Adding link  
0 1 -> You are creating a link at 0,1 with value 1  
1 -> Adding link  
0 2 -> Creating a link at 0,2  
1 -> Adding link  
3 4 -> Creating a link at 3,4  
1 -> Adding link  
0 1 -> Adding a link to the already existing one at 0,1 (Now, value of this link become 2)  
3 -> Display link  
0 4 -> At 0,4 we dont have any link, so we should get an output of 0.  
4 -> Sum of row values  
1 100 -> Adding elements of row 1 until column 100. We have value 2 at 0,1 and that is it. So output will be 2  
5 -> Sum of column values  
0 100 -> Value 2 at 0,1 and value 1 at 0,2. So addition of values = 3. Output will be 3.  
2 -> Deleting node  
0 2 -> Removing existence of node at 0,2. (Also as row 2 now doesnt have any element, it will get deleted)  
5 -> Sum of column values  
0 100 -> Now there is not value at 0,2. So on value 2 of 0,1 will be counted. Output will be 2.  
6 -> Matrix multiplication  
5 1 2 3 4 5 -> We have to assume a matrix in the sparse matrix and multiply it with the entered column matrix.  
We currently have   
[0 0 0 0 0         [1             [0  
 2 0 0 0 0          2              2  
 0 0 0 0 0    *     3      =       0  
 0 0 0 0 0          4              0  
 0 0 0 4 0]         5]             4]  

This is the only example test case I have. 
If you wish to use your own input cases, this is how you must proceed.  
1) Type in the number of operations (add, delete etc.) you want to use  
2) Type in the operations. Operations add, link, retrieve value, row sum and column sum all take in two standard (cin) inputs. They are integers which signify the particular index of the matrix that needs to be added/deleted etc.  
3) Add and Delete will have no output. Retrieve, row sum and column sum output one number.   
4) for matrix multiplication, you must specify a size of matrix and then enter numbers into an array which forms a column matrix. On multiplying a sub-matrix of specified size with the entered matrix, you will get standard output (cout) in the form of the resultant product matrix, whose size will be the same as that of the specified column matrix.   
