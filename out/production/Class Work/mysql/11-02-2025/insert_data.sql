USE bank;

-- Insert branch data
INSERT INTO branch (branch_name, branch_city, assets) VALUES
('Downtown', 'New York', 9000000),
('Brighton', 'Brooklyn', 7500000),
('Queens', 'New York', 8000000),
('Redwood', 'Palo Alto', 12000000),
('Central', 'Chicago', 10000000);

-- Insert customer data
INSERT INTO customer (customer_name, customer_street, customer_city) VALUES
('John Smith', '321 Maple St', 'New York'),
('Emma Johnson', '123 Oak Ave', 'Brooklyn'),
('Michael Brown', '456 Pine Rd', 'Chicago'),
('Sarah Wilson', '789 Elm Blvd', 'Palo Alto'),
('David Miller', '159 Cedar Ln', 'New York');

-- Insert loan data
INSERT INTO loan (branch_name, amount) VALUES
('Downtown', 150000.00),
('Brighton', 75000.00),
('Queens', 100000.00),
('Redwood', 200000.00),
('Central', 125000.00);

-- Insert account data
INSERT INTO account (branch_name, balance) VALUES
('Downtown', 25000.5000),
('Brighton', 15000.7500),
('Queens', 18500.2500),
('Redwood', 40000.0000),
('Central', 32000.7500);

-- Insert borrower data
INSERT INTO borrower (ID, branch_name, amount) VALUES
(100001, 'Downtown', 150000.00),
(100002, 'Brighton', 75000.00),
(100003, 'Central', 125000.00),
(100004, 'Redwood', 200000.00),
(100005, 'Queens', 100000.00);

-- Insert depositor data
INSERT INTO depositor (ID, account_number) VALUES
(100001, 100001),
(100002, 100002),
(100003, 100003),
(100004, 100004),
(100005, 100005);

-- Verify data
SELECT 'Branches' as Table_Name, COUNT(*) as Count FROM branch
UNION ALL
SELECT 'Customers', COUNT(*) FROM customer
UNION ALL
SELECT 'Loans', COUNT(*) FROM loan
UNION ALL
SELECT 'Accounts', COUNT(*) FROM account
UNION ALL
SELECT 'Borrowers', COUNT(*) FROM borrower
UNION ALL
SELECT 'Depositors', COUNT(*) FROM depositor;

SELECT * FROM branch;