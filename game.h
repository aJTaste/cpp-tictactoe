#ifndef MARUBATSU_GAME_
#define MARUBATSU_GAME_

#include <iostream>
#include <string>

class Game
{
public:
    Game();
    ~Game();
    void leave(int x, int y);
    void judge();
    void gameStart();
    void render();
    void getKey(std::string mb);

private:
    bool is_game = false;
    bool is_finish = false;
    const std::string d = "□";
    const std::string h = "■";
    const std::string m = "●";
    const std::string b = "×";
    std::string turn_k = "●";
    std::string turn_r = "マル";
    std::string grids[3][3] = {
        {d, d, d},
        {d, d, d},
        {d, d, d}};
    std::string l_grids;
};
#endif // MARUBATSU_GAME_
