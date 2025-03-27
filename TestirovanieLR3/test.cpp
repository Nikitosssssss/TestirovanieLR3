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
    return "����� ���������� �� ���� ��� ����� ����� �����������! ������� enter, ����� ������.";
}

string Game::askAQuestion() //formirovanie soobsheniya o nachale igry
{
    return "������� ����� 2+2?";
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
    ASSERT_EQ(startMessage, "����� ���������� �� ���� ��� ����� ����� �����������! ������� enter, ����� ������.");
}

//test zadit vopros
TEST(gameClassAskingTest, AskAQuestion) {
    //todo ������� ������ ������ �������
    Game* myGame = new Game();
    string questionText = myGame->askAQuestion();
    ASSERT_EQ(questionText, "������� ����� 2+2?");
}