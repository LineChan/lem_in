School Project : Algorithm (2)

#   Lem_in
* [Subject](#subject)
* [Method](#method)
* [Help](#help)

#   Subject   :pushpin:

Lem_in is a path finding game. The goal is to find the quickest way to get all ants from an anthill from the entrance to the exit. At the **beginning of the game**, all the ants are in the room ##start. At **each turn**, an ant can only move once through a tube. Be careful, the receiving room must be empy because it can only contain one ant at a time (except for the ##end room). The game is done when all the ants are in the exit room.

Here is an example of an input :
```C
7                    /* Number of ants */
##start              /* Rooms' List : room_name x_position y_position */
r_start 00 00
r_1 10 60
r_2 40 30
r_3 40 00
r_4 45 70
r_5 70 20
r_6 30 60
##end
r_end 70 70
r_start-r_1          /* Tubes' List : room_name1-room_name2 */
r_start-r_2
r_start-r_3
r_1-r_6
r_4-r_6
r_3-r_5
r_4-r_end
r_2-r_end
r_5-r_end
```

The output of the program is displayed like this :
- Number of ants
- Room List
- Tube List
- L1-x L2-y L3-z ... 1,2,3 represents the ants' numbers and x,y,z the rooms' names

```C
L1-r_2 L2-r_3 L3-r_1                         /* each line represents a move */
L1-r_end L4-r_2 L2-r_5 L5-r_3 L3-r_6
L4-r_end L6-r_2 L2-r_end L5-r_5 L3-r_4
L6-r_end L7-r_2 L5-r_end L3-r_end
L7-r_end
```

**Allowed function** : write, read, malloc, free, exit, strerror, perror

### Libraries :books:
- **libft** : personnal library with functions from libc.h (printf from stdio.h for instance)
- **liblst** : personnal library with a set of tools to manipulate Linux-like linked lists
- **pygame** : for bonuses only

#  Method

## Parsing

For the parsing I made a **grammatical analysis** of the input format and build my function according to it.
Note : Any unknown command is ignored (lines starting with ##) and any non compliant or empty lines will automatically stop the parsing. The programm process only the already acquired data.

```C
<start>         : <ant> <room_list> <tube_list>

<ant>           : <number>

<number>        : <digit> [<number>]

<digit>         : [0-9]

<room_list>     : <room_id> <new_line> [<room_list>]
                | '#' <command> <new_line> [<room_list>]
                | '#' <word> <new_line> [<room_list>]

<room_id>       : <room_name> ' ' <number> ' ' <number>

<command>       : '#' <command_start>
                | '#' <command_end>
                | '#' <word>

<command_start> : "start" '\n' <room_id>

<command_end>   : "end" '\n' <room_id>

<tube_list>     : <tube_id> [<tube_list>]
                | '#' <word> [<tube_list>]

<room_name>     : <first_letter> [<word>]

<word>          : <letter> [<word>]

<first_letter>  : [A-Z] - L
                | [a-z]
                | <number>

<letter>        : <first_letter>
                | ['L',' ','#', '-', '.']

<tube_id>       : <room_name> '-' <room_name> <new_line>
```

NB : you can visualize the parsing process with the **--parsing** option

## Path finding algorithm

To find solutions I decided to implement an **Iterative Deepening Depth-First Search** (IDDSF). I chose that algorithm because it combines Breadth-First Search's ([BSF](http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/)) fast search (for nodes closer to root) and Depth-Dirst Search's ([DSF](http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/)) space-efficiency.

IDDSF calls DFS for different depths starting from an initial value. In every call, DFS is restricted from going beyond given depth. Because it is a DSF executed in a BFS fashion, the algorithm is easy to adapt to find **multiples shortest paths** by taking different initial values.

In our case, the **maximum depth** is the number of tube (TUBE_NB). Indeed, if there is a solution, the longest path possible goes through all the rooms on the map. Before starting the IDDFS, the maximal number of shortest paths (SP_NB) is also defined. We simply look the number of rooms linked to the ##start and ##end rooms and take the lower number.
Example : the ##start rooms has 2 tubes and the ##end room has 3 tubes--> SP_NB = 2
In the best case, both paths are shortest paths from ##start to the **3 adjacent rooms** of ##end.

```C
int                                ft_iddsf(void)
{
	int                limit;

	limit = 0;
	/* Loop until all the shortest path aren't found */
	while (SP_NB > 0)
	{
		/* Repeadted Depth-Limit Search until the maximum depth */
		while (limit < TUBE_NB)
		{
			if (ft_dls(START_REF, limit))
				break ;
			++limit;
		}
		--SP_NB;
	}
	if (ft_lst_is_head(&SHORTEST_PATH))
		return (0);
	return (1);
}
```
## Computing moves

#  Bonuses

- [ ] Call and caller graphs of the project
- [x] Parsing details
- [x] Chose of the number of shortest paths that can be found
- [x] Interactive anthill visualization

[work in progress] : a short presentation of the visual

#  Sources :bookmark_tabs:

- MIT Open Course Ware :
	- [*Breadth-First Search*](https://www.youtube.com/watch?v=s-CYnVz-uh4&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=13)
	- [*Depth-First Search, topological sort*](https://www.youtube.com/watch?v=AfSk24UTFS8&index=14&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
	- [*Single source shortest path*](https://www.youtube.com/watch?v=Aa2sqUhIn-E&index=15&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb)
	- [*Djisktra*](https://www.youtube.com/watch?v=2E7MmKv0Y24&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=16)
- University of British Colombia pdf : 
	- [*Iterative deepening and IDA* *](http://www.cs.ubc.ca/~mack/CS322/lectures/2-Search6.pdf)

- Geek for geeks website :
	- [*Iterative Deepening Search*](http://www.geeksforgeeks.org/iterative-deepening-searchids-iterative-deepening-depth-first-searchiddfs/)

[*Path finding algorithm visualisation*](https://qiao.github.io/PathFinding.js/visual/)

[*Lex and Yacc*](http://www.linux-france.org/article/devl/lexyacc/minimanlexyacc.html#toc2)

# Help :heavy_exclamation_mark:
	> ./lem-in [--parsing] [--shortest_path=nb] < ant_farm_map.txt 

**parsing** : shows the grammatical analysis of the parsing
**shortest_path nb** : by default the program finds all possible shortest path. The proccess can be a bit slow for a hight number of rooms and tubes so it is possible to restrain the solutions with this option

	> python3 main.c ant_farm_map.txt

**visualisation** : (work in progress)

#  Result
Peer evaluation not done yet.
