-- The previous report was liked by the Megadirector,
-- but he would prefer to see those countries (between the 5th and 10th)
-- listed in alphabetical order:
-- ▶ modify the query to sort them appropriately,
-- ▶ but add an additional column that shows the rank of each country,
--    by amount of money spent, as before

SELECT *
FROM
    (SELECT country,
            SUM(total) as revenue,
            RANK() OVER (
                         ORDER BY SUM(total) DESC) as rank
     FROM countrieswithcustomers
     GROUP BY country)
WHERE rank >= 5 AND rank <= 10
ORDER BY country