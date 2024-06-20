-- Create database
CREATE DATABASE sn22cs032_exp3;

-- Switch to the newly created database
USE sn22cs032_exp3;

-- Create Employee table
CREATE TABLE Employee (
    E_id INT PRIMARY KEY,
    E_name VARCHAR(255),
    Age INT,
    Salary DECIMAL(10, 2)
);

-- Insert records into Employee table
INSERT INTO Employee VALUES (101, 'aaa', 20, 1000);
INSERT INTO Employee VALUES (102, 'bbb', 20, 1000);
INSERT INTO Employee VALUES (103, 'ccc', 30, 1000);
INSERT INTO Employee VALUES (104, 'ddd', 19, 5000);
INSERT INTO Employee VALUES (105, 'eee', 25, 10000);

-- Verify insertion
SELECT * FROM Employee;

-- 1. Count number of employee names from employee table
SELECT COUNT(E_name) AS TotalEmployees FROM Employee;

-- 2. Find the Maximum age from employee table
SELECT MAX(Age) AS MaxAge FROM Employee;

-- 3. Find the Minimum age from employee table
SELECT MIN(Age) AS MinAge FROM Employee;

-- 4. Find salaries of employees in ascending order
SELECT Salary FROM Employee ORDER BY Salary ASC;

-- 5. Find grouped salaries of employees
SELECT Salary, COUNT(E_id) AS NumberOfEmployees FROM Employee GROUP BY Salary;
