class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string date){
            int month = stoi(date.substr(0 , 2));
            int day = stoi(date.substr(3));

            for(int i = 0 ; i < month - 1 ; i++){
                day += days[i];
            }
            return day;
        };

        int aliceAD = convert(arriveAlice);
        int aliceLD = convert(leaveAlice);
        int bobAD = convert(arriveBob);
        int bobLD = convert(leaveBob);

        int startD = max(aliceAD , bobAD);
        int leaveD = min(aliceLD , bobLD);

        if(startD > leaveD) return 0;

        return leaveD - startD + 1;
    }
};