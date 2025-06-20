# Write your MySQL query statement below
select s.user_id , IFNULL(ROUND(SUM(action='confirmed')/COUNT(*), 2 ), 0.00)as confirmation_rate
from Signups as s
LEFT JOIN  Confirmations  as c
ON  s.user_id = c.user_id
GROUP BY s.user_id ;