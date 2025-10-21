-- The Megadirector has an attention span of a goldfish and finds your report too verbose.
-- Use the view we created to create a query that
-- ▶ has countries ordered by the amount of money spent
-- ▶ lists only the countries and their revenues
-- ▶ prints only countries between the 5th and 10th in the list

select
    country,
    sum(total) as revenue
from
    CountriesWithCustomers
group by
    country
order by
    revenue desc
limit
    6
offset
    4