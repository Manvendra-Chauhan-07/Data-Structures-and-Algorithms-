class Solution {
public:

    int calculateDays(string s,int totalMonthsDays[] ){

        int months = stoi(s.substr(0,2));
        int days = stoi(s.substr(3));

        return totalMonthsDays[months-1]+days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int totalMonthsDays[13];
        totalMonthsDays[1]=months[0];

        for(int i=2;i<=12;i++){
            totalMonthsDays[i]=totalMonthsDays[i-1]+months[i-1];
        }


        int DaysarriveAlice  = calculateDays(arriveAlice, totalMonthsDays);
        int DaysleaveAlice = calculateDays(leaveAlice,totalMonthsDays);
        int DaysarriveBob = calculateDays(arriveBob,totalMonthsDays);
        int DaysleaveBob = calculateDays(leaveBob,totalMonthsDays);

        int ans = min(DaysleaveBob,DaysleaveAlice) - max(DaysarriveAlice,DaysarriveBob)+1;

        return ans<0? 0 : ans;
    }
};