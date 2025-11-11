class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);

        int i=0,j=people.length-1;
        int min = 0;
        int subtract = 0;
        while(i<j)
        {
            int sum = people[i] + people[j];
            
            if(sum <= limit)
            {
                min++;
                i++;
                j--;
                subtract += 2;
            }

            else if(people[i]<people[j])
            j--;
            else
            i++;

        }
        min += people.length-subtract;

        return min;
    }
}
