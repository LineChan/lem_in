import pygame
import settings as s

class Room(pygame.sprite.DirtySprite) :
    def __init__(self, ref, name, x, y) :
        self.ref = ref
        self.name = name
        self.x = x / 100 * s.screen_width
        self.y = y / 100 * s.screen_height
        self.img = pygame.image.load("img/room_" + str(ref) + ".png")
        self.rect = self.img.get_rect()
        s.roomList.append(self)

    def update() :
        [s.screen.blit(room.img, (room.x, room.y)) for room in s.roomList]

class Ant(pygame.sprite.DirtySprite) :
    def __init__(self, ref, state = True) :
        self.state = state
        self.ref = ref
        self.img = pygame.image.load("img/ant_" + str(ref) + ".png")
        self.rect = self.img.get_rect()
        self.rect.topleft = [(s.offSet[0][0]/ 100 + 1) * s.roomList[0].x - self.rect[2] * 0.5, (s.offSet[0][1] / 100 + 1) * s.roomList[0].y - self.rect[3]]
        s.antList.append(self)

    def update() :
        #[s.screen.blit(ant.img, ant.rect) for ant in s.antList if ant.state == True]
        [s.screen.blit(ant.img, ant.rect) for ant in s.antList]
