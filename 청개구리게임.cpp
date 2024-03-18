#include <iostream>
#include <random>
#include <string>
#include <ctime>
using namespace std;

class frog_game {
private:
    int num1;
    string human;
    string Answer;
    time_t startTime, endTime;

    string selectRandomAI() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 2);
        int randomNumber = dis(gen);

        if (randomNumber == 0)
            return "가위";
        else if (randomNumber == 1)
            return "바위";
        else
            return "보";
    }

    bool isTimeOver() {
        return endTime - startTime > 3;
    }

    void printResult(const string& result) {
        cout << "게임에 " << result << "!" << endl;
        cout << "게임을 새로 시작하려면 1, 종료하려면 2를 입력하세요." << endl;
        cin >> num1;
    }

    string calculateResult(const string& ai, const string& human, const string& Answer) {
        if (ai == human) {
            return (Answer == "개굴") ? "승리" : "패배";
        }
        else if ((ai == "가위" && human == "바위") ||
            (ai == "바위" && human == "보") ||
            (ai == "보" && human == "가위")) {
            return (Answer == "이겼다") ? "승리" : "패배";
        }
        else {
            return (Answer == "졌다") ? "승리" : "패배";
        }
    }

public:
    frog_game() : num1(1) {}

    void startGame() {
        while (num1 == 1) {
            string ai = selectRandomAI(); 
            cout << "청개구리 가위, 바위, 보를 시작합니다." << endl;
            cout << "가위, 바위, 보를 입력해주세요 :" << endl;
            cin >> human;

            cout << "상대는 [" << ai << "]를 냈습니다" << endl;
            startTime = time(nullptr);
            cin >> Answer;
            endTime = time(nullptr);

            if (isTimeOver()) {
                cout << "시간초과로 패배하였습니다" << endl;
                printResult("패배");
            }
            else {
                string result = calculateResult(ai, human, Answer);
                printResult(result);
            }
        }
    }
};

int main() {
    frog_game game;
    game.startGame();
    return 0;
}
