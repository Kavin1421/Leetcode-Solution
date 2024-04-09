# Write your MySQL query statement below
WITH
    S AS (
        SELECT 'Low Salary' AS category
        UNION
        SELECT 'Average Salary'
        UNION
        SELECT 'High Salary'
    ),
    T AS (
        SELECT
            CASE
                WHEN income < 20000 THEN "Low Salary"
                WHEN income > 50000 THEN 'High Salary'
                ELSE 'Average Salary'
            END AS category,
            COUNT(1) AS accounts_count
        FROM Accounts
        GROUP BY 1
    )
SELECT category, IFNULL(accounts_count, 0) AS accounts_count
FROM
    S
    LEFT JOIN T USING (category);
