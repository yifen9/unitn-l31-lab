-- Expand the previous query and investigate what are the most offending shipment companies:
-- list the CompanyName and the number of orders they have shipped late, plus the average delay in days.
-- Sort the results by the number of late orders in descending order

SELECT
    company_name,
    count(orders.order_id) AS delayed_orders,
    avg(shipped_date - required_date) AS avg_delay_days
FROM orders, shippers
WHERE
    shipped_date > required_date
    AND orders.ship_via = shippers.shipper_id
GROUP BY
    company_name
ORDER BY delayed_orders DESC