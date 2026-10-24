class Solution {
private:
    const vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dateToDayOfYear(const string& date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int day_of_year = day;
        for (int i = 0; i < month - 1; ++i) {
            day_of_year += days_in_months[i];
        }

        return day_of_year;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int alice_start = dateToDayOfYear(arriveAlice);
        int alice_end = dateToDayOfYear(leaveAlice);
        int bob_start = dateToDayOfYear(arriveBob);
        int bob_end = dateToDayOfYear(leaveBob);

        int start = max(alice_start, bob_start);
        int end = min(alice_end, bob_end);

        return max(0, end - start + 1);
    }
};