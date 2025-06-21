# Write your MySQL query statement below
select DATE_FORMAT(trans_date , '%Y-%m') AS month ,
country ,
COUNT(id) as trans_count ,
sum(state = 'approved') as approved_count ,
sum(amount) as trans_total_amount,
SUM(if(state = 'approved' , amount , 0)) as  approved_total_amount


from  Transactions
group by month , country 