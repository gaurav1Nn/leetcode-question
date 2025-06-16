# Write your MySQL query statement below
SELECT 
E1.employee_id,
E1.name,
COUNT(E2.employee_id) as reports_count,
ROUND(AVG(E2.age)) AS average_age
FROM 
    Employees E1 INNER JOIN Employees E2
ON 
    E1.employee_id = E2.reports_to
GROUP BY 
    E1.employee_id  , E1.name
ORDER BY 
    employee_id
