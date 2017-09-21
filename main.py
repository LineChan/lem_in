import sys
import subprocess
import pygame
import parse
from settings import init as init
from settings import display as display
from classes import Room as Room
from classes import Ant as Ant

def main(proc) :
    init()
    # -------- Parsing -------
    inputList = []
    inputList = proc.stdout.readlines()
    parse.room(inputList)

    return
    # --------- Loop ---------
    crashed = False
    do = False
    while not crashed : 
        for event in pygame.event.get() :
            if event.type == pygame.QUIT :
                crashed = True

        if event.type == pygame.KEYDOWN :
            if event.key == pygame.K_ESCAPE :
                pygame.quit()
                quit()
            if event.key == pygame.K_SPACE and not do :
                print('do something !')
                do = True

        if event.type == pygame.KEYUP :
            if event.key == pygame.K_SPACE :
                do = False

        display()

    pygame.quit()
    quit()




if __name__ == "__main__" :
    #subprocess.run(["make re"], shell = True, check = True)
    proc = subprocess.Popen(["./lem-in <" + sys.argv[1] + " 2> /dev/null"], shell = True, stdin = subprocess.PIPE, stdout = subprocess.PIPE, stderr = subprocess.PIPE)
    main(proc)
