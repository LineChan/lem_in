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
    def __init__(self, room1, room2) :
        self.room1 = room1
        self.room2 = room2
        s.tubeList.append(self)
    def update() :
        for each in s.tubeList :
            #print('%s [%d][%d] ----> %s [%d][%d]' % (each.room1, s.roomList[each.room1].rect.topleft[0], s.roomList[each.room1].rect.topleft[1], each.room2, s.roomList[each.room2].rect.topleft[0], s.roomList[each.room2].rect.topleft[1]))
            xpos1 = s.roomList[each.room1].rect.topleft[0] + 0.5 * s.antList[0].rect.width
            ypos1 = s.roomList[each.room1].rect.topleft[1] + s.antList[0].rect.height
            xpos2 = s.roomList[each.room2].rect.topleft[0] + 0.5 * s.antList[0].rect.width
            ypos2 = s.roomList[each.room2].rect.topleft[1] + s.antList[0].rect.height
            #step = m
            pygame.draw.line(s.screen, s.black, (xpos1, ypos1), (xpos2, ypos2))
            #print("[%d, %d] = [%d, %d]" % (xpos1, ypos1, xpos2, ypos2))
    '''
        room1 = s.roomList[0].rect.topleft
        room2 = s.roomList[3].rect.topleft
        xdistance = room1[0] - room2[0]
        ydistance = room1[1] - room2[1]
        step1 = min(abs(xdistance), abs(ydistance))
        if (step1 == abs(xdistance)) :
            step1 = room1[0] - room2[0]
        else :
            step1 = room1[1] - room2[1]
        pygame.draw.line(s.screen, s.black, (room1[0], room1[1]), (room1[0] + step1, room1[1] + step1))
        pygame.draw.line(s.screen, s.black,  (room1[0] + step1, room1[1] + step1), (room2[0], room2[1]))
    '''

class Move(object) :
    def __init__(self, List, ant, room) :
        self.ant = ant
        self.room = room
        List.append(self)
