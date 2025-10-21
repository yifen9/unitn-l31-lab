-- List all the employees that
--   ▶ are not managers,^1
--   ▶ show their Name, Surname, and Name and Surname of their manager (if they have one),
--   ▶ and sort them by their manager’s surname
-- ^1 Do not make any assumption on the title column

SELECT E1.First_Name,
       E1.Last_Name,
       E2.First_Name as Manager_First_Name,
       E2.Last_Name as Manager_Last_Name
FROM Employees E1
JOIN Employees E2 ON E1.reports_to = E2.employee_id
WHERE E1.employee_id NOT IN
        (SELECT DISTINCT reports_to
         FROM Employees E0
         WHERE reports_to is not NULL )
ORDER BY Manager_Last_Name