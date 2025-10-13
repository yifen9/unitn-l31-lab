-- With this information, the company can now decide which countries to target.
-- Using this helper expression to filter only developing countries:
--
-- `WHERE Country in ('Venezuela', 'Mexico', 'Brazil', 'Argentina')`
--
-- list the countries and the average amount of money spent in each country.

SELECT
    country,
    sum(quantity) AS tot_orders,
    sum(
        quantity * unit_price * (1 - discount)
    ) AS tot_money_spent
FROM (
        customers
        JOIN orders ON customers.customer_id = orders.customer_id
    )
    JOIN order_details ON orders.order_id = order_details.order_id
GROUP BY
    country
ORDER BY tot_money_spent DESC