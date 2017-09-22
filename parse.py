import settings as s
from classes import Room as Room
from classes import Ant as Ant
from classes import Tube as Tube
#from classes import Move as Move


# -------------------- Room parsing ---------------------

def startEndRoom(inputList) :
    index = inputList.index('##start') + 1
    split = inputList[index].split()
    Room(0, split[0], int(split[1]), int(split[2]))
    del inputList[index]

    index = inputList.index('##end') + 1
    split = inputList[index].split()
    Room(1, split[0], int(split[1]), int(split[2]))
    del inputList[index]
    inputList[:] = (line for line in inputList if (line[0] != '#'))

def otherRoom(inputList) :
    roomRef = 2
    roomIndexes = [i for i, line in enumerate(inputList) if line[0] != 'L' and len(line.split()) == 3]
    for i in roomIndexes :
        if (roomRef >= s.roomMax) :
            print('Error : Visualization not allowed for more than %d rooms' % (s.rromMax))
            sys.exit(1)
        split = inputList[roomIndexes[i]].split()
        Room(roomRef, split[0], int(split[1]), int(split[2]))
        roomRef += 1
    while roomIndexes :
        del inputList[roomIndexes[-1]]
        del roomIndexes[-1]

def room(inputList) :
    inputList[:] = (line[:-1] for line in inputList if (line != '\n'))
    startEndRoom(inputList)
    s.antNb = int(inputList[0])
    if (s.antNb < 1) or (s.antNb > s.antMax) :
        print('Error : the number of ants has to be between 1 and %d' %(s.antMax))
        sys.exit(1)
    for n in range(1, s.antNb + 1) :
        Ant(n)
    del inputList[0]
    otherRoom(inputList)

# -------------------- Tube parsing ---------------------
def tube(inputList) :
    tubeIndexes = [i for i, line in enumerate(inputList) if line[0] != 'L']
    for i in tubeIndexes :
        roomPair = inputList[tubeIndexes[i]].split('-')
        try :
            room1 = (next(x for x in s.roomList if (roomPair[0] == x.name)))
            room2 = (next(x for x in s.roomList if (roomPair[1] == x.name)))
        except StopIteration :
            break
        Tube(room1, room2)
    inputList[:] = (line for line in inputList if (line[0] == 'L'))

'''
# -------------------- Tube parsing ---------------------
def move(inputList) :
    inputList[:] = (line for line in inputList if (line[0] == 'L'))
    currentTurn = 0
    for line in inputList :
        turn = line.split()
        for each in turn :
            split = each[1:].split('-')
            Move(currentTurn, next(x for x in s.antList if (int(split[0]) == x.ref)),next(x for x in s.roomList if (split[1] == x.name)))
        currentTurn += 1
'''
