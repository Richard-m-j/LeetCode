-- Last updated: 7/24/2025, 8:27:42 AM
# Write your MySQL query statement below
select distinct viewer_id as id
from Views
where viewer_id = author_id
order by id