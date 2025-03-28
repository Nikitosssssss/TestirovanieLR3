#include <string>
#include <iostream>
#include "pch.h"
#include "stdio.h"
#include "windows.h"

using namespace std;

class Game {
    //todo по-хорошему сделать класс вопроса и структуру ответов
public:
    Game() { this->hintWasUsed = false; };
    string start();
    string askAQuestion(int numberOfQuestion);
    string* offerAnswers(int numberOfQuestion);
    bool processResponses(int numberOfQuestion, int numberOfAnswer);
    string* make50on50Hint(int numberOfQuestion);
    bool checkMake50on50Hint();
private:
    bool hintWasUsed;
};

// rezultat - stroka, vsegda odno i to zhe soobshenie
string Game::start() //formirovanie soobsheniya o nachale igry
{
    return "Добро пожаловать на игру Кто хочет стать миллионером! Нажмите enter, чтобы начать.";
}


//pararmetry: int numberOfQuestion - celoe, nomer voprosa, rezultat - stroka, text voprosa
string Game::askAQuestion(int numberOfQuestion) //formirovanie soobsheniya o nachale igry
{
    //todo добавить больше вопросов
    //todo хранение вопросов в файле
    if(numberOfQuestion==1)
        return "Сколько будет 2+2?";
    if (numberOfQuestion == 2)
        return "В каком месяце 28 дней?";
    if (numberOfQuestion == 3)
        return "Номер счета Материалы в плане счетов бухгалтерского учета ...";
}

//pararmetry: int numberOfQuestion - celoe, nomer voprosa, rezultat - massiv strok, otvety
string* Game::offerAnswers(int numberOfQuestion) //formirovanie soobsheniya o nachale igry
{
    //todo сделать выбор случайных вопросов из списка
    if (numberOfQuestion == 1)
    {
        string* arr = new string[4]{ "1) 1","2) 9999","3) -1000","4) 4" };
        return arr; 
    }
    if (numberOfQuestion == 2)
    {
        string* arr = new string[4]{ "1) В декабре","2) Ни в каком","3) В никогдабре","4) Во всех" };
        return arr;
    }
    if (numberOfQuestion == 3)
    {
        string* arr = new string[4]{ "1) 92.1","2) 10","3) 92.2","4) 43.1" };
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

string* Game::make50on50Hint(int numberOfQuestion) //formirovanie soobsheniya o nachale igry
{
    //todo сделать, чтобы вопросы случайным образом убирались, а не 2 фиксированных
    this->hintWasUsed = true;
    string* arr = new string[2];
    if (numberOfQuestion == 1)
    {
        string* arr = new string[2]{ "1) 1","4) 4" };
        return arr;
    }
    if (numberOfQuestion == 2)
    {
        string* arr = new string[2]{ "3) В никогдабре","4) Во всех" };
        return arr;
    }
    if (numberOfQuestion == 3)
    {
       string* arr = new string[2]{ "1) 92.1","2) 10" };
       return arr;
    }   
}

bool Game::checkMake50on50Hint()
{
    return !(this->hintWasUsed);
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

//test zadit vopros nomer 1
TEST(gameClassAskingTest, AskAQuestion1) {
    Game* myGame = new Game();
    string questionText = myGame->askAQuestion(1);
    ASSERT_EQ(questionText, "Сколько будет 2+2?");
}

//test zadit vopros nomer 2
TEST(gameClassAskingTest, AskAQuestion2) {
    Game* myGame = new Game();
    string questionText = myGame->askAQuestion(2);
    ASSERT_EQ(questionText, "В каком месяце 28 дней?");
}

//test zadit vopros nomer 3
TEST(gameClassAskingTest, AskAQuestion) {
    Game* myGame = new Game();
    string questionText = myGame->askAQuestion(3);
    ASSERT_EQ(questionText, "Номер счета Материалы в плане счетов бухгалтерского учета ...");
}

//test predlozhit otvety na vopros 1
TEST(gameClassAskingTest, OfferAnswers1) {
    Game* myGame = new Game();
    string *answers = myGame->offerAnswers(1);
    string expectedAnswers[4] = { "1) 1","2) 9999","3) -1000","4) 4" };
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test predlozhit otvety na vopros 2
TEST(gameClassAskingTest, OfferAnswers2) {
    Game* myGame = new Game();
    string *answers = myGame->offerAnswers(2);
    string expectedAnswers[4] = { "1) В декабре","2) Ни в каком","3) В никогдабре","4) Во всех" };
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test predlozhit otvety na vopros 3
TEST(gameClassAskingTest, OfferAnswers3) {
    Game* myGame = new Game();
    string *answers = myGame->offerAnswers(3);
    string expectedAnswers[4] = { "1) 92.1","2) 10","3) 92.2","4) 43.1" };
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

//test 50 na 50 vopros 1
TEST(gameClassHintTest, Hint50_50v1) {
    Game* myGame = new Game();
    string* answers = myGame->make50on50Hint(1);
    string expectedAnswers[2] = { "1) 1","4) 4"};
    for (int i = 0; i < 2; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test 50 na 50 vopros 2
TEST(gameClassHintTest, Hint50_50v2) {
    Game* myGame = new Game();
    string* answers = myGame->make50on50Hint(2);
    string expectedAnswers[2] = { "3) В никогдабре","4) Во всех" };
    for (int i = 0; i < 2; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test 50 na 50 vopros 3
TEST(gameClassHintTest, Hint50_50v3) {
    Game* myGame = new Game();
    string* answers = myGame->make50on50Hint(3);
    string expectedAnswers[2] = { "1) 92.1","2) 10"};
    for (int i = 0; i < 2; i++)
    {
        EXPECT_EQ(answers[i], expectedAnswers[i]) << "Error in position: " << i;
    }
}

//test 50 na 50
TEST(gameClassHintTest, Hint50_50SecondCall) {
    Game* myGame = new Game();
    string* answers = myGame->make50on50Hint(1);
    ASSERT_EQ(myGame->checkMake50on50Hint(), false);
}

//test 50 na 50
TEST(gameClassHintTest, Hint50_50FirstCall) {
    Game* myGame = new Game();
    ASSERT_EQ(myGame->checkMake50on50Hint(), true);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Game *myGame = new Game();
    cout << myGame->start();
    while (cin.get() != '\n') { //ozhidanie enter
        continue;
    }
    cout << "Для получения подсказки 50 на 50 нажмите 5." << endl;
    int numberOfQuestion = 1;
    int answer;
    string* answers;
    for (int i = 0; i < 3; i++)
    {
        cout << myGame->askAQuestion(numberOfQuestion) << endl;
        answers = myGame->offerAnswers(numberOfQuestion);
        for (int j = 0; j < 4; j++)
        {
            cout << answers[j] << endl;
        }
        cin >> answer;
        if (answer == 5 )
        {
            if (myGame->checkMake50on50Hint())
            {
                answers = myGame->make50on50Hint(numberOfQuestion);
                for (int j = 0; j < 2; j++)
                {
                    cout << answers[j] << endl;
                }
            }
            else
            {
                cout << "Вы уже использовали подсказку. Придется отвечать без нее! Введите ответ:" << endl;
            }
            cin >> answer;
        }
        if (!myGame->processResponses(numberOfQuestion, answer))
        {
            cout << "Неверно! Конец игры!";
            break;
        }
        else
        {
            cout << "Верно!" << endl;
        }
        numberOfQuestion++;
    }
    if (numberOfQuestion == 4)
        cout << "Поздравляю! Вы самый умный наш чемпион! Вы победили." << endl;
    delete[] answers;
    return 0;
}