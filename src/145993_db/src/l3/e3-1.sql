-- Provide an ordered list (by the amount of money spent)
-- of the countries where the company has customers,
-- the number of orders in each country,
-- and the total amount of money spent in each one

SELECT C.country,
       SUM(OD.quantity * OD.unit_price * (1 - OD.discount)) as Total,
       COUNT(DISTINCT O.order_id) as Count
FROM Orders O
JOIN Order_Details OD ON OD.order_id = O.order_id
JOIN Customers C ON O.Customer_ID = C.Customer_ID
GROUP BY C.country
ORDER BY Total DESC