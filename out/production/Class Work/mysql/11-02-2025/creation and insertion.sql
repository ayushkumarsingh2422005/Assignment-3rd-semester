CREATE DATABASE bank;
USE bank;

CREATE TABLE branch(
    branch_name VARCHAR(25) PRIMARY KEY,
    branch_city VARCHAR(25) NOT NULL,
    assets BIGINT CHECK(assets > 0)
);
DROP Table branch;

CREATE TABLE customer(
    ID INT PRIMARY KEY AUTO_INCREMENT,
    customer_name VARCHAR(50) NOT NULL,
    customer_street VARCHAR(100),
    customer_city VARCHAR(50) NOT NULL
) AUTO_INCREMENT = 100001;
DROP TABLE customer;

CREATE TABLE loan(
    loan_number INT PRIMARY KEY AUTO_INCREMENT,
    branch_name VARCHAR(25) NOT NULL,
    amount NUMERIC(12, 2) CHECK(amount > 0),
    Foreign Key (branch_name) REFERENCES branch(branch_name) ON DELETE CASCADE
) AUTO_INCREMENT = 100001;
DROP TABLE loan;

CREATE TABLE borrower(
    ID INT PRIMARY KEY AUTO_INCREMENT,
    branch_name VARCHAR(25) NOT NULL,
    amount NUMERIC(12, 2) CHECK(amount > 0),
    Foreign Key (branch_name) REFERENCES branch(branch_name) ON DELETE CASCADE,
    Foreign Key (ID) REFERENCES customer(ID) ON DELETE CASCADE
)

DROP Table borrower;

CREATE TABLE account(
    account_number INT PRIMARY KEY AUTO_INCREMENT,
    branch_name VARCHAR(25) NOT NULL,
    balance NUMERIC(16, 4) CHECK(balance > 0),
    Foreign Key (branch_name) REFERENCES branch(branch_name) ON DELETE CASCADE
) AUTO_INCREMENT = 100001;
DROP TABLE `account`;

CREATE TABLE depositor(
    ID INT,
    account_number INT,
    PRIMARY KEY (ID, account_number),
    Foreign Key (ID) REFERENCES customer(ID) ON DELETE CASCADE,
    Foreign Key (account_number) REFERENCES account(account_number) ON DELETE CASCADE
);
DROP TABLE depositor;
SHOW TABLES;