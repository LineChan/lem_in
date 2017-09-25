import settings as s
from settings import display as display
from classes import Move as Move


# ---- Check if ant moves are done ----
def check(expectedAnt) :
    for each in expectedAnt :
        if each :
            return (1)
    return (0)

# ------------- Move Ant ------------- 
def moveAntHome() :
    
    start = 1
    s.step = 30
    while start < s.antNb + 1 :
        for x in range (0, start) :
            moveAnt(x, 0)
        display()
        start += 1
    s.step = 10
    start = 0
    while (start < s.antNb) :
        for ref in range(start, s.antNb) :
            if not moveAnt(ref, 0) :
                start += 1
        display()
        
def moveAnt(ant, room) :
    xpos = s.antList[ant].rect.topleft[0]
    ypos = s.antList[ant].rect.topleft[1]
    xroom = s.roomList[room].rect.topleft[0]
    yroom = s.roomList[room].rect.topleft[1]
    if ([xpos, ypos] == [xroom, yroom]) :
        return (0)
    if (xpos < xroom) :
        xpos += s.step
    else :
        xpos -= s.step
    if (ypos < yroom) :
        ypos += s.step
    else :
        ypos -= s.step
    if (xpos >= xroom - s.step) and (xpos <= xroom + s.step) :
        xpos = xroom
    if (ypos >= yroom - s.step) and (ypos <= yroom + s.step) :
        ypos = yroom
    s.antList[ant].rect.topleft = [xpos, ypos]
    return (1)
    
# ------------- Execute Turn ------------- 

def turn(turn) :
    move = turn.split()
    currentTurn = []
    print('move : %s' % move )
    for each in move :
        split = each[1:].split('-')
        try :
            Move(currentTurn, int(split[0]), next(x for x in s.roomList if (split[1] == x.name)).ref)
        except StopIteration :
            pass
    expectedAnt = []
    for n in range(len(currentTurn)) :
        expectedAnt.append(1)
    while (check(expectedAnt)) :
        for each in currentTurn :
            if not moveAnt(each.ant - 1, each.room) :
                expectedAnt[currentTurn.index(each)] = 0
        display()
