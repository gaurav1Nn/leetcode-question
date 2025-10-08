# Write your MySQL query statement below
select person_name
from(
    select 
        person_name,
        SUM(weight) OVER (order by turn) as total_weight from Queue

) as ordered_queue
where total_weight<=1000
order by total_weight desc
limit 1
