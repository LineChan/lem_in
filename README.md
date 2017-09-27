School Project : Algorithm (2)

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

The output of the program is displayed like this :
- Number of ants
- Room List
- Tube List
- L1-x L2-y L3-z ... 1,2,3 represents the ants' numbers and x,y,z the rooms' names

```C
/* each line represents one move */
L1-r_2
L1-r_end L2-r_2
L2-r_end L3-r_2
L3-r_end L4-r_2
L4-r_end L5-r_2
L5-r_end L6-r_2
L6-r_end L7-r_2
L7-r_end
```

```C
/* each line represents one move */
<start>         : <newline> <ant> <room_list> <tube_list>
| <ant> <room_list> <tube_list>

<ant>           : <number> <new_line>

<new_line>      : '\n' <new_line>
| '\n'

<number>        : <digit> <number>
| <digit>

<digit>         : '0' .. '9'

<room_list>     : <room_id> <new_line> <room_list>
| <room_id> <new_line>
| '#' <command> <new_line> <room_list>
| '#' <command> <new_line>
| '#' <word> <new_line> <room_list>
| '#' <word> <new_line>

<room_id>       : <room_name> ' ' <number> ' ' <number>

<command>       : '#' <command_start>
| '#' <command_end>
| '#' <word> /*---> the ligne is ignored */

<command_start> : "START" <new_line> <room_id> <new_line>

<command_end>   : "END" <new_line> <room_id> <new_line>

<tube_list>     : <tube_id> <new_line> <tube_list>
| <tube_id> <new_line>
| '#' <word> <new_line> <tube_list>
| '#' <word> <new_line>

<room_name>     : <first_letter> <word>
| <first_letter>

<word>          : <letter> <word>
| <letter>

<first_letter>  : [A..Z] - L
| [a..z]
| <number>

<letter>        : <first_letter>
| 'L'
| ' '
| '#'
| '_'
| '.'

<tube_id>          | <room_name> '-' <room_name> <new_line>
```

**Allowed function** : write, read, malloc, free, exit, strerror, perror

### Libraries :books:
- **libft** : personnal library with functions from libc.h (printf from stdio.h for instance)
- **liblst** : personnal library with a set of tools to manipulate Linux-like linked lists
- **pygame** : for bonuses only

#  Method

## Parsing

## Path finding algorithm

## Computing moves

#  Bonuses

- [ ] Call and caller graphs of the project
- [x] Chose of the number of shortest paths that can be found
- [x] Interactive visualization

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
	> ./lem-in [--shortest_path nb] < ant_farm_map.txt 

**shortest_path nb** : by default the program finds all possible shortest path. The proccess can be a bit slow for a hight number of rooms and tubes so it is possible to restrain the solutions with this option

	> python3 main.c ant_farm_map.txt

**visualisation** :
#  Result
Peer evaluation not done yet.
