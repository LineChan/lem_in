import sys
import subprocess
import pygame
import parse
import execute
import settings as s
from settings import init as init
from settings import display as display
from classes import Room as Room
from classes import Ant as Ant


def main(proc) :
    init()

    # -------- Parsing -------
    inputList = []
    inputList = proc.stdout.readlines()
    inputList[:] = [str(line, 'utf-8') for line in inputList]
    if inputList == ['\x1b[31;1merror\x1b[0m\n'] :
        print('Error in lem-in resolution')
        return
    parse.room(inputList)
    print('roomList : %s' % (s.roomList))
    parse.tube(inputList)
    turnMax = len(inputList)
    for each in s.tubeList :
        room1 = s.roomList[each.room1].rect.topleft
        room2 = s.roomList[each.room2].rect.topleft
        print('[%d][%d]\n[%d][%d]\n\n' % (room1[0], room1[1], room2[0], room2[1]))

    # --------- Loop ---------
    crashed = False
    do = False
    turn = -1
    while not crashed : 
        for event in pygame.event.get() :
            if event.type == pygame.QUIT :
                crashed = True

        if event.type == pygame.KEYDOWN :
            if event.key == pygame.K_ESCAPE :
                pygame.quit()
                quit()
            # -------- Execute a turn -------
            if event.key == pygame.K_SPACE and not do :
                turn += 1
                if (turn < turnMax) :
                    execute.turn(inputList[turn])
                    do = True

        if event.type == pygame.KEYUP :
            if event.key == pygame.K_SPACE :
                do = False
            if turn > turnMax :
                # move ant move
                turn = -1 

        display()

    pygame.quit()
    quit()




if __name__ == "__main__" :
    #subprocess.run(["make re"], shell = True, check = True)
    proc = subprocess.Popen(["./lem-in <" + sys.argv[1] + " 2> /dev/null"], shell = True, stdin = subprocess.PIPE, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
    main(proc)
