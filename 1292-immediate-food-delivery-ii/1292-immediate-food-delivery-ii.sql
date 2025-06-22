# Write your MySQL query statement below
select 
round(
    100 * SUM(order_date =customer_pref_delivery_date ) / count(*),
    2
) AS immediate_percentage
FROM Delivery
WHERE 
 (customer_id , order_date) IN (
    select customer_id , MIN(order_date)
    FROM Delivery
    group by customer_id
);