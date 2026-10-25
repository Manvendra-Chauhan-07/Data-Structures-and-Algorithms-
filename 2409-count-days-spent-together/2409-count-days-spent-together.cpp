class Solution {
public:

    int findDays(string s, int totalDays[]){

        int months = stoi(s.substr(0,2));
        int days = stoi(s.substr(3));

        return totalDays[months-1]+days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int totalDays[13];

        totalDays[0]=0;
        totalDays[1]=monthDays[0];

        for(int i=2;i<=12;i++){
            totalDays[i]=totalDays[i-1]+monthDays[i-1];
        }

        int arriveAliceDays = findDays(arriveAlice,totalDays);
        int leaveAliceDays = findDays(leaveAlice,totalDays);
        int arriveBobDays = findDays(arriveBob,totalDays);
        int leaveBobDays = findDays(leaveBob,totalDays);

        int totalDayTogether = min(leaveBobDays,leaveAliceDays) - max(arriveAliceDays,arriveBobDays)+1;

        return totalDayTogether<0? 0 : totalDayTogether;
        
    }
};