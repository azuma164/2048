#include <stdio.h>
#include <stdlib.h>
#include <time.h>               

void print_board(int board[4][4]) {
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            switch (board[j][i]) {
                case 0: printf("-\t\t"); break;
                case 2:
                case 4:
                case 8:
                    printf("%d\t\t", board[j][i]);
                    break;
                case 16:
                case 32:
                case 64:
                    printf("\e[33m%d\e[0m\t\t", board[j][i]);
                    break;
                case 128:
                case 256:
                case 512:
                    printf("\e[32m%d\e[0m\t\t", board[j][i]);
                    break;
                case 1024:
                case 2048:
                    printf("\e[36m%d\e[0m\t\t", board[j][i]);
                    break;
            }
        }
        printf("\r\n");
    }
}

void copy_board (int board[4][4], int copy[4][4]) {
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            copy[j][i] = board[j][i];
        }
    }
}

int compare_board (int latter_board[4][4], int former_board[4][4]) {
    int sum = 0;
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (latter_board[j][i] != former_board[j][i]) {
                sum = 1;
                j = 4;
                break;
            }
        }
    }
    return sum; 
}

void movement_number(int board[4][4], char c) {
    if (c == 'A' || c == 'w') {
        for (int n = 0; n < 3; ++n) { //３回回す
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[j][i] == 0) {
                        board[j][i] = board[j + 1][i];
                        board[j + 1][i] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[j][i] == board[j + 1][i]) {
                    board[j][i] += board[j + 1][i];
                    board[j + 1][i] = 0;
                }
            }
        }
        for (int n = 0; n < 3; ++n) { //３回回す
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[j][i] == 0) {
                        board[j][i] = board[j + 1][i];
                        board[j + 1][i] = 0;
                    }
                }
            }
        }        
    } else if (c == 'D' || c == 'a') {
        for (int n = 0; n < 3; ++n) { //３回回す
            for (int j = 0; j < 4; ++j) {
                for (int i = 0; i < 3; ++i) {
                    if (board[j][i] == 0) {
                        board[j][i] = board[j][i + 1];
                        board[j][i + 1] = 0;
                    } 
                }
            }
        }
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 3; ++i) {
                if (board[j][i] == board[j][i + 1]) {
                    board[j][i] += board[j][i + 1];
                    board[j][i + 1] = 0;
                }
            }
        }
        for (int n = 0; n < 3; ++n) { //３回回す
            for (int j = 0; j < 4; ++j) {
                for (int i = 0; i < 3; ++i) {
                    if (board[j][i] == 0) {
                        board[j][i] = board[j][i + 1];
                        board[j][i + 1] = 0;
                    } 
                }
            }
        }
    } else if (c == 'B' || c == 's') {
        for (int n = 0; n < 3; ++n) { //３回回す
            for (int i = 0; i < 4; ++i) {
                for (int j = 3; j > 0; --j) {
                    if (board[j][i] == 0) {
                        board[j][i] = board[j - 1][i];
                        board[j - 1][i] = 0;
                    } 
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 3; j > 0; --j) {
                if (board[j][i] == board[j - 1][i]) {
                        board[j][i] += board[j - 1][i];
                        board[j - 1][i] = 0;
                }
            }
        }
        for (int n = 0; n < 3; ++n) { //３回回す
            for (int i = 0; i < 4; ++i) {
                for (int j = 3; j > 0; --j) {
                    if (board[j][i] == 0) {
                        board[j][i] = board[j - 1][i];
                        board[j - 1][i] = 0;
                    } 
                }
            }
        }        
    } else if (c == 'C' || c == 'd') {
        for (int n = 0; n < 3; ++n) { //３回回す
            for (int j = 0; j < 4; ++j) {
                for (int i = 3; i > 0; --i) {
                    if (board[j][i] == 0) {
                        board[j][i] = board[j][i - 1];
                        board[j][i - 1] = 0;
                    }
                }
            }
        }
        for (int j = 0; j < 4; ++j) {
            for (int i = 3; i > 0; --i) {
                if (board[j][i] == board[j][i - 1]) {
                        board[j][i] += board[j][i - 1];
                        board[j][i - 1] = 0;
                }
            }
        }
        for (int n = 0; n < 3; ++n) { //３回回す
            for (int j = 0; j < 4; ++j) {
                for (int i = 3; i > 0; --i) {
                    if (board[j][i] == 0) {
                        board[j][i] = board[j][i - 1];
                        board[j][i - 1] = 0;
                    }
                }
            }
        }        
    }
}

int count_0 (int board[4][4]) {
    int sum = 0;
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (board[j][i] == 0) {
                sum += 1;
            }
        }
    }
    return sum;
}

void spawn_number (int board[4][4]) {
    int count = count_0(board);
    srand((unsigned)time(NULL));
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (board[j][i] == 0) {
                if ((rand() % count) == 0) {
                    board[j][i] = 2;
                    j = 4;
                    break;
                }
                count -= 1;
            }
        }
    }
    
}

void make_board(int board[4][4]) {
    spawn_number(board);
    srand((unsigned)time(NULL) + 1);
    int count = count_0(board);
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (board[j][i] == 0) {
                if ((rand() % count) == 0) {
                    if (rand() % 3 == 0) {
                        board[j][i] = 4;
                    }
                    else {
                        board[j][i] = 2;
                    }
                    j = 4;
                    break;
                }
                count -= 1;
            }
        }
    }
}

int max_number(int board[4][4]) {
    int max = 0;
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            if (max < board[j][i]) {
                max = board[j][i];
            }
        }
    }
    return max;
}

int main (int argc, char *argv[]) {

    char c;
    int board[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    int copy[4][4];

    system("/bin/stty raw onlcr");  // enterを押さなくてもキー入力を受け付けるようになる
    
    system("clear");
    printf("Press '.' to close\r\n");
    make_board(board);
    print_board(board);
    
    while((c = getchar()) != '.') {
        system("clear");
        printf("Press '.' to close\r\n");
        copy_board(board, copy);
        movement_number(board, c);
        if (compare_board(board, copy) == 1) {
            spawn_number(board);
        }
        print_board(board);
        printf("You pressed '%c'\r\n", c);        
    }
    int max = max_number(board);
    printf("\r");    
    printf("Your score is %d.\r\n", max);

    system("/bin/stty cooked");  // 後始末

    return 0;
}
