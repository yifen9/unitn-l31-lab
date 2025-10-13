-- List all the orders that have overshot the delivery deadline
-- (Shipped_Date > Required_Date),
-- and list the Customer_ID, Order_ID,
-- and by how many days the order was late

SELECT
    customer_id,
    order_id,
    (shipped_date - required_date) AS overshot
FROM orders
WHERE
    shipped_date > required_date