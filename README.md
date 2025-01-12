## PUSH SWAP (with bonus)

(more detailed readme about the project requirements and used algorithm and implementation will follow)<br>
<br> 
In the meantime, try the program by typing make and then ./push_swap followed by a list of integers<br>
Example:<br>
$>./push_swap 2 1 3 6 5 8<br>
The program will print a list of operations needed to sort these numbers in ascending order, by pushing elements from stack A to stack B or the other way around or previously rotating the stacks seperatley or together. The goal is to get as little amount of operations as possible.<br> 
<br>
The bonus is to build our own checker progam, which verifies if the provided list of operations indeed sorts the stack correctly.<br>
To run this, type make bonus and then pipe the output into the program.<br>
Example:<br>
$>./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8<br>
If the operations provided by the push_swap program are indeed making sure the stack is sorted at the end, the checker program displays OK, otherwise it displays KO. 
