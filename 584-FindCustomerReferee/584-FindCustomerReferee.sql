-- Last updated: 7/24/2025, 8:30:17 AM
# Write your MySQL query statement below
select name
from Customer
where referee_id <> 2 or referee_id is null;