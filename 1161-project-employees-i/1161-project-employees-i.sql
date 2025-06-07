# Write your MySQL query statement below
-- select p.project_id , ROUND(AVG(p.employee_id),2) as average_years 
SELECT  
 p.project_id, 
    ROUND(AVG(e.experience_years), 2) AS average_years
FROM  Project AS  p
LEFT JOIN  Employee as e
ON p.employee_id = e.employee_id  
GROUP BY p.project_id;
