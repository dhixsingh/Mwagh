
# Mwagh
RMIT C++ codes


1) AVLtree.cpp
This assignment is to implement several concepts of Data Structures, like Binary Search Trees, Merge Sort algorithm, and AVL trees. 

Project :-
You have to display shares in a sorted AVL tree.[An AVL tree is a binary search tree which is balanced]. It will display the price of the stocks of various companies.
Also, it will only display changes in the share prices if it is beyond a fixed threshold.

To-Do :-
i.Implement merge sort algorithm for pre-sorting the stocks
ii.Construct an AVL tree from these sorted key value pairs
iii.Support the following operations:

a)register-company <company-id> <initial-price>: Insert a new node in the AVL Tree
with the given company-id and price. Print the company-id and the stock price separated
by a space(see output format).

b)deregister-company <company-id>: Remove all data of the company with the given
company-id.

c)update-price <company-id> <new-price>: You must update the price of the given company-
id, if the above given rule is satisfied. Also in case the rule is satisfied, you must broadcast
 the current price. Ignore operation if given stock does not exist.

d)stock-split <company-id> <x:y>: Update the price of the company-id given that its stocks
are split in the ratio x:y. (Note: This operation also covers reverse stock split, i.e.
it is possible that x < y.) Publish the updated stock price. Ignore operation if given
stock does not exist.

INPUT format
 The first line of the input contains a single integer n - the no. of stocks to be bulk loaded.
 Following n lines contains 2 space separated integers - comapny id and initial price - representing the n initial stocks.
 Next line has 2 space separated integers: N - the no. of subsequent operations to be performed
on the AVL Tree and T - the threshold parameter of the MDP (see rule above).
 Next N lines consist of 1 operation each in the following format: <operation-code> [params].
Code Operation
1 register-company
2 deregister-company
3 update-price
4 stock-split

OUTPUT (expected)
 Operation 1 outputs the initial price of the stock
 There is no output for Operation 2.
 Operation 3 may or may not publish the new price of the stock based on the condition jnewPrice􀀀
lastPublishedP ricej > threshold.
 Operation 4 always publishes the modified price.

Sample Input

5  
11 10  
5 4  
72 91  
35 42  
12 12  
10 5  
1 100 100  
3 12 20  
3 12 21  
3 11 31  
3 12 15  
3 12 14  
4 100 2:1  
2 100  
3 100 70  
3 11 30  

Sample Expected Output

100 100  
12 20  
11 31  
12 14  
100 50  
