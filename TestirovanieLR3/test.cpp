#include <string>
#include <iostream>
#include "pch.h"
#include "stdio.h"

using namespace std;

class Game {
public:
    Game() {};
    string start();
    string askAQuestion();
};

// rezultat - stroka, vsegda odno i to zhe soobshenie
string Game::start() //formirovanie soobsheniya o nachale igry
{
    return "Добро пожаловать на игру Кто хочет стать миллионером! Нажмите enter, чтобы начать.";
}

string Game::askAQuestion() //formirovanie soobsheniya o nachale igry
{
    return "Сколько будет 2+2?";
}


//test na sozdanie classa igry
TEST(gameClassCreationTest, CreationClass) {
    Game* myGame = new Game();
    ASSERT_NE(myGame, nullptr);
}

//test na start igry
TEST(gameClassStartTest, StartGame) {
    Game* myGame = new Game();
    string startMessage = myGame->start();
    ASSERT_EQ(startMessage, "Добро пожаловать на игру Кто хочет стать миллионером! Нажмите enter, чтобы начать.");
}

//test zadit vopros
TEST(gameClassAskingTest, AskAQuestion) {
    //todo сделать больше одного вопроса
    Game* myGame = new Game();
    string questionText = myGame->askAQuestion();
    ASSERT_EQ(questionText, "Сколько будет 2+2?");
}