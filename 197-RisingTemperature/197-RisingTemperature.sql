-- Last updated: 7/24/2025, 8:33:09 AM
# Write your MySQL query statement below
select t2.id 
from Weather t1 join Weather t2 on t1.recordDate + INTERVAL 1 DAY = t2.recordDate
where t1.temperature < t2.temperature