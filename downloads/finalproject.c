#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define W 10
#define H 20
#define SCORE_PER_PIECE 10

int board[H][W];

typedef struct {
    int id;
    int rot;
    int x;
    int y;
} Piece;

char pieceLetter[8] = " IJLOSTZ";

//7 種方塊
const char* SHAPE[8][4] = {
    {NULL,NULL,NULL,NULL},

    // I
    {
        "...."
        "OOOO"
        "...."
        "....",
        "..O."
        "..O."
        "..O."
        "..O.",
        "...."
        "...."
        "OOOO"
        "....",
        ".O.."
        ".O.."
        ".O.."
        ".O.."
    },

    // J
    {
        "O..."
        "OOO."
        "...."
        "....",
        ".OO."
        ".O.."
        ".O.."
        "....",
        "...."
        "OOO."
        "..O."
        "....",
        ".O.."
        ".O.."
        "OO.."
        "...."
    },

    // L
    {
        "..O."
        "OOO."
        "...."
        "....",
        ".O.."
        ".O.."
        ".OO."
        "....",
        "...."
        "OOO."
        "O..."
        "....",
        "OO.."
        ".O.."
        ".O.."
        "...."
    },

    // O
    {
        ".OO."
        ".OO."
        "...."
        "....",
        ".OO."
        ".OO."
        "...."
        "....",
        ".OO."
        ".OO."
        "...."
        "....",
        ".OO."
        ".OO."
        "...."
        "...."
    },

    // S
    {
        ".OO."
        "OO.."
        "...."
        "....",
        ".O.."
        ".OO."
        "..O."
        "....",
        "...."
        ".OO."
        "OO.."
        "....",
        "O..."
        "OO.."
        ".O.."
        "...."
    },

    // T
    {
        ".O.."
        "OOO."
        "...."
        "....",
        ".O.."
        ".OO."
        ".O.."
        "....",
        "...."
        "OOO."
        ".O.."
        "....",
        ".O.."
        "OO.."
        ".O.."
        "...."
    },

    // Z
    {
        "OO.."
        ".OO."
        "...."
        "....",
        "..O."
        ".OO."
        ".O.."
        "....",
        "...."
        "OO.."
        ".OO."
        "....",
        ".O.."
        "OO.."
        "O..."
        "...."
    }
};

//Console 工具
void moveCursorTopLeft() {
    COORD pos = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setCursorVisible(int visible) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(hOut, &info);
    info.bVisible = visible ? TRUE : FALSE;
    SetConsoleCursorInfo(hOut, &info);
}

//基本邏輯
void clearBoard() {
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            board[y][x] = 0;
}

int pieceCell(int id, int rot, int px, int py) {
    return SHAPE[id][rot][py * 4 + px] == 'O';
}

int collide(Piece p) {
    for (int py = 0; py < 4; py++)
        for (int px = 0; px < 4; px++)
            if (pieceCell(p.id, p.rot, px, py)) {
                int x = p.x + px;
                int y = p.y + py;
                if (x < 0 || x >= W || y < 0 || y >= H) return 1;
                if (board[y][x]) return 1;
            }
    return 0;
}

void mergePiece(Piece p) {
    for (int py = 0; py < 4; py++)
        for (int px = 0; px < 4; px++)
            if (pieceCell(p.id, p.rot, px, py))
                board[p.y + py][p.x + px] = 1;
}

void clearLines() {
    for (int y = H - 1; y >= 0; y--) {
        int full = 1;
        for (int x = 0; x < W; x++)
            if (!board[y][x]) full = 0;
        if (full) {
            for (int yy = y; yy > 0; yy--)
                for (int x = 0; x < W; x++)
                    board[yy][x] = board[yy - 1][x];
            for (int x = 0; x < W; x++) board[0][x] = 0;
            y++;
        }
    }
}

int randId() { 
    return 1 + rand() % 7;
}

Piece spawn(int id) {
    Piece p = {id, 0, 3, 0};
    return p;
}

