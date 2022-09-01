class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = abs(5.5*minutes - 30*hour);
        if(angle > 180)
        {
            return 360-angle;
        }
        else
        {
            return angle;
        }
    }
};
