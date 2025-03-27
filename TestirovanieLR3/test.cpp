#include <string>
#include <iostream>
#include "pch.h"
#include "stdio.h"

using namespace std;

class Game {
public:
    Game() {};
};


//test na sozdanie classa igry
TEST(gameClassCreationTest, CreationClass) {
    Game* myGame = new Game();
    ASSERT_NE(myGame, nullptr);
}

//test na start igry
TEST(gameClassStartTest, StartGame) {
    Game* myGame = new Game();
    string startMessage = myGame.start();
    ASSERT_EQ(startMessage, "Добро пожаловать на игру Кто хочет стать миллионером! Нажмите enter, чтобы начать.");
}