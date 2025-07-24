-- Last updated: 7/24/2025, 8:26:17 AM
# Write your MySQL query statement below
select customer_id, COUNT(*) as count_no_trans 
    from Visits V left join Transactions T
        on V.visit_id = T.visit_id 
    where T.transaction_id is null
group by customer_id