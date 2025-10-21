-- Recycle Exercise 3.3.3’s Report CTE to create a view that lists the countries
-- in which Northwind has customers.
-- Call the view `CountriesWithCustomers`

create view CountriesWithCustomers as
    (SELECT C.company_name,
            C.country,
            SUM(OD.product_id * OD.unit_price) as Total,
            COUNT(O.order_id) as count_orders
     FROM Orders O
     JOIN Order_Details OD ON OD.order_id = O.order_id
     JOIN Customers C ON O.Customer_ID = C.Customer_ID
     GROUP BY C.country,
              C.company_name
     ORDER BY Total DESC)