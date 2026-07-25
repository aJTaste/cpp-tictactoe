#include <iostream>
#include "game.h"

using namespace std;

Game::Game()
{
    cout << "cキーを入力してゲームを開始します" << endl;
    string start_key;
    cin >> start_key;
    if (start_key == "c")
    {
        is_game = true;
        cout << "========マルバツゲームを開始しました========" << endl;
    }
    else
    {
        cout << "正しいキー入力を検知できませんでした" << endl;
    }
}

Game::~Game()
{
    cout << "終了" << endl;
}

void Game::leave(int x, int y)
{
    l_grids = grids[x][y];
    grids[x][y] = h;
}

void Game::render()
{
    cout << grids[0][0] << " " << grids[1][0] << " " << grids[2][0] << endl;
    cout << grids[0][1] << " " << grids[1][1] << " " << grids[2][1] << endl;
    cout << grids[0][2] << " " << grids[1][2] << " " << grids[2][2] << endl;
}

void Game::judge()
{
    for (int i = 0; i < 3; i++)
    {
        if ((grids[i][0] == grids[i][1] && grids[i][1] == grids[i][2] && grids[i][2] == turn_k) || (grids[0][i] == grids[1][i] && grids[1][i] == grids[2][i] && grids[2][i] == turn_k) || (grids[i][0] == grids[1][1] && grids[1][1] == grids[2 - i][2] && grids[2 - i][2] == turn_k))
        {
            cout << "========" << turn_r << "の勝ち" << "========" << endl;
            render();
            is_finish = true;
            return;
        }
    }

    int all_count = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (grids[j][k] != d)
            {
                all_count += 1;
            }
        }
    }
    if (all_count == 9)
    {
        cout << "========" << "引き分けです" << "========" << endl;
        render();
        is_finish = true;
    }
}

void Game::getKey(string mb)
{
    int now_x = 1;
    int now_y = 1;
    leave(now_x, now_y);
    render();
    bool hide = false;
    while (true)
    {
        string key;
        cin >> key;
        if (key == "c" && l_grids == d)
        {
            grids[now_x][now_y] = (mb == "m") ? m : b;
            l_grids = "";
            break;
        }
        else
        {
            if (key == "c")
            {
                cout << "このマスは既に置かれています" << endl;
            }
            else if (key == "x")
            {
                hide = !hide;
                if (hide == true)
                {
                    grids[now_x][now_y] = l_grids;
                }
                else
                {
                    grids[now_x][now_y] = h;
                }
            }
            else if (key == "w" && now_y != 0)
            {
                hide = false;
                grids[now_x][now_y] = l_grids;
                now_y -= 1;
                leave(now_x, now_y);
            }
            else if (key == "a" && now_x != 0)
            {
                hide = false;
                grids[now_x][now_y] = l_grids;
                now_x -= 1;
                leave(now_x, now_y);
            }
            else if (key == "s" && now_y != 2)
            {
                hide = false;
                grids[now_x][now_y] = l_grids;
                now_y += 1;
                leave(now_x, now_y);
            }
            else if (key == "d" && now_x != 2)
            {
                hide = false;
                grids[now_x][now_y] = l_grids;
                now_x += 1;
                leave(now_x, now_y);
            }
        }
        render();
    }
    judge();
}

void Game::gameStart()
{
    if (is_game != true)
    {
        cout << "ゲームを開始できません" << endl;
    }
    else
    {
        cout << "- wasdでマスを選択します。" << endl
             << "- 「■」が現在選択しているマスです。" << endl
             << "- 現在選択しているマスはxキーで表示、非表示できます。" << endl
             << "- cキーで確定してください。" << endl;
        int count = 0;
        string turn;
        while (is_finish != true)
        {
            count += 1;
            if (count % 2 == 1)
            {
                turn = "m";
                turn_k = "●";
                turn_r = "マル";
            }
            else
            {
                turn = "b";
                turn_k = "×";
                turn_r = "バツ";
            }
            cout << "========「" << turn_k << "（" << turn_r << "）" << "」のターン========" << endl;
            getKey(turn);
        };
    }
}
