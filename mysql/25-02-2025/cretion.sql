CREATE DATABASE sales;
SHOW DATABASES;
USE sales;
CREATE TABLE client_master (
    clientno varchar(6) PRIMARY KEY CHECK(clientno LIKE 'C%'),
    name varchar(20) NOT NULL,
    address1 varchar(30),
    address2 varchar(30),
    city varchar(15),
    pincode int,
    state varchar(15),
    bal_due float
);
DELETE FROM client_master;
SELECT * FROM client_master;

INSERT INTO client_master VALUES
('C00001', 'John Smith', '123 Main St', 'Apt 4B', 'New York', 10001, 'New York', 1500.50),
('C00002', 'Mary Johnson', '456 Oak Ave', NULL, 'Los Angeles', 90001, 'California', 2750.25),
('C00003', 'Robert Brown', '789 Pine Rd', 'Suite 12', 'Chicago', 60601, 'Illinois', 500.75),
('C00004', 'Patricia Davis', '321 Elm St', NULL, 'Houston', 77001, 'Texas', 3200.00),
('C00005', 'Michael Wilson', '654 Maple Dr', 'Unit 8', 'Phoenix', 85001, 'Arizona', 1800.50),
('C00006', 'Linda Anderson', '987 Cedar Ln', NULL, 'Philadelphia', 19101, 'Pennsylvania', 950.25),
('C00007', 'James Taylor', '147 Birch Rd', 'Floor 3', 'San Antonio', 78201, 'Texas', 2100.75),
('C00008', 'Barbara Thomas', '258 Spruce Ave', NULL, 'San Diego', 92101, 'California', 1650.00),
('C00009', 'William Moore', '369 Ash St', 'Suite 15', 'Dallas', 75201, 'Texas', 3500.50),
('C00010', 'Elizabeth White', '741 Walnut Dr', NULL, 'San Jose', 95101, 'California', 800.25),
('C00011', 'David Miller', '852 Cherry Ln', 'Apt 7C', 'Austin', 73301, 'Texas', 2900.75),
('C00012', 'Jennifer Hall', '963 Poplar Rd', NULL, 'Jacksonville', 32201, 'Florida', 1200.00),
('C00013', 'Richard Lee', '159 Willow Ave', 'Unit 11', 'San Francisco', 94101, 'California', 4100.50),
('C00014', 'Susan Martin', '357 Cypress St', NULL, 'Columbus', 43201, 'Ohio', 1750.25),
('C00015', 'Joseph Thompson', '486 Magnolia Dr', 'Suite 9', 'Fort Worth', 76101, 'Texas', 2600.75);

CREATE TABLE product_master(
    productno varchar(6) PRIMARY KEY CHECK(productno LIKE 'P%'),
    description varchar(15) NOT NULL,
    profit_percent decimal(4, 2) NOT NULL,
    unit_measure varchar(10) NOT NULL,
    qty_on_hand int NOT NULL,
    recorder_lvl int NOT NULL,
    sell_prize decimal(8, 2) NOT NULL CHECK(sell_prize > 0),
    cost_prize decimal(8, 2) NOT NULL CHECK(cost_prize > 0)
);

DELETE FROM product_master;
SELECT * FROM product_master;

INSERT INTO product_master VALUES
('P00001', 'Laptop', 25.50, 'piece', 50, 10, 1200.00, 900.00),
('P03453', 'Smartphone', 30.00, 'piece', 100, 20, 800.00, 550.00),
('P07886', 'Headphones', 40.00, 'piece', 150, 30, 100.00, 60.00),
('P00004', 'Monitor', 20.00, 'piece', 30, 5, 300.00, 240.00),
('P07868', 'Keyboard', 35.00, 'piece', 80, 15, 80.00, 52.00),
('P00006', 'Mouse', 45.00, 'piece', 120, 25, 40.00, 22.00),
('P07885', 'Printer', 28.00, 'piece', 25, 5, 250.00, 180.00),
('P00008', 'USB Drive', 50.00, 'piece', 200, 40, 30.00, 15.00),
('P00345', 'Webcam', 32.00, 'piece', 60, 12, 90.00, 61.20),
('P00010', 'Speaker', 38.00, 'piece', 70, 15, 150.00, 93.00),
('P00011', 'Hard Drive', 22.00, 'piece', 45, 10, 120.00, 93.60),
('P07965', 'Graphics Card', 18.00, 'piece', 20, 5, 600.00, 492.00),
('P07976', 'RAM', 42.00, 'piece', 90, 20, 80.00, 46.40),
('P06734', 'Power Bank', 33.00, 'piece', 110, 25, 60.00, 40.20),
('P07975', 'Router', 27.00, 'piece', 40, 8, 120.00, 87.60);

