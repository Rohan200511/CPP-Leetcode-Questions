# Write your MySQL query statement below
WITH t AS(
    SELECT person_name , weight , SUM(weight) OVER (ORDER BY turn) AS running_weight
    FROM Queue
)

SELECT person_name 
FROM t
WHERE running_weight <= 1000
ORDER BY running_weight DESC
LIMIT 1;