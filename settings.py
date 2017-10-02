from classes import Room as Room
from classes import Ant as Ant
from classes import Tube as Tube
import pygame

def init() :
    # ------------ Colors -------------
    global white, black, greenGrass, brownPath
    white = (255,255,255)
    black = (0,0,0)
    greenGrass = (197, 210, 91)
    brownPath =  (107, 113, 45)

    # ------- Pygame parameters -------
    pygame.init()
    pygame.display.set_caption('lem-in : ESC to quit, SPACE to execute next turn')
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
    offSet = [[18,0], [40,40], [35,0], [30,30], [30,10], [15,-10], [20,50], [0,0]] 
    global roomList, antList, tubeList
    roomList, antList, tubeList = [], [], []

    # ----------- Variables -----------
    global antMax, antNb
    antMax, antNB = 7, 0
    global roomMax
    roomMax = 8
    global step
    step = 10

def display() :
    screen.fill(greenGrass)
    Tube.update()
    Room.update()
    Ant.update()
    pygame.display.update()