//速度
int dropIntervalMs(int score) {
    int ms = 650 - score / 20;
    if (ms < 120) ms = 120;
    return ms;
}

//畫面
void draw(Piece cur, int nextId, int score) {
    moveCursorTopLeft();

    printf(" ----------   Next: %c\n", pieceLetter[nextId]);
    for (int y = 0; y < H; y++) {
        printf("|");
        for (int x = 0; x < W; x++) {
            int draw = board[y][x];
            for (int py = 0; py < 4; py++)
                for (int px = 0; px < 4; px++)
                    if (pieceCell(cur.id, cur.rot, px, py) && cur.x + px == x && cur.y + py == y)
                        draw = 1;
            printf(draw ? "O" : " ");
        }
        printf("|");
        if (y == 2) printf("   Score: %d", score);
        printf("\n");
    }
    printf(" ----------\n");
    printf("a/d: move  w: rotate  s: down  tab: hard drop  q: quit\n");
}

//開始畫面
void startScreen() {
    system("cls");
    printf("====================================\n");
    printf("               TETRIS               \n");
    printf("====================================\n\n");
    printf("Board: 10 x 20\n");
    printf("Blocks: I J L O S T Z\n\n");
    printf("Controls:\n");
    printf("  a : move left\n");
    printf("  d : move right\n");
    printf("  s : move down faster\n");
    printf("  w : rotate\n");
    printf("  q : quit\n");
    printf("tab : hard drop\n\n");
    printf("Scoring:\n");
    printf("  Each placed block +10 points\n");
    printf("  Falling speed increases with score\n\n");
    printf("Press any key to start...\n");
    _getch();
}

//主程式
int main() {
    srand(time(NULL));

    startScreen(); //開始畫面

    system("cls");
    setCursorVisible(0);
    clearBoard();

    int score = 0;
    int nextId = randId();
    Piece cur = spawn(nextId);
    nextId = randId();

    DWORD lastDrop = GetTickCount();
    int needRedraw = 1;

    while (1) {
        if (needRedraw) {
            draw(cur, nextId, score);
            needRedraw = 0;
        }

        if (_kbhit()) {
            int k = _getch();

            if (k == 9) {  // Tab key
                Piece t = cur;

                // 一直往下試，直到下一格會碰撞
                while (1) {
                    Piece next = t;
                    next.y++;
                    if (collide(next)) break;
                    t = next;
                }

                // 移到最低位置並立刻固定
                cur = t;
                mergePiece(cur);
                clearLines();
                score += SCORE_PER_PIECE;

                // 產生新方塊
                cur = spawn(nextId);
                nextId = randId();
                needRedraw = 1;

                // 檢查是否 Game Over
                if (collide(cur)) break;

                continue;
            }

            //一般移動（a/d/s/w/q）
            Piece t = cur;
            if (k == 'a') t.x--;
            if (k == 'd') t.x++;
            if (k == 's') t.y++;
            if (k == 'w') t.rot = (t.rot + 1) % 4;
            if (k == 'q') break;

            if (!collide(t)) {
                cur = t;
                needRedraw = 1;
            }
        }

        DWORD now = GetTickCount();
        if (now - lastDrop >= (DWORD)dropIntervalMs(score)) {
            lastDrop = now;
            Piece t = cur;
            t.y++;
            if (!collide(t)) {
                cur = t;
                needRedraw = 1;
            } else {
                mergePiece(cur);
                clearLines();
                score += SCORE_PER_PIECE;

                cur = spawn(nextId);
                nextId = randId();
                needRedraw = 1;

                if (collide(cur)) break;
            }
        }

        Sleep(10);
    }

    setCursorVisible(1);
    system("cls");
    printf("====================================\n");
    printf("            GAME OVER               \n");
    printf("====================================\n\n");
    printf("Final Score: %d\n", score);
    printf("Press any key to exit...\n");
    _getch();
    return 0;
}