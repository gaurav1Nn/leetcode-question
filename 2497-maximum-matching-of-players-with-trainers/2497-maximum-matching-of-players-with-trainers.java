import java.util.*;
class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int count = 0;
        int i =0 , j = 0 ;
        while(i < players.length && j < trainers.length){
            if(trainers[j]>=players[i]){
                i++;
                j++;
                count++;
            }
           else  j++;
        }
        return count;
    }
}