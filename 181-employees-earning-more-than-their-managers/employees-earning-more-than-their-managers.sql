# Write your MySQL query statement below
/*SELECT e.name AS Employee
FROM Employee e
JOIN Employee m
ON e.managerId = m.id
WHERE e.salary > m.salary;*/

SELECT e.name AS Employee
FROM Employee e
WHERE e.salary > (
    SELECT salary
    FROM Employee m
    WHERE e.managerId = m.id
)