USE sales;

-- SELECT * FROM information_schema.check_constraints; WHERE CONSTRAINT_SCHEMA = "sales_order";
-- Question i)
-- a
SELECT * from client_master WHERE name LIKE("_a%");

-- b
SELECT * from client_master WHERE city LIKE("H%");

-- c
SELECT * from client_master WHERE city IN ("New York", "Los Angeles");

-- d
SELECT * from client_master WHERE bal_due > 1200;

-- e
SELECT * FROM sales_order WHERE MONTH(order_date) = 6;
-- SELECT * FROM sales_order WHERE order_date LIKE ("_____06%"); 

-- f
SELECT * FROM sales_order s LEFT JOIN sales_order_details sd ON s.orderno = sd.orderno WHERE clientno IN ("C00001", "C00002");

-- g
SELECT * FROM product_master WHERE sell_prize BETWEEN 100 AND 300;

-- h
SELECT sell_prize*0.15 as new_sell_prize, sell_prize FROM product_master WHERE sell_prize > 500;

-- i
SELECT name, city, state FROM client_master WHERE state != "California";

-- j
SELECT count(*) FROM sales_order;

-- k
SELECT avg(cost_prize), avg(sell_prize) FROM product_master;

-- l
SELECT max(cost_prize) as max_price, min(cost_prize) as min_price FROM product_master;

-- m
SELECT count(*) FROM product_master WHERE cost_prize <= 500;

-- n
