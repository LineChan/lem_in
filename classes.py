import pygame
import settings as s

class Room(object) :
    def __init__(self, ref, name, x, y) :
        self.ref = ref
        self.name = name
        self.x = float(x / 100) * s.screen_width
        self.y = float(y / 100) * s.screen_height
        self.img = pygame.image.load("img/room_" + str(ref) + ".png")
        self.rect = self.img.get_rect()
        self.rect.topleft = [self.x + float(s.offSet[ref][0] / 100) * self.rect.width, self.y + float(s.offSet[ref][1] / 100) * self.rect.height]
        s.roomList.append(self)

    def update() :
        [s.screen.blit(room.img, (room.x, room.y)) for room in s.roomList]

class Ant(object) :
    def __init__(self, ref) :
        self.state = True
        self.ref = ref
        self.img = pygame.image.load("img/ant_" + str(ref) + ".png")
        self.rect = self.img.get_rect()
        self.rect.topleft = [s.roomList[0].rect.topleft[0] - self.rect[2] * 0.5, s.roomList[0].rect.topleft[1] - self.rect[3]]
        s.antList.append(self)

    def update() :
        #[s.screen.blit(ant.img, ant.rect) for ant in s.antList if ant.state == True]
        [s.screen.blit(ant.img, ant.rect) for ant in s.antList]

class Tube(object) :
    def __init__(self, room1, room2) :
        self.room1 = room1
        self.room2 = room2
        s.tubeList.append(self)

class Move(object) :
    def __init__(self, List, ant, room) :
        self.ant = ant
        self.room = room
        List.append(self)
