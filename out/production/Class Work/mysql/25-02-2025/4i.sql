USE sales;

-- a

SELECT pr.orderno, sod.productno FROM (SELECT so.*, cm.name FROM sales_order so LEFT JOIN client_master cm ON cm.clientno = so.clientno WHERE name = "John Smith") pr LEFT JOIN sales_order_details sod ON sod.orderno = pr.orderno;
-- SELECT so.*, cm.name FROM sales_order so LEFT JOIN client_master cm ON cm.clientno = so.clientno WHERE name = "John Smith"

-- b




SELECT * FROM client_master;
SELECT * FROM product_master;
SELECT * FROM selesman_master;
SELECT * FROM sales_order;
SELECT * FROM sales_order_details;