CREATE TABLE selesman_master(
    selesmanno varchar(6) PRIMARY KEY CHECK(selesmanno LIKE 'S%'),
    selesman_name varchar(20) NOT NULL,
    address1 varchar(30) NOT NULL,
    address2 varchar(30),
    city varchar(20),
    pincode int,
    state varchar(20),
    sal_amt decimal(8,2) NOT NULL CHECK(sal_amt > 0),
    tot_to_get decimal(6,2) NOT NULL CHECK(tot_to_get > 0),
    ytd_sales decimal(6,2) NOT NULL,
    remarks varchar(60)
);

INSERT INTO selesman_master VALUES
('S00001', 'James Wilson', '123 Sales Ave', 'Floor 2', 'New York', 10001, 'New York', 45000.00, 5000.00, 3500.00, 'Top performer'),
('S00002', 'Sarah Johnson', '456 Market St', NULL, 'Los Angeles', 90001, 'California', 38000.00, 4200.00, 2800.00, 'Good communication'),
('S00003', 'Michael Brown', '789 Commerce Rd', 'Suite 5', 'Chicago', 60601, 'Illinois', 42000.00, 4800.00, 3200.00, 'Experienced'),
('S00004', 'Emily Davis', '321 Trade Blvd', NULL, 'Houston', 77001, 'Texas', 36000.00, 3800.00, 2500.00, 'New hire'),
('S00005', 'Robert Miller', '654 Business Ln', 'Unit 3', 'Phoenix', 85001, 'Arizona', 40000.00, 4500.00, 3000.00, 'Consistent performer');


CREATE TABLE sales_order(
    orderno varchar(6) PRIMARY KEY CHECK(orderno LIKE 'O%'),
    clientno varchar(6),
    order_date Date NOT NULL,
    delay_addr varchar(25),
    salesmanno varchar(6),
    dely_type char DEFAULT 'F' CHECK(dely_type in ('F', 'P')),
    bill_yn char CHECK(bill_yn in ('Y', 'N')),
    dely_date Date,
    order_status varchar(10) CHECK(order_status in ('In Process', 'Fulfilled', 'BackOrder', 'Cancelled')),
    FOREIGN KEY (clientno) REFERENCES client_master(clientno) ON DELETE SET NULL,
    FOREIGN KEY (salesmanno) REFERENCES selesman_master(selesmanno) ON DELETE SET NULL,
    CONSTRAINT check_delivery_date CHECK (dely_date >= order_date)
);

INSERT INTO sales_order VALUES
('O19001', 'C00001', '2004-06-12', NULL, 'S00001', 'F', 'N', '2004-07-20', 'In Process'),
('O19002', 'C00002', '2004-06-25', NULL, 'S00002', 'P', 'N', '2004-06-27', 'Cancelled'),
('O46865', 'C00003', '2004-02-18', NULL, 'S00003', 'F', 'Y', '2004-02-20', 'Fulfilled'),
('O19003', 'C00001', '2004-04-03', NULL, 'S00001', 'F', 'Y', '2004-04-07', 'Fulfilled'),
('O46866', 'C00004', '2004-05-20', NULL, 'S00002', 'P', 'N', '2004-05-22', 'Cancelled'),
('O19008', 'C00005', '2004-05-24', NULL, 'S00004', 'F', 'N', '2004-07-26', 'In Process');

CREATE TABLE sales_order_details(
    orderno varchar(6),
    productno varchar(6),
    qty_ordered int,
    qty_disp int,
    product_rate decimal(10,2),
    FOREIGN KEY (orderno) REFERENCES sales_order(orderno) ON DELETE CASCADE,
    FOREIGN KEY (productno) REFERENCES product_master(productno) ON DELETE CASCADE
);

INSERT INTO sales_order_details VALUES
('O19001', 'P00001', 4, 4, 525.00),
('O19001', 'P07965', 2, 1, 8400.00),
('O19001', 'P07885', 2, 2, 5250.00),
('O19002', 'P00001', 10, 0, 525.00),
('O46865', 'P07868', 3, 3, 3150.00),
('O46865', 'P07885', 3, 1, 5250.00),
('O46865', 'P00001', 10, 10, 525.00),
('O46865', 'P03453', 4, 4, 1050.00),
('O19003', 'P03453', 2, 2, 1050.00),
('O19003', 'P06734', 1, 1, 12000.00),
('O46866', 'P07965', 1, 0, 8400.00),
('O46866', 'P07975', 1, 0, 1050.00),
('O19008', 'P00001', 10, 5, 525.00),
('O19008', 'P07975', 5, 3, 1050.00);


