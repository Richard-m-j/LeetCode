-- Last updated: 7/24/2025, 8:27:54 AM
# Write your MySQL query statement below
select product_name,year,price
from Sales S, Product P
where S.product_id = P.product_id