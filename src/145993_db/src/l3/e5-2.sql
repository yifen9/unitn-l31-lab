-- Now list any customer that has not placed an order yet,
-- without using subqueries, aggregation, or null checks.
-- Return both the customer ID and the company name

SELECT C.customer_id,
       C.company_name
FROM Customers C
LEFT JOIN Orders O ON C.customer_id = O.customer_id
EXCEPT
SELECT C.customer_id,
       C.company_name
FROM Customers C
JOIN Orders O ON C.customer_id = O.customer_id