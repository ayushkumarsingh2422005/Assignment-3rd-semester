USE sales;

-- a
SELECT pm.*, COALESCE(sd.count, 0) as solditem FROM product_master pm LEFT JOIN (SELECT productno, count(productno) as count FROM sales_order_details GROUP BY productno) sd ON pm.productno = sd.productno;

-- b
SELECT pm.* FROM (SELECT DISTINCT(productno) FROM sales_order_details) sd LEFT JOIN product_master pm ON pm.productno = sd.productno;

-- c
SELECT so.clientno, sum(sod.product_rate) as total FROM sales_order so LEFT JOIN sales_order_details sod ON so.orderno = sod.orderno GROUP BY so.clientno HAVING total > 15000;

-- d
SELECT count(*) as count, month(order_date) as month FROM sales_order WHERE month(order_date)=6 GROUP BY month;


SELECT * FROM client_master;
SELECT * FROM product_master;
SELECT * FROM selesman_master;
SELECT * FROM sales_order;
SELECT * FROM sales_order_details;