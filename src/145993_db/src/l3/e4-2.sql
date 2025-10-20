-- The employees listed in the previous query have been selected for a special training program.
-- Northwind Traders’ Megadirector – your boss – would like to know more about these employees.
-- Provide a detailed report for him: in each row of the report, list
--   ▶ the employee IDs as found in the previous query,
--   ▶ a country the employee has shipped to,
--   ▶ the average number of days it took for the employee to ship an order to that country
--   ▶ how many distinct products the employee has shipped to that country
-- Make sure rows with incomplete data are stripped out.
 WITH tmp2 AS
    (SELECT E.employee_id,
            O.ship_country,
            (O.shipped_date - O.order_date) AS tmp
     FROM employees AS E
     JOIN orders AS O ON E.employee_id = O.employee_id
     WHERE (E.hire_date - E.birth_date) / 365 < 35
         AND E.country = 'UK'
         AND
             (SELECT COUNT(DISTINCT orders.order_id)
              FROM orders
              WHERE orders.employee_id = E.employee_id ) > 45 )
SELECT employee_id,
       ship_country,
       AVG(tmp),
       COUNT(tmp)
FROM tmp2
GROUP BY employee_id,
         ship_country
ORDER BY employee_id,
         ship_country