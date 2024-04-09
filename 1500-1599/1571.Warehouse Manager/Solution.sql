# Write your MySQL query statement below
SELECT
    name AS warehouse_name,
    SUM(width * length * height * units) AS volume
FROM
    Warehouse
    JOIN Products USING (product_id)
GROUP BY 1;
