-- Provide an ordered list (by the amount of money spent)
-- of the countries where the company has customers,
-- the number of orders in each country,
-- and the total amount of money spent in each one

SELECT country,
       sum(quantity) AS tot_orders,
       sum(quantity * unit_price * (1 - discount)) AS tot_money_spent
FROM (customers
      JOIN orders ON customers.customer_id = orders.customer_id)
JOIN order_details ON orders.order_id = order_details.order_id
GROUP BY country
ORDER BY tot_money_spent DESC