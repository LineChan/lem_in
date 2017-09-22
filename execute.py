import settings as s
from classes import Move as Move

# topleft[0] : (s.offSet[0][0]/ 100 + 1) * s.roomList[0].x - self.rect[2] * 0.5
def moveAnt(currentTurn) :
    #for each in currentTurn :
        #if (ant
    for each in currentTurn :
        print('ant_%d --> %s' % (each.ant.ref, each.room.name))
    

# ------------- Parse turn------------- 
def turn(turn) :
    move = turn.split()
    currentTurn = []
    for each in move :
        split = each[1:].split('-')
        ant = next(ant for ant in s.antList if (int(split[0]) == ant.ref))
        room = next(room for room in s.roomList if (split[1] == room.name))
        Move(currentTurn, ant, room)
        #print('%d --> %s' % (ant.ref, room.name))
    moveAnt(currentTurn)

