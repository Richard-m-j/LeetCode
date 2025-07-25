-- Last updated: 7/24/2025, 8:25:59 AM
# Write your MySQL query statement below
select a.machine_id, round(avg(b.timestamp - a.timestamp),3) as processing_time 
from Activity a, Activity b
where a.machine_id = b.machine_id and a.process_id = b.process_id and a.activity_type = 'start' and b.activity_type = 'end'
group by 1