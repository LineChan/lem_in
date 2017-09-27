#   Lem_in
* [Subject](#subject)
* [Method](#method)
* [Help](#help)

#   Subject   :pushpin:

Lem_in is a path finding game. The goal is to find the quickest way to get all ants from an anthill from the entrance to the exit. At the **beginning of the game**, all the ants are in the room ##start. At **each turn**, an ant can only move once through a tube. Be careful, the receiving room must be empy because it can only contain one ant at a time (except for the ##end room). The game is done when all the ants are in the exit room.

Here is an example of an input :
```C
/* Number of ants */
7

/* Room List : room_name x_position y_position */
##start
r_start 00 00
r_1 10 60
r_2 40 30
r_3 40 00
r_4 45 70
r_5 70 20
r_6 30 60
##end
r_end 70 70

/* Tube List : room_name1-room_name2 */
r_start-r_1
r_start-r_2
r_start-r_3
r_1-r_6
r_4-r_6
r_4-r_end
r_2-r_end
r_3-r_5
r_5-r_end
```

Allowed function : write, read, malloc, free, exit, strerror, perror

### Libraries :books:
- **libft** : personnal library with functions from libc.h (printf from stdio.h for instance)
- **liblst** : personnal library with a set of tools to manipulate Linux-like linked lists
- **pygame** : for bonuses only

#  Method















# lem_in
School Project : Algorithm (2)
Sources : 
- MIT Open Course Ware :
	- Breadth-First Search https://www.youtube.com/watch?v=s-CYnVz-uh4&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=13
	- Depth-First Search, topological sort : https://www.youtube.com/watch?v=AfSk24UTFS8&index=14&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb
	- Single source shortest path : https://www.youtube.com/watch?v=Aa2sqUhIn-E&index=15&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb
	- Djisktra : https://www.youtube.com/watch?v=2E7MmKv0Y24&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=16
	
University of British Colombia pdf : 
	- Iterative deepening and IDA* : http://www.cs.ubc.ca/~mack/CS322/lectures/2-Search6.pdf

Geek for geeks website :
	- Iterative Deepening Search http://www.geeksforgeeks.org/iterative-deepening-searchids-iterative-deepening-depth-first-searchiddfs/

Path finding algorithm visualisation : https://qiao.github.io/PathFinding.js/visual/

Lex and Yacc : http://www.linux-france.org/article/devl/lexyacc/minimanlexyacc.html#toc2


