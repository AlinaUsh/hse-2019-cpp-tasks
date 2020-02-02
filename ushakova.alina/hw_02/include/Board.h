#ifndef HW_02_BOARD_H
#define HW_02_BOARD_H

enum cell {
    cell_empty,
    cell_X,
    cell_O
};

enum player_type {
    player_X,
    player_O
};

enum game_status {
    draw,
    X_wins,
    O_wins,
    not_ended
};


struct Player {
    Player(player_type new_player): player(new_player) {}
    void changePlayer();
    void printRequest();

    player_type player;
};


class Board {
public:
    ~Board() = default;
    Board();
    /** Проверить ход на корректность, если бы он был следующим. */
    bool canMove(int x, int y);

    /** Сделать ход. UB, если он некорректен. */
    void move(int x, int y, Player cur_player);

    /** Состояние игры: игра идёт, игра кончилась с одним из результатов: ничья, победа одной из сторон. */
    game_status getState(int x, int y, Player cur_player);

    /** состояние клетки поля*/
    cell getCell(int x, int y) const;

    bool sameInLine(int x, int y, int delta_x, int delta_y);

private:
    static const int size = 10;
    cell board[size][size];
};

#endif //HW_02_BOARD_H
