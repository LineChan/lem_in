from classes import Room as Room
from classes import Ant as Ant
from classes import Tube as Tube
import pygame

def init() :
    # ------------ Colors -------------
    global white, black
    white = (255,255,255)
    black = (0,0,0)
    #red = (255,0,0)
    #green = (0,255,0)
    #blue = (0,0,255)
    #darkBlue = (0,0,128)

    # ------- Pygame parameters -------
    pygame.init()
    pygame.display.set_caption('lem-in : ESC to quit')
    global clock
    clock = pygame.time.Clock()
    clock.tick(60)

    # ------- Screen parameters -------
    global screen_width, screen_height
    screen_width, screen_height = 1400, 750
    global screen
    screen = pygame.display.set_mode((screen_width, screen_height))
    screen.fill(white)

    # ------------- Lists -------------
    global offSet
    offSet = [[18,0], [0,0], [0,0], [30,30], [0,0], [0,0]] 
    global roomList, antList, tubeList
    roomList, antList, tubeList = [], [], []

    # ----------- Variables -----------
    global antMax, antNb
    antMax, antNB = 7, 0
    global roomMax
    roomMax = 7
    global step
    step = 10

def display() :
    screen.fill(white)
    Tube.update()
    Room.update()
    #pygame.draw.line(screen, black, [roomList[0].rect.topleft[0], roomList[0].rect.topleft[1]], [roomList[1].rect.topleft[0], roomList[1].rect.topleft[1]])

    Ant.update()
    pygame.display.update()
