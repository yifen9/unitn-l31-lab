-- Using the newly created view,
-- list all the company names
-- that have spent more than the average in their respective countries.
-- Return the same columns as in the view,
-- but sort them by the amount of money spent

SELECT
    *
FROM
    CountriesWithCustomers c1
WHERE
    total > (
        SELECT
            AVG(total)
        FROM
            CountriesWithCustomers c2
        WHERE
            c2.country = c1.country
    )
ORDER BY
    total