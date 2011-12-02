#include <iostream>
#include <vector>
using namespace std;

static const string CARD_NUMBER = "23456789TJQKA";
static const int INDEX_NO_PAIR = 0;
static const int INDEX_ONE_PAIR = 1;
static const int INDEX_TWO_PAIR = 2;
static const int INDEX_THREE_CARD = 3;
static const int INDEX_STRAIGHT = 4;
static const int INDEX_FLASH = 5;
static const int INDEX_FULLHOUSE = 6;
static const int INDEX_FOUR_CARD = 7;
static const int INDEX_STRAIGHT_FLASH = 8;

int getNum(const string& card) {
    for (int i = 0; i < CARD_NUMBER.size(); i++)
        if (CARD_NUMBER[i] == card[0]) return i;
    return -1;
}

bool isFlash(const vector<string>& cards) {
    char c = cards[0][1];
    if (cards[1][1] == c && cards[2][1] == c &&
            cards[3][1] == c && cards[4][1] == c) 
        return true;
    else
        return false;
}

vector<int> calsScore(const vector<string>& cards) {

    vector<int> numbers(CARD_NUMBER.size(), 0);
    for (int i = 0; i < cards.size(); i++) 
        numbers[getNum(cards[i])]++;

    vector<int> score(9, 0);

    // add score for card
    for (int i = 0; i < numbers.size(); i++)
        if (numbers[i] == 1) 
            score[INDEX_NO_PAIR] = max(score[INDEX_NO_PAIR], i+2);

    // add score for pairs
    bool hasPair = false;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 2) {
            if (hasPair) {
                score[INDEX_TWO_PAIR] = i+2;
            } else {
                hasPair = true;
                score[INDEX_ONE_PAIR] = i+2;
            }
        }
    }

    // add score for 3 cards
    bool has3cards = false;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 3) {
            has3cards = true;
            score[INDEX_THREE_CARD] = i+2;
        }
    }

    // add score for straight
    bool isStraight = false;
    for (int i = 0; i < numbers.size() - 4; i++) {
        if (numbers[i] == 1 && numbers[i+1] == 1 && numbers[i+2] == 1 &&
                numbers[i+3] == 1 && numbers[i+4] == 1) {
            isStraight = true;
            score[INDEX_STRAIGHT] = i+2;
        }
    }

    // add score for flash
    bool flash = false;
    if (isFlash(cards)) {
        flash = true;
        int maxCard = 0;
        for (int i = 0; i < numbers.size(); i++) maxCard = max(maxCard, i+2);
        score[INDEX_FLASH] = maxCard;
    }

    // add score for fullhouse
    if (hasPair && has3cards) score[INDEX_FULLHOUSE];

    // add score for 4 cards
    for (int i = 0; i < numbers.size(); i++)
        if (numbers[i] == 4) score[INDEX_FOUR_CARD] = i+2;

    // add score for (royal) straight flash
    if (isStraight && flash) score[INDEX_STRAIGHT_FLASH] = 1;

    for (int i = 0; i < cards.size(); i++) cerr << cards[i] << " ";
    cerr << " => SCORE: ";
    for (int i = score.size()-1; i >= 0; i--) cerr << score[i] << " ";
    cerr << endl;

    return score;
}

bool isP1Win(const vector<string>& p1, const vector<string>& p2) {
    vector<int> score1 = calsScore(p1);
    vector<int> score2 = calsScore(p2);
    for (int i = score1.size()-1; i >= 0; i--) {
        if (score1[i] > score2[i]) {
            return true;
        } else if (score1[i] < score2[i]) {
            return false;
        }
    }
    return false;
}

int main() {
    int answer = 0;
    for (int t = 1; t <= 1000; t++) {
        string temp;
        vector<string> s1, s2;
        for (int i = 0; i < 5; i++) {
            cin >> temp;
            s1.push_back(temp);
        }
        for (int i = 0; i < 5; i++) {
            cin >> temp;
            s2.push_back(temp);
        }
        bool p1win = isP1Win(s1, s2);
        if (p1win) answer++;
        cerr << "#" << t << ": " << (p1win ? "Player 1" : "Player 2") << " win!" << endl << endl;;
    }
    cout << "A: " << answer << endl;
}
