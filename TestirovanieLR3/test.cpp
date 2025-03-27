#include <string>
#include <iostream>
#include "pch.h"
#include "stdio.h"

using namespace std;

class Game {
public:
    Game() {};
    string start();
    string askAQuestion(int numberOfQuestion);
};

// rezultat - stroka, vsegda odno i to zhe soobshenie
string Game::start() //formirovanie soobsheniya o nachale igry
{
    return "����� ���������� �� ���� ��� ����� ����� �����������! ������� enter, ����� ������.";
}


//pararmetry: int numberOfQuestion - celoe, nomer voprosa, rezultat - stroka, text voprosa
string Game::askAQuestion(int numberOfQuestion) //formirovanie soobsheniya o nachale igry
{
    //todo �������� ������ ��������
    //todo �������� �������� � �����
    if(numberOfQuestion==1)
        return "������� ����� 2+2?";
    if (numberOfQuestion == 2)
        return "� ����� ������ 28 ����?";
    if (numberOfQuestion == 3)
        return "����� ����� ��������� � ����� ������ �������������� ����� ...";
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

//test zadit vopros nomer 1
TEST(gameClassAskingTest, AskAQuestion1) {
    Game* myGame = new Game();
    string questionText = myGame->askAQuestion(1);
    ASSERT_EQ(questionText, "������� ����� 2+2?");
}

//test zadit vopros nomer 2
TEST(gameClassAskingTest, AskAQuestion2) {
    Game* myGame = new Game();
    string questionText = myGame->askAQuestion(2);
    ASSERT_EQ(questionText, "� ����� ������ 28 ����?");
}

//test zadit vopros nomer 3
TEST(gameClassAskingTest, AskAQuestion) {
    Game* myGame = new Game();
    string questionText = myGame->askAQuestion(3);
    ASSERT_EQ(questionText, "����� ����� ��������� � ����� ������ �������������� ����� ...");
}

//test predlozhit otvety na vopros 1
TEST(gameClassAskingTest, OfferAnswers1) {
    Game* myGame = new Game();
    string answers[4] = myGame->offerAnswers(1);
    string expectedAnswers[4] = { "1","9999","-1000","4" };
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test predlozhit otvety na vopros 2
TEST(gameClassAskingTest, OfferAnswers2) {
    Game* myGame = new Game();
    string answers[4] = myGame->offerAnswers(2);
    string expectedAnswers[4] = { "� �������","�� � �����","� ����������","�� ����" };
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test predlozhit otvety na vopros 3
TEST(gameClassAskingTest, OfferAnswers3) {
    Game* myGame = new Game();
    string answers[4] = myGame->offerAnswers(3);
    string expectedAnswers[4] = { "92.1","10","92.2","43.1" };
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}