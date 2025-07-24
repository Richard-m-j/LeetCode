-- Last updated: 7/24/2025, 8:26:52 AM
# Write your MySQL query statement below
select unique_id, name 
from Employees E left join EmployeeUNI U
on E.id = U.id