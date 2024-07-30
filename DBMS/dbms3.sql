-- 1. Create a new database
CREATE DATABASE sn22cs032_exp3;

-- 2. Switch to the newly created database
USE sn22cs032_exp3;

-- 3. Create the Employee table
CREATE TABLE Employee (
    E_id INT PRIMARY KEY,
    E_name VARCHAR(255),
    Age INT,
    Salary DECIMAL(10, 2)
);

-- 4. Insert records into the Employee table
INSERT INTO Employee VALUES (101, 'aaa', 20, 1000);
INSERT INTO Employee VALUES (102, 'bbb', 20, 1000);
INSERT INTO Employee VALUES (103, 'ccc', 30, 1000);
INSERT INTO Employee VALUES (104, 'ddd', 19, 5000);
INSERT INTO Employee VALUES (105, 'eee', 25, 10000);

-- 5. Select all records from the Employee table
SELECT * FROM Employee;

-- 6. Count the number of employee names in the Employee table
SELECT COUNT(E_name) AS TotalEmployees FROM Employee;

-- 7. Find the maximum age from the Employee table
SELECT MAX(Age) AS MaxAge FROM Employee;

-- 8. Find the minimum age from the Employee table
SELECT MIN(Age) AS MinAge FROM Employee;

-- 9. Find salaries of employees in ascending order
SELECT E_name, Salary FROM Employee ORDER BY Salary ASC;

-- 10. Find salaries of employees in descending order
SELECT E_name, Salary FROM Employee ORDER BY Salary DESC;

-- 11. Find grouped salaries of employees
SELECT Salary, COUNT(*) AS EmployeeCount
FROM Employee
GROUP BY Salary;
