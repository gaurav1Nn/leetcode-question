SELECT 
  query_name, 
  ROUND(SUM(rating * 1.0 / position) / COUNT(query_name), 2) AS quality, 
  ROUND(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(rating), 2) AS poor_query_percentage
FROM queries
GROUP BY query_name;
