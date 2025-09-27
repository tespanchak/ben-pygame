
import pygame

class Button:
    def __init__(self,rect,iamge,button=None):
        self.rect = pygame.Rect(*rect)
        self.image = iamge
        self.button = button if button else []
        self.is_draw = True
    def draw(self,screen):
        if not self.is_draw:
            return
        screen.blit(self.image,(self.rect.x,self.rect.y))
        for button in self.button:
            button.draw(screen)
    def collision(self,pos):
        pass
        

