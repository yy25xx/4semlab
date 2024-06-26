-- Create database
CREATE DATABASE exp4;

-- Switch to the newly created database
USE exp4;

-- Create CUSTOMERS table
CREATE TABLE CUSTOMERS (
    ID INT PRIMARY KEY AUTO_INCREMENT,
    NAME VARCHAR(255),
    AGE INT,
    ADDRESS VARCHAR(255),
    SALARY DECIMAL(10, 2)
);

-- Show tables
SHOW TABLES;

-- Set delimiter for trigger creation
DELIMITER //

-- Create trigger after_insert_salary_difference
CREATE TRIGGER after_insert_salary_difference
AFTER INSERT ON CUSTOMERS
FOR EACH ROW
BEGIN
    SET @my_sal_diff = CONCAT('salary inserted is ', NEW.SALARY);
END;
//

-- Create trigger after_update_salary_difference
CREATE TRIGGER after_update_salary_difference
AFTER UPDATE ON CUSTOMERS
FOR EACH ROW
BEGIN
    DECLARE old_salary DECIMAL(10, 2);
    DECLARE new_salary DECIMAL(10, 2);

    SET old_salary = OLD.SALARY;
    SET new_salary = NEW.SALARY;
    SET @my_sal_diff = CONCAT('salary difference after update is ', NEW.SALARY - OLD.SALARY);
END;
//

-- Create trigger after_delete_salary_difference
CREATE TRIGGER after_delete_salary_difference
AFTER DELETE ON CUSTOMERS
FOR EACH ROW
BEGIN
    SET @my_sal_diff = CONCAT('salary deleted is ', OLD.SALARY);
END;
//

-- Reset delimiter to default
DELIMITER ;

-- Insert a record into CUSTOMERS
INSERT INTO CUSTOMERS (NAME, AGE, ADDRESS, SALARY)
VALUES ('Shankara', 35, '123 Main St', 50000.00);

-- Select all records from CUSTOMERS
SELECT * FROM CUSTOMERS;

-- Retrieve the salary difference after insertion
SELECT @my_sal_diff AS SAL_DIFF;

-- Update the salary of the record in CUSTOMERS
UPDATE CUSTOMERS SET SALARY = 55000.00 WHERE ID = 1;

-- Select all records from CUSTOMERS after update
SELECT * FROM CUSTOMERS;

-- Retrieve the salary difference after update
SELECT @my_sal_diff AS SAL_DIFF;

-- Delete the record from CUSTOMERS
DELETE FROM CUSTOMERS WHERE ID = 1;

-- Select all records from CUSTOMERS after deletion
SELECT * FROM CUSTOMERS;

-- Retrieve the salary difference after deletion
SELECT @my_sal_diff AS SAL_DIFF;
