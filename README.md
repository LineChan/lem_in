School Project : Algorithm (2)

#   Lem_in
* [Subject](#subject)
* [Method](#method)
* [Help](#help)

#   Subject   :pushpin:

Lem_in is a path finding game. The goal is to find the quickest way to get all ants from an anthill from the entrance to the exit. At the **beginning of the game**, all the ants are in the room ##start. At **each turn**, an ant can only move once through a tube. Be careful, the receiving room must be empy because it can only contain one ant at a time (except for the ##end room). The game is done when all the ants are at the exit.

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
// <new_line> to add
<start>         : <ant> <new_line> <room_list> <new_line> <tube_list>

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

<command_start> : "start" <new_line> <room_id>

<command_end>   : "end" <new_line> <room_id>

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

<new_line>      : '\n'
```

NB : you can visualize the parsing process with the **--parsing** option

## Path finding algorithm

The anthill with its rooms and tubes can be analyzed as a graph that is:
- **unweighted** : all the edges have the same weight (it costs one turn each time an ant moves)
- **undirected** : there is no directed edges (an ant go through a tube in both directions)
- **cyclic** : there are circles in the graph (possibility to go twice in the same room withe same ant)

To find solutions I decided to implement an **Iterative Deepening Depth-First Search** (IDDFS). I chose that algorithm because it combines Breadth-First Search's ([BSF](http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/)) fast search (for vertices closer to root) and Depth-Dirst Search's ([DSF](http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/)) space-efficiency. Also, the IDDSF guarentees that each path found is **the shortest one** available.

The IDDSF calls DFS for different depths starting from an initial value. In every call, DFS is restricted from going beyond given depth. Because it is a DSF executed in a BFS fashion, the algorithm is easy to adapt to find **multiples shortest paths** by giving different initial values.

![graph](/img/readme_img.png)

Top level nodes are visited **multiples times**. The last (or max depth) level is visited once, second last level is visited twice, and so on. It may seem expensive, but it turns out to be not so costly, since in a tree most of the nodes are in the bottom level. So it does not matter much if the upper levels are visited multiple times.

Because the IDDFS works only on **acyclic** graphs, I used an [adjacency matrix](https://en.wikipedia.org/wiki/Adjacency_matrix) I adapted so a vertex can't be visited multiple times (see :arrow_down: DLS). The matrix can take 3 values :
- 1 : if the pairs of vertices are adjacent (there is a tube between two rooms)
- 0 : if not
- -1 : if the vertex has already been visited

### IDDFS
In our case, the **maximum depth** is the number of rooms (ROOM_NB). Indeed, if there is a solution, the longest path possible goes through all rooms once. Before starting the IDDFS, the **maximal number of shortest paths** (SP_NB) is also defined. We simply look the number of rooms linked to the ##start and ##end rooms and take the lower number.

Example : the ##start rooms has 2 tubes and the ##end room has 3 tubes--> SP_NB = 2 . In the best case, both paths are shortest paths from ##start to **2 out of 3 adjacent rooms** of ##end.

```C
int              ft_iddfs(void)
{
	int          limit;

	limit = 0;

	/* Loop until all the shortest path aren't found */
	while (SP_NB > 0)
	{
		/* Repeadted Depth-Limit Search until the maximum depth */
		while (limit < ROOM_NB)
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

### DLS
Depth-Limit Search is a recursive function that starts from a given source and stops when the ##end room is found or the depth limit is reached (no solution). 
At each source vertex given the adjacency matrix is 


```C
static int       ft_dls(const int src_ref, const int limit)
{
	int          i;

	/* Result found */
	if (src_ref == END_REF)
		return (1);

	/* Limit depth reached*/
	if (limit <= 0)
	{
		ft_reset_matrix();
		return (0);
	}
	i = 0;

	/* Set the node as visited */
	while (i < ROOM_NB)
	{
		if (!(MATRIX[i][src_ref] ^ 1))
			MATRIX[i][src_ref] = -1;
		++i;
	}

	/* Start DLS from adjacent nodes */
	if (ft_explore_adjacent(src_ref, limit))
		return (1);
	return  (0);
}
```

### Exploring adjacent nodes

```C
static int         ft_explore_adjacent(const int ref, const int limit)
{
	int            i;
	int            j;

	i = 0;
	while (i < ROOM_NB)
	{
		/* If it is an adjancent and on the shortest path */
		if ((MATRIX[ref][i] == 1) && (ft_dls(i, limit - 1)))
		{
			if (i != END_REF)
			{
				/* If it isn't the ##end room, move the room from the anthill
				to the shortest path list */
				ft_lst_moveto_next(ft_find_room_with_ref(&ANTHILL, i), &PATH(SHORTEST_PATH.prev));
				j = 0;
				/* Removing the room from matrix by setting the value to 0 */
				while (j < ROOM_NB)
					ft_set_matrix(i, j++, 0);
			}
			else
			{
				/* Create a shortest path list and copy the ##end room at the end of it */
				/* NB : Because the IDDFS always finds the shortest path,
				solutions are sorted from the shortest to the longest) */
				ft_add_shortest_path();
				ft_copy_end_room_to_path();
			}
			++PATH_LEN(SHORTEST_PATH.prev);
			return (1);
		}
		++i;
	}
	return (0);
}
```

## Computing moves

Now that we have SP_NB shortest path, ants need to be sent on these paths. To minimize the number of moves, paths are taken according to these rules :
- **1st shortest path** (best solution) : an ant is sent at each turn
- **Other paths** : an ant is sent if only it is less cost-effective to take the current path than the shortest one.

```C
if (PATH_LEN(current_path) <= ((ANT_NB - current_ant) * PATH_LEN(BEST_SHORTEST_PATH)))
	ft_sent_ant(&PATH(current_path), &current_ant);
```

#  Bonuses

- [ ] Call and caller graphs of the project
- [x] Parsing details
- [x] Chose of the number of shortest paths that can be found
- [x] Interactive anthill visualization

![visual](/img/readme_visual.png)

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

- Others :
	- [*Path finding algorithm visualisation*](https://qiao.github.io/PathFinding.js/visual/)

	- [*Lex and Yacc*](http://www.linux-france.org/article/devl/lexyacc/minimanlexyacc.html#toc2)

# Help :heavy_exclamation_mark:
	> ./lem-in [--parsing] [--shortest_path=nb] < ant_farm_map.txt 

**parsing** : shows the grammatical analysis of the parsing
**shortest_path nb** : by default the program finds all possible shortest path. The proccess can be a bit slow for a hight number of rooms and tubes so it is possible to restrain the solutions with this option

	> python3 main.c ant_farm_map.txt

**visualisation** : (work in progress)

#  Result
Peer evaluation not done yet.
