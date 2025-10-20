-- List all the employees (Name, Surname, count of orders shipped) that
--   ▶ were hired when they were younger than 35 years old
--   ▶ are located in the UK
--   ▶ have shipped at least 45 orders

SELECT E.first_name,
       E.last_name,
       COUNT(DISTINCT O.order_id) AS order_count
FROM employees AS E
JOIN orders AS O ON E.employee_id = O.employee_id
WHERE (E.hire_date - E.birth_date) / 365 < 35
    AND E.country = 'UK'
    AND
        (SELECT COUNT(DISTINCT orders.order_id)
         FROM orders
         WHERE orders.employee_id = E.employee_id ) > 45
GROUP BY E.employee_id