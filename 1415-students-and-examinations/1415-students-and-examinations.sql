# Write your MySQL query statement below
Select S.student_id , S.student_name , sub.subject_name  ,
COUNT(e.subject_name) AS attended_exams
FROM Students as S
CROSS JOIN Subjects AS sub
LEFT JOIN Examinations AS e
ON S.student_id = e.student_id AND sub.subject_name= e.subject_name 
GROUP BY S.student_id , S.student_name , sub.subject_name 
ORDER BY S.student_id , sub.subject_name;