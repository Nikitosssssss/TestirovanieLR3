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
    string* offerAnswers(int numberOfQuestion);
    bool Game::processResponses(int numberOfQuestion, int numberOfAnswer);
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

//pararmetry: int numberOfQuestion - celoe, nomer voprosa, rezultat - massiv strok, otvety
string* Game::offerAnswers(int numberOfQuestion) //formirovanie soobsheniya o nachale igry
{
    string* arr = new string[4];
    if (numberOfQuestion == 1)
    {
        string* arr = new string[4]{ "1","9999","-1000","4" };
        return arr; 
    }
    if (numberOfQuestion == 2)
    {
        string* arr = new string[4]{ "� �������","�� � �����","� ����������","�� ����" };
        return arr;
    }
    if (numberOfQuestion == 3)
    {
        string* arr = new string[4]{ "92.1","10","92.2","43.1" };
        return arr;
    }
}

//pararmetry: int numberOfQuestion - celoe, nomer voprosa,numberOfAnswer - celoe, nomer otveta, rezultat - bulevo, vernyi li otvet
bool Game::processResponses(int numberOfQuestion, int numberOfAnswer) //formirovanie soobsheniya o nachale igry
{
    bool rezult = false;
    if (numberOfQuestion == 1)
    {
        if (numberOfAnswer == 4)
            rezult = true;
    }
    if (numberOfQuestion == 2)
    {
        if (numberOfAnswer == 4)
            rezult = true;
    }
    if (numberOfQuestion == 3)
    {
        if (numberOfAnswer == 2)
            rezult = true;
    }
    return rezult;
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
    string *answers = myGame->offerAnswers(1);
    string expectedAnswers[4] = { "1","9999","-1000","4" };
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test predlozhit otvety na vopros 2
TEST(gameClassAskingTest, OfferAnswers2) {
    Game* myGame = new Game();
    string *answers = myGame->offerAnswers(2);
    string expectedAnswers[4] = { "� �������","�� � �����","� ����������","�� ����" };
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test predlozhit otvety na vopros 3
TEST(gameClassAskingTest, OfferAnswers3) {
    Game* myGame = new Game();
    string *answers = myGame->offerAnswers(3);
    string expectedAnswers[4] = { "92.1","10","92.2","43.1" };
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test proverit otxet na vopros1
TEST(gameClassAskingTest, ProcessResponses1) {
    Game* myGame = new Game();
    bool isRightAnswer = myGame->processResponses(1,1);
    ASSERT_EQ(isRightAnswer, false);
}

//test proverit otxet na vopros1
TEST(gameClassAskingTest, ProcessResponses1True) {
    Game* myGame = new Game();
    bool isRightAnswer = myGame->processResponses(1, 4);
    ASSERT_EQ(isRightAnswer, true);
}

//test proverit otxet na vopros2
TEST(gameClassAskingTest, ProcessResponses2) {
    Game* myGame = new Game();
    bool isRightAnswer = myGame->processResponses(2, 1);
    ASSERT_EQ(isRightAnswer, false);
}

//test proverit otxet na vopros2
TEST(gameClassAskingTest, ProcessResponses2True) {
    Game* myGame = new Game();
    bool isRightAnswer = myGame->processResponses(2, 4);
    ASSERT_EQ(isRightAnswer, true);
}

//test proverit otxet na vopros3
TEST(gameClassAskingTest, ProcessResponses3) {
    Game* myGame = new Game();
    bool isRightAnswer = myGame->processResponses(3, 1);
    ASSERT_EQ(isRightAnswer, false);
}

//test proverit otxet na vopros3
TEST(gameClassAskingTest, ProcessResponses3True) {
    Game* myGame = new Game();
    bool isRightAnswer = myGame->processResponses(3, 2);
    ASSERT_EQ(isRightAnswer, true);
}