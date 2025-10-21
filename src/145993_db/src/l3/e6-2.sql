-- Northwind Traders’ Megadirector is considering for promotion one or more employees
-- that have shown exceptional performance and are not managers yet.
-- Find each employee that
--   1 has shipped the most profitable order ever
--   2 has the highest average profit per order
-- and list their Name, Surname, and what they have achieved.
-- The query must work even if there are ties
 WITH NonManagers AS
    (SELECT DISTINCT e.employee_id
     FROM Employees E
     WHERE E.employee_id not in
             (SELECT DISTINCT reports_to
              FROM Employees E0
              WHERE reports_to is not NULL ) ),
      MostProfitableOrder as
    (SELECT e.employee_id,
            e.first_name,
            e.last_name,
            SUM(od.unit_price * od.quantity * (1 - od.discount)) AS amount
     FROM employees e
     NATURAL JOIN orders o
     NATURAL JOIN order_details od
     GROUP BY e.employee_id,
              e.first_name,
              e.last_name,
              o.order_id
     HAVING SUM(od.unit_price * od.quantity * (1 - od.discount)) =
         (SELECT MAX(SM)
          FROM
              (SELECT SUM(od2.unit_price * od2.quantity * (1 - od2.discount)) AS SM
               FROM order_details od2
               JOIN orders o2 ON od2.order_id = o2.order_id
               JOIN employees e2 ON o2.employee_id = e2.employee_id
               GROUP BY o2.order_id))),
      HighestAverageProfit AS
    (SELECT e.employee_id,
            e.first_name,
            e.last_name,
            AVG(od.unit_price * od.quantity) AS avg_amount,→
     FROM employees e
     NATURAL JOIN orders o
     NATURAL JOIN order_details od
     WHERE e.employee_id in
             (SELECT employee_id
              FROM NonManagers)
     GROUP BY e.employee_id,
              e.first_name,
              e.last_name
     HAVING AVG(od.unit_price * od.quantity) =
         (SELECT MAX(avg_amount)
          FROM
              (SELECT AVG(od2.unit_price * od2.quantity) AS avg_amount
               FROM employees e2
               NATURAL JOIN orders o2
               NATURAL JOIN order_details od2
               WHERE e2.employee_id in
                       (SELECT employee_id
                        FROM NonManagers)
               GROUP BY e2.employee_id))),
SELECT first_name,
       last_name,
       'Shipped the most profitable order ever' AS achievement
FROM MostProfitableOrder
UNION
SELECT first_name,
       last_name,
       'Has the highest average profit per order' AS achievement
FROM HighestAverageProfit