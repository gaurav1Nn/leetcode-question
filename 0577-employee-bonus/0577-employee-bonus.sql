# Write your MySQL query statement below
select  name , bonus 
FROM  Employee 
LEFT JOIN Bonus ON
Employee.empID = Bonus.empID
where bonus < 1000 or bonus IS NULL ;
