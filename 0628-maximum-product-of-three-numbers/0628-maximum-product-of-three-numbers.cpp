class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        int first_max = INT_MIN ;
        int second_max = INT_MIN ;
        int third_max = INT_MIN ;

        int first_min = INT_MAX ;
        int second_min = INT_MAX ;

        for( int i = 0 ; i < nums.size() ; i++ )
        {
            if( nums[i] < first_min )
            {
                second_min = first_min ;
                first_min = nums[i] ;
            }
            else if( nums[i] < second_min )
                second_min = nums[i] ;
            if( nums[i] > first_max )
            {
                third_max = second_max ;
                second_max = first_max ;
                first_max = nums[i] ;
            }
            else if( nums[i] > second_max )
            {
                third_max = second_max ;
                second_max = nums[i] ;
            }
            else if( nums[i] > third_max )
                third_max = nums[i] ;
        }
        return max ( first_max * second_max * third_max , first_min * second_min * first_max );
    }
};