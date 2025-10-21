-- List all the customers of Northwind,
-- along with any order that may have done by them.
-- Return the customer ID and company name

SELECT C.customer_id,
       C.company_name
FROM Customers C
LEFT JOIN Orders O ON C.customer_id = O.customer_id