# Write your MySQL query statement below
select name AS Customers from Customers LEFT JOIN Orders On Customers.id=Orders.customerId where Orders.customerId IS NULL