class Solution {
public:
    double angleClock(int hour, int minutes) {
        int H = (hour == 12) ? 0 : hour;
        
        double angle = abs(30 * H - 5.5 * minutes);

        return (angle > 180) ? 360 - angle : angle;
    }
};