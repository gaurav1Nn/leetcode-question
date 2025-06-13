# Write your MySQL query statement below
select activity_date as day  , COUNT( DISTINCT user_id) as active_users
from Activity
WHERE 
 activity_date >= '2019-06-28' AND activity_date <= '2019-07-27'
GROUP BY  activity_date ;