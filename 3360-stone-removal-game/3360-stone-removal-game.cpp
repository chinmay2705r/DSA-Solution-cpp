class Solution {
public:
    bool canAliceWin(int n) {
        int stones_to_remove = 10;
        bool alice_turn = true;

        while (n >= stones_to_remove && stones_to_remove > 0) {
            n -= stones_to_remove;
            stones_to_remove--;
            alice_turn = !alice_turn;
        }
        return !alice_turn;
    }
};