-- With this information, the company can now decide which countries to target.
-- Using this helper expression to filter only developing countries:
--
-- `WHERE Country IN ('Venezuela', 'Mexico', 'Brazil', 'Argentina')`
--
-- list the countries and the average amount of money spent IN each country.
 WITH oap AS
    (WITH orders_and_price AS
         (SELECT orders.order_id,
                 SUM(unit_price * quantity - discount) AS tot_price,
                 customer_id
          FROM orders
          JOIN order_details USING (order_id)
          GROUP BY order_id) SELECT country,
                                    SUM(tot_price) AS tot_revenue,
                                    COUNT(order_id) AS n_orders --, tot_revenue / n_orders AS avg_spending

     FROM orders_and_price
     JOIN customers USING (customer_id)
     WHERE country IN ('Venezuela',
                       'Mexico',
                       'Brazil',
                       'Argentina')
     GROUP BY country
     ORDER BY SUM(tot_price) DESC)
SELECT country,
       tot_revenue / n_orders AS avg_spending
FROM oap