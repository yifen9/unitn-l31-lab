-- With this information, the company can now decide which countries to target.
-- Using this helper expression to filter only developing countries:
--
-- `WHERE Country IN ('Venezuela', 'Mexico', 'Brazil', 'Argentina')`
--
-- list the countries and the average amount of money spent IN each country.
 WITH Report as
     (SELECT C.country,
             SUM(OD.quantity * OD.unit_price * (1 - OD.discount)) as Total,
             COUNT(DISTINCT O.order_id) as Count
      FROM Orders O
      JOIN Order_Details OD ON OD.order_id = O.order_id
      JOIN Customers C ON O.Customer_ID = C.Customer_ID
      GROUP BY C.country
      ORDER BY Total DESC)
SELECT Country,
       (Total/Count) as Average
FROM Report
WHERE Country in ('Venezuela',
                  'Mexico',
                  'Brazil',
                  'Argentina')
ORDER BY Average DESC