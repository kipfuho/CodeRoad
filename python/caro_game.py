import pygame
import sys

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

CELL_SIZE = 50

class Cell:
    def __init__(self, position, player_turn):
        self.position = position
        self.isX = player_turn

    def draw(self, screen):
        if self.isX:
            x = self.position[1]
            y = self.position[0]
            pygame.draw.line(screen, BLACK, [y + 13, x - 13], [y - 13, x + 13], 3)
            pygame.draw.line(screen, BLACK, [y - 13, x - 13], [y + 13, x + 13], 3)
        else:
            pygame.draw.circle(screen, BLACK, self.position, 20, 3)

size = 11
player_turn = True
x = 1
y = 1

pygame.init()
screen = pygame.display.set_mode((size*CELL_SIZE, size*CELL_SIZE))
pygame.display.set_caption("Caro game")
board = [[0 for i in range(size)] for j in range(size)]

def game_complete(screen, board, size, x, y) -> bool:
    # xem cột có 5 điểm liên tiếp không
    mark1 = 0
    mark2 = 0
    for i in range(x - 4, x + 5):
        if i < 0 or i >= size:
            continue
        if board[i][y] != 0 and board[i][y].isX:
            if mark1 == 4:
                pygame.draw.line(screen, RED, [y*CELL_SIZE, (i - 4)*CELL_SIZE], [y*CELL_SIZE, i*CELL_SIZE], 5)
                return True
            mark1 += 1
            mark2 = 0
        elif board[i][y] != 0 and not board[i][y].isX:
            if mark2 == 4:
                pygame.draw.line(screen, RED, [y*CELL_SIZE, (i - 4)*CELL_SIZE], [y*CELL_SIZE, i*CELL_SIZE], 5)
                return True
            mark2 += 1
            mark1 = 0

    # xem hàng có 5 điểm liên tiếp không
    mark1 = 0
    mark2 = 0
    for i in range(y - 4, y + 5):
        if i < 0 or i >= size:
            continue
        if board[x][i] != 0 and board[x][i].isX:
            if mark1 == 4:
                return True
            mark1 += 1
            mark2 = 0
        elif board[x][i] != 0 and not board[x][i].isX:
            if mark2 == 4:
                return True
            mark2 += 1
            mark1 = 0

    # xem hàng chéo lên có 5 điểm liên tiếp không
    mark1 = 0
    mark2 = 0
    for i in range(-4, 5):
        if x + i < 0 or x + i >= size:
            continue
        if y + i < 0 or y + i >= size:
            continue
        if board[x + i][y + i] != 0 and board[x + i][y + i].isX:
            if mark1 == 4:
                return True
            mark1 += 1
            mark2 = 0
        elif board[x + i][y + i] != 0 and not board[x + i][y + i].isX:
            if mark2 == 4:
                return True
            mark2 += 1
            mark1 = 0

    # xem hàng chéo xuống có 5 điểm liên tiếp không
    mark1 = 0
    mark2 = 0
    for i in range(-4, 5):
        if x - i < 0 or x - i >= size:
            continue
        if y - i < 0 or y - i >= size:
            continue
        if board[x - i][y - i] != 0 and board[x - i][y - i].isX:
            if mark1 == 4:
                return True
            mark1 += 1
            mark2 = 0
        elif board[x - i][y - i] != 0 and not board[x - i][y - i].isX:
            if mark2 == 4:
                return True
            mark2 += 1
            mark1 = 0
    return False

# bắt đầu game
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        # đánh dấu vị trí được đánh khi được click
        if event.type == pygame.MOUSEBUTTONDOWN:
            position = pygame.mouse.get_pos()
            x = position[1] // CELL_SIZE
            y = position[0] // CELL_SIZE
            if board[x][y] != 0:
                continue
            board[x][y] = Cell((y*CELL_SIZE + 20, x*CELL_SIZE + 20), player_turn)
            player_turn = not player_turn

    # cập nhật screen
    screen.fill(WHITE)
    for i in range(size):
        for j in range(size):
            pygame.draw.rect(screen, BLACK, [i*CELL_SIZE - 5, j*CELL_SIZE - 5, CELL_SIZE, CELL_SIZE], 2)
            if board[i][j] != 0:
                board[i][j].draw(screen)

    # xem đã kết thúc ván chơi chưa
    complete = game_complete(screen, board, size, x, y)

    # cập nhật hiển thị màn hình
    pygame.display.flip()

    # xử lý khi kết thúc ván chơi
    if complete:
        if player_turn:
            print("O win")
            
        else:
            print("X win")
        
        # đợi đến khi người dùng bấm bàn phím hoặc chuột, trò chơi sẽ kết thúc
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN or event.type == pygame.MOUSEBUTTONDOWN:
                pygame.quit()
                sys.exit()
