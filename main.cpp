#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
int randomNumber(int from, int to)
{
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}
int readFromNumberTo(int from, int to, string message)
{
  int num1 = 0;
  do
  {
    cout << message << endl;
    cin >> num1;
  } while (num1 < from || num1 > to);
  return num1;
}
enum difficulties
{
  easy = 1,
  medium = 2,
  hard = 3,
  mixed = 4
};
enum opType
{
  add = 1,
  sub = 2,
  mul = 3,
  divv = 4,
  mix = 5,
};
struct gameStatus
{
  difficulties difficultie;
  opType opreationType;
  short quests = 0;
  short right = 0;
  short wrong = 0;
};
string strDiff(difficulties diff)
{
  string arr[4];
  arr[0] = "easy";
  arr[1] = "medium";
  arr[2] = "hard";
  arr[3] = "mix";
  return arr[diff - 1];
}
string strOpType(opType kk)
{
  string arr[5];
  arr[0] = "add";
  arr[1] = "sub";
  arr[2] = "mul";
  arr[3] = "div";
  arr[4] = "mix";
  return arr[kk - 1];
}
char opTyper(opType kk)
{
  switch (kk)
  {
  case opType::add:
    return char(43);
  case opType::sub:
    return char(45);
  case opType::mul:
    return char(42);
  case opType::divv:
    return char(47);
  }
  return 0;
}
int diffNumber(difficulties diff)
{
  switch (diff)
  {
  case difficulties::easy:
    return randomNumber(1, 10);
    break;
  case difficulties::medium:
    return randomNumber(10, 100);
    break;
  case difficulties::hard:
    return randomNumber(100, 1000);
    break;
  case difficulties::mixed:
    return randomNumber(1, 1000);
    break;

  default:
    break;
  }
  return 0;
}
float simpleCalculater(int num1, int num2, char kk)
{
  switch (kk)
  {
  case char(43):
    return num1 + num2;
  case char(45):
    return num1 - num2;
  case char(42):
    return num1 * num2;
  case char(47):
    return num1 / num2;
  default:
    return 0;
  }
  return 0;
}
char getOpt(opType op)
{
    char opt = ' ';
    if (op == opType::mix)
      opt = opTyper((opType)randomNumber(1, 4));
    else
      opt = opTyper(op);
    return opt;
}
void question(int allQuest ,int questNumber, int num1, int num2, char opt, float &answer)
{
    cout << "Question[ " << questNumber << "/" << allQuest << "]\n\n";
    cout << num1 << endl;
    cout << num2 << opt << endl;
    cout << "____________" << endl;
    answer = 0;
    cin >> answer;
}
void checkAnswer(int num1, int num2, char opt , float answer, short &wins, short &losses)
{
  if(simpleCalculater(num1, num2, opt) == answer)
  {
      cout << "your answer is correct " << endl;
      wins++;
      cout << "\n\n\n";
  }
  else
  {
      cout << "your answer is incorrect ";
      losses++;
      cout << "\n\n\n";
  }
}
void questions(short quests, difficulties diff, opType op, short &wins, short &losses)
{
  char opt = '0';
  float answer = 0;
  for (int i = 1; i <= quests; i++)
  {
    int questNumber1 = diffNumber(diff);
    int questNumber2 = diffNumber(diff);
    opt = getOpt(op);
    question(quests, i, questNumber1, questNumber2, opt, answer);
    checkAnswer(questNumber1,questNumber2,opt, answer, wins, losses);
  }
}
void gameResult(gameStatus stat)
{
  cout << "difficulty :" << strDiff(stat.difficultie) << endl;
  cout << "opreation type :" << strOpType(stat.opreationType) << endl;
  cout << "question number :" << stat.quests << endl;
  cout << "wins :" << stat.right << endl;
  cout << "losses :" << stat.wrong << endl;
  if (stat.right >= stat.wrong)
    cout << "you win" << endl;
  else
    cout << "you lose " << endl;
}
void game()
{
  gameStatus stat;
  stat.quests = readFromNumberTo(1, 10, "enter how many question you want from 1 to 10");
  stat.difficultie = (difficulties)readFromNumberTo(1, 4, "enter the difficultiy you want [1]: easy, [2]:medium, [3]:hard, [4]:mix");
  stat.opreationType = (opType)readFromNumberTo(1, 5, "enter what opreation type you want [1]:add, [2]:sub, [3]:mul, [4]:div, [5]:mix");
  questions(stat.quests, stat.difficultie, stat.opreationType, stat.right, stat.wrong);
  gameResult(stat);
}
int main()
{
  srand((unsigned)time(NULL));
  game();
}
