SELECT 
  contest_id, 
  ROUND(COUNT(DISTINCT r.user_id) * 100.0 / (SELECT COUNT(user_id) FROM Users), 2) AS percentage
FROM Register AS r
GROUP BY r.contest_id
ORDER BY percentage DESC , contest_id;
