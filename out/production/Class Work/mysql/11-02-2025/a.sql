use bank;
SELECT ID FROM customer WHERE ID NOT IN (SELECT ID FROM borrower) AND ID IN(SELECT ID FROM depositor);
SELECT * FROM borrower;
SELECT * FROM customer;
SELECT * from depositor;
SELECT * FROM account;
SELECT * FROM loan;
SELECT * FROM branch;

SELECT * FROM customer WHERE customer_street = (SELECT customer_street FROM customer WHERE ID=100001) AND customer_city = (SELECT customer_city FROM customer WHERE ID=100001);

