class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int eH = abs(((endTime[0] - '0') * 10 + endTime[1] - '0'));
        int eM = ((endTime[3] - '0') * 10 + endTime[4] - '0');
        int eS = ((endTime[6] - '0') * 10 + endTime[7] - '0');

        int sH = abs(((startTime[0] - '0') * 10 + startTime[1] - '0'));
        int sM = ((startTime[3] - '0') * 10 + startTime[4] - '0');
        int sS = ((startTime[6] - '0') * 10 + startTime[7] - '0');

        long long totalE = eH * 3600 + eM * 60 + eS;
        long long totalS = sH * 3600 + sM * 60 + sS;

        return (int)(totalE - totalS);
    }
};