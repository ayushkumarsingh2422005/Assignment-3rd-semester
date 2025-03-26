USE sales;
-- a
-- SELECT so.orderno, so.order_date, sod.productno, sod.qty_ordered FROM sales_order so LEFT JOIN sales_order_details sod ON so.orderno = sod.orderno;
select orders.*, pm.description, pm.sell_prize from (
    SELECT so.orderno, so.order_date, sod.productno, sod.qty_ordered FROM sales_order so LEFT JOIN sales_order_details sod ON so.orderno = sod.orderno
) orders LEFT JOIN product_master pm ON orders.productno = pm.productno;

-- b
SELECT orderno, order_date, monthname(order_date) FROM sales_order;

-- c
SELECT orderno, DATE_FORMAT(order_date, '%d-%M-%y') as formatted_date 
FROM sales_order;

-- d
-- List the date, 15 days after today's date. 
-- SELECT DATE_ADD(CURDATE(), INTERVAL 15 DAY) as date_after_15_days;
SELECT orderno, order_date, DATE_ADD(order_date, INTERVAL 15 DAY) as date_after_15_days
FROM sales_order;



SELECT * FROM client_master;
SELECT * FROM product_master;
SELECT * FROM selesman_master;
SELECT * FROM sales_order;
SELECT * FROM sales_order_details;