-- Repeat the previous query, but this time:
--   ▶ Filter out all the discontinued products,
--   ▶ Sort the results by the UnitPrice in descending order,
--   ▶ Print highly requested products, i.e., those with more units on order than in stock

SELECT product_name,unit_price
FROM products
WHERE discontinued = 0 AND units_on_order > units_in_stock
ORDER BY unit_price DESC;