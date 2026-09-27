import random
import os

ROW = 9
COL = 9
EASY_COUNT = 20

def cls():
    os.system('cls' if os.name == 'nt' else 'clear')

def InitBoard(rows, cols, set_char):
    board = []
    for _ in range(rows):
        line = [set_char for _ in range(cols)]
        board.append(line)
    return board

def TeatDisplayBoardBoard(board, rows, cols):
    for i in range(rows):
        for j in range(cols):
            print(f"{board[i][j]} ", end="")
        print()

def SetMine(board, row, col):
    count = EASY_COUNT
    while count > 0:
        x = random.randint(1, row)
        y = random.randint(1, col)
        if board[x][y] == '0':
            board[x][y] = '1'
            count -= 1

def DisplayBoard(board, row, col):
    print("----扫雷----")
    # 打印列号
    for i in range(0, col + 1):
        print(i, end=" ")
    print()
    for i in range(1, row + 1):
        print(i, end=" ")
        for j in range(1, col + 1):
            print(f"{board[i][j]}", end=" ")
        print()

def GetMineCount(mine, x, y):
    total = 0
    total += 1 if mine[x-1][y-1] == '1' else 0
    total += 1 if mine[x-1][y] == '1' else 0
    total += 1 if mine[x-1][y+1] == '1' else 0
    total += 1 if mine[x][y-1] == '1' else 0
    total += 1 if mine[x][y+1] == '1' else 0
    total += 1 if mine[x+1][y-1] == '1' else 0
    total += 1 if mine[x+1][y] == '1' else 0
    total += 1 if mine[x+1][y+1] == '1' else 0
    return total

def FindMine(mine, show, row, col, count):
    win = row * col - count
    while win != 0:
        try:
            y = int(input("输入x>"))
            x = int(input("输入y>"))
        except ValueError:
            cls()
            print("请输入数字坐标！")
            DisplayBoard(show, row, col)
            continue

        if 1 <= x <= row and 1 <= y <= col:
            cls()
            if mine[x][y] == '1':
                print("踩到雷了！游戏结束！")
                DisplayBoard(mine, row, col)
                break
            elif show[x][y] == '*':
                ret = GetMineCount(mine, x, y)
                if ret == 0:
                    show[x][y] = ' '
                else:
                    show[x][y] = str(ret)
                DisplayBoard(show, row, col)
                win -= 1
            else:
                cls()
                print("该坐标已经排查过了，请重新输入！")
                DisplayBoard(show, row, col)
        else:
            cls()
            print("输入坐标超过棋盘范围！请重新输入")
            DisplayBoard(show, row, col)
    else:
        print("恭喜胜利！")

def game():
    ROWS = ROW + 2
    COLS = COL + 2
    mine = InitBoard(ROWS, COLS, '0')
    show = InitBoard(ROWS, COLS, '*')
    SetMine(mine, ROW, COL)
    DisplayBoard(show, ROW, COL)
    FindMine(mine, show, ROW, COL, EASY_COUNT)

def menu():
    print("--------------------")
    print("----1.start game----")
    print("----0.quit game-----")
    print("--------------------")

def main():
    while True:
        menu()
        try:
            input_str = input("请选择>\n")
            input_val = int(input_str)
        except ValueError:
            print("输入错误,重新输入")
            continue
        if input_val == 1:
            game()
        elif input_val == 0:
            print("退出游戏")
            break
        else:
            print("输入错误,重新输入")

if __name__ == "__main__":
    main()