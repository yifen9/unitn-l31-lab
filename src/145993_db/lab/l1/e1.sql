-- Assume a generic database has the following relation (uppercase N means NULL):
--
--   A B C D
--   -------
--   a N 1 2
--   N b 2 3
--   b b 0 3
--   a a 4 2

-- 1 Can C be a primary key for this relation?
--   ▶ Yes, C can be a primary key for this relation. No two tuples have the same value for C

-- 2 Can (A, B) be a candidate key for this relation?
--   ▶ Yes. Although both A and B have NULL values, the combination of both is unique.
--     Candidate keys may have NULL values

-- 3 Can (A, D) be a candidate key for this relation?
--   ▶ No. The tuple (a, 2) appears twice in the relation, so (A, D) is not a candidate key