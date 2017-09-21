import settings as s
from classes import Room as Room


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
        s.roomList.append(Room(roomRef, split[0], int(split[1]), int(split[2])))
        roomRef += 1
    while roomIndexes :
        del inputList[roomIndexes[-1]]
        del roomIndexes[-1]

def room(inputList) :
    inputList[:] = (line[:-1] for line in inputList if (line != '\n'))
    startEndRoom(inputList)
    s.antNb = int(inputList[0])
    if (s.antNb < 1) or (s.antNb > s.antMax) :
        print('Error : the number of ants has to be between 1 and 7')
        sys.exit(1)
    del inputList[0]
    otherRoom(inputList)

