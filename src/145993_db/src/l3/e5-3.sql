-- Northwind Traders would like to investigate why these customers have not placed an order yet.
-- To address this, NT would like potential customers and suppliers to contact each other
--   ▶ List side-by-side any customer
--     that has not placed an order yet with potential suppliers
--     that are located in the same country
--   ▶ Do not use subqueries, aggregation, or null checks.
--     Print only the representatives’ names
 WITH Offending_Customers as
    (SELECT *
     FROM Customers C -- take care of changing the columns
LEFT JOIN Orders O ON O.customer_id = C.customer_id
     EXCEPT SELECT *
     FROM Customers C
     JOIN Orders O ON O.customer_id = C.customer_id)
SELECT S.contact_name,
       OC.contact_name
FROM Offending_Customers OC
JOIN Suppliers S ON OC.country = S.country