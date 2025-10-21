-- Now, either use the view we created or create a new one
-- that includes the region for each country. Using this view,
-- ▶ list the countries alphabetically (all of them now, no LIMIT),
-- ▶ include the region, if any, for each country,
-- ▶ modify the ranking to be within each country’s regions instead of globally Ignore companies:
-- only consider the countries, their regions, and the total amount spent

SELECT customers.country,
       customers.region,
       customers.company_name,
       sum(order_details.quantity::double precision * order_details.unit_price * (1::double precision - order_details.discount)) AS total,
       count(DISTINCT orders.order_id) AS count
FROM orders
JOIN order_details USING (order_id)
JOIN customers USING (customer_id)
GROUP BY customers.country,
         customers.region,
         customers.company_name
ORDER BY (sum(order_details.quantity::double precision * order_details.unit_price * (1::double precision - order_details.discount))) DESC;