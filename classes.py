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
        self.rect.topleft = [s.roomList[0].rect.topleft[0], s.roomList[0].rect.topleft[1]]
        s.antList.append(self)
    def update() :
        #[s.screen.blit(ant.img, ant.rect) for ant in s.antList if ant.state == True]
        [s.screen.blit(ant.img, ant.rect) for ant in s.antList]

class Tube(object) :
    def __init__(self, xpos1, ypos1, xpos2, ypos2, xstep, ystep) :
        self.xpos1 = xpos1
        self.ypos1 = ypos1
        self.xpos2 = xpos2
        self.ypos2 = ypos2
        self.xstep = xstep
        self.ystep = ystep
        s.tubeList.append(self)
    def update() :
        for t in s.tubeList :
            pygame.draw.line(s.screen, s.black, (t.xpos1, t.ypos1), (t.xpos1 + t.xstep, t.ypos1 + t.ystep))
            pygame.draw.line(s.screen, s.black, (t.xpos1 + t.xstep, t.ypos1 + t.ystep), (t.xpos2, t.ypos2))

class Move(object) :
    def __init__(self, List, ant, room) :
        self.ant = ant
        self.room = room
        List.append(self)